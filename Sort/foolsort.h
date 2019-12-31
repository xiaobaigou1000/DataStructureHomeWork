#pragma once
#include<deque>
#include<vector>
#include<algorithm>
#include<ostream>
#include<chrono>
#include<random>
#include<iomanip>
#include<iterator>
#include<functional>
#include<numeric>
#include<thread>
#include<future>
namespace FoolSort
{
    template<class DataTraits>
    inline void swapElement(DataTraits a, DataTraits b)
    {
        typename std::iterator_traits<DataTraits>::value_type tmp = *a;
        *a = *b;
        *b = tmp;
    }

    template<class Data>
    std::vector<Data> insertSort(std::vector<Data> toSort)
    {
        toSort.push_back(Data());
        auto backSentry = std::rbegin(toSort);
        auto reverseBegin = std::rbegin(toSort);
        auto reverseEnd = std::rend(toSort);

        for (auto i = reverseBegin + 2; i != reverseEnd; ++i)
        {
            *backSentry = *i;
            for (auto j = i; *j > * (j - 1); --j)
            {
                std::iter_swap(j, j - 1);
            }
        }
        toSort.pop_back();
        return std::move(toSort);
    }

    template<class Data>
    std::vector<Data> binaryInsertionSort(std::vector<Data> toSort)
    {
        toSort.push_back(Data());
        auto backSentry = std::rbegin(toSort);
        auto reverseBegin = std::rbegin(toSort);
        auto reverseEnd = std::rend(toSort);
        typename std::vector<Data>::reverse_iterator reverseLow, reverseHigh, reverseMiddle;
        for (auto i = reverseBegin + 2; i != reverseEnd; ++i)
        {
            *backSentry = *i;
            reverseLow = reverseBegin + 1;
            reverseHigh = i - 1;
            while (reverseLow <= reverseHigh)
            {
                reverseMiddle = (reverseLow + (reverseHigh - reverseLow) / 2);
                if (*backSentry < *reverseMiddle)
                    reverseLow = reverseMiddle + 1;
                else
                    reverseHigh = reverseMiddle - 1;
            }
            for (auto j = i - 1; j > reverseHigh; --j)
            {
                *(j + 1) = *j;
            }
            *(reverseHigh + 1) = *backSentry;
        }
        toSort.pop_back();
        return std::move(toSort);
    }

    template<class Data>
    std::vector<Data> shellSort(std::vector<Data> toSort)
    {
        auto begin = std::begin(toSort);
        auto end = std::end(toSort);
        int dk = 1;
        while (dk < (end - begin) / 3)
            dk = 3 * dk + 1;
        while (dk > 0)
        {
            for (auto i = begin + dk; i != end; ++i)
            {
                for (auto j = i; (j - begin) >= dk && *j < *(j - dk); j -= dk)
                {
                    std::iter_swap(j, j - dk);
                }
            }
            dk /= 3;
        }
        return std::move(toSort);
    }

    template<class Data>
    std::vector<Data> bubbleSort(std::vector<Data> toSort)
    {
        auto begin = std::begin(toSort);
        auto end = std::end(toSort);
    }

    template<class Data>
    std::vector<Data> spawnOriginData()
    {
        std::default_random_engine dre(std::chrono::system_clock::now().time_since_epoch().count());
        std::uniform_int_distribution<Data> uid(0, 100000);
        std::vector<Data> ret;
        for (size_t i = 0; i < 5000; i++)
        {
            ret.push_back(uid(dre));
        }
        return std::move(ret);
    }

    template<class Data>
    std::ostream& operator<<(std::ostream& out, std::vector<Data> toPrint)
    {
        for (int i = 0; i < 100; ++i)
        {
            out << std::setw(8) << toPrint[i];
            if ((i + 1) % 10 == 0)
            {
                out << '\n';
            }
        }
        return out;
    }

    template<class Data>
    std::vector<Data> getReferenceSortedArray(std::vector<Data> input)
    {
        std::sort(std::begin(input), std::end(input));
        return std::move(input);
    }

    void sortFunctionTestAndEfficiencyComparison(std::ostream& out, std::vector<int>(*sortFunction)(std::vector<int>))
    {
        

        auto toSort = spawnOriginData<int>();
        out << "first 100 element of origin random vector:\n\n";
        out << toSort;
        out << "\n\n";

        std::chrono::high_resolution_clock hrc;
        auto beforSort = hrc.now();

        std::vector<std::future<std::chrono::steady_clock::duration>> referenceTests;
        std::vector<std::chrono::steady_clock::duration> referenceTime;
        std::vector<int> referenceSorted;

        auto referenceAlgorithmTimer = [&hrc,&toSort]() {
            auto beforSort = hrc.now();
            getReferenceSortedArray(toSort);
            return hrc.now() - beforSort;
        };

        for (size_t i = 0; i < 5; i++)
        {
            referenceTests.push_back(std::async(referenceAlgorithmTimer));
        }
        referenceSorted = getReferenceSortedArray(toSort);
        for (auto& i : referenceTests)
        {
            referenceTime.push_back(i.get());
        }
        auto averageReferenceTime = std::accumulate(std::begin(referenceTime), std::end(referenceTime), std::chrono::steady_clock::duration());
        averageReferenceTime /= referenceTime.size();
        out << "first 100 element of reference sorted array:\n\n";
        out << referenceSorted;
        out << "\n\n";
        out << "average time used in reference sort: " << averageReferenceTime.count() << " ns.\n\n";

        std::vector<std::future<std::chrono::steady_clock::duration>> actualTests;
        std::vector<std::chrono::steady_clock::duration> actualAlgorithmTime;
        std::vector<int> sorted;
        auto actualAlgorithmTimer = [&hrc, &toSort, sortFunction]() {
            auto beforSort = hrc.now();
            sortFunction(toSort);
            return hrc.now() - beforSort;
        };
        for (size_t i = 0; i < 5; i++)
        {
            actualTests.push_back(std::async(actualAlgorithmTimer));
        }
        sorted = sortFunction(toSort);
        for (auto& i : actualTests)
        {
            actualAlgorithmTime.push_back(i.get());
        }
        auto averageAlgorithmTime = std::accumulate(std::begin(actualAlgorithmTime), std::end(actualAlgorithmTime), std::chrono::steady_clock::duration());
        averageAlgorithmTime /= actualAlgorithmTime.size();
        out << "first 100 element of sorted array by sort function:\n\n";
        out << sorted << "\n\n";
        out << "average time used in user defined sort function:" << averageAlgorithmTime.count() << " ns.\n\n";
    }
}