#include<iostream>
#include<array>
#include<thread>
#include<future>
#include<random>
#include<thread>

struct Matrix512x512
{
    constexpr static uint32_t row = 512;
    constexpr static uint32_t col = 512;

    std::shared_ptr<std::array<std::array<uint32_t, col>, row>> dataPtr;

    Matrix512x512()
    {
        dataPtr.reset(new std::array<std::array<uint32_t, col>, row>());
        std::unique_ptr<std::array<uint32_t, col>> identityElement(new std::array<uint32_t, col>);
        std::fill(identityElement->begin(), identityElement->end(), uint32_t());
        std::fill(dataPtr->begin(), dataPtr->end(), *identityElement);
    }

    Matrix512x512(std::default_random_engine& dre, std::uniform_int_distribution<uint32_t> uid)
    {
        dataPtr.reset(new std::array<std::array<uint32_t, col>, row>());
        for (auto& i : *dataPtr)
        {
            for (auto& j : i)
            {
                j = uid(dre);
            }
        }
    }



    std::array<uint32_t, col>& operator[](uint32_t i) const
    {
        return (*dataPtr)[i];
    }

    Matrix512x512 operator*(const Matrix512x512& rhs)const
    {
        Matrix512x512 result;

        auto caculateElement = [this, &rhs](uint32_t row, uint32_t col)
        {
            uint32_t elementValue{};
            for (uint32_t i = 0; i < this->col; i++)
            {
                elementValue += (*this)[row][i] * rhs[i][col];
            }
            return elementValue;
        };

        auto caculateBlock = [this, &rhs, &caculateElement, &result]
        (uint32_t rowLow, uint32_t colLow, uint32_t rowHigh, uint32_t colHigh)
        {
            for (uint32_t i = rowLow; i < rowHigh; i++)
            {
                for (uint32_t j = colLow; j < colHigh; j++)
                {
                    result[i][j] = caculateElement(i, j);
                }
            }
        };

        std::vector<std::future<void>> futures;
        for (uint32_t i = 0; i < 2; i++)
        {
            for (uint32_t j = 0; j < 2; j++)
            {
                uint32_t rows = this->row;
                uint32_t cols = rhs.col;
                uint32_t halfRows = rows / 2;
                uint32_t halfCols = cols / 2;

                //open thread
                futures.push_back(std::move(std::async([=] {
                    caculateBlock(
                        halfRows * i, halfCols * j,
                        halfRows * (i + 1), halfCols * (j + 1)); })));
            }
        }

        for (auto& i : futures)
        {
            i.get();
        }

        return result;
    }
};

int main()
{
    std::default_random_engine dre(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<uint32_t> uid(0, 10);

    Matrix512x512 mat1(dre,uid);
    Matrix512x512 mat2(dre,uid);

    auto result = mat2 * mat2;
    return 0;
}
