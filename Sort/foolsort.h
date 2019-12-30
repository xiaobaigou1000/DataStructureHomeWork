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

        for (auto i = std::rbegin(toSort) + 2; i != std::rend(toSort); ++i)
        {
            *backSentry = *i;
            for (auto j = i; *j > *(j - 1); --j)
            {
                std::iter_swap(j, j-1);
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
        typename std::vector<Data>::reverse_iterator reverseLow, reverseHigh, reverseMiddle;
        for (auto i = std::rbegin(toSort) + 2; i != std::rend(toSort); ++i)
        {
            *backSentry = *i;
            reverseLow = std::rbegin(toSort) + 1;
            reverseHigh = i - 1;
            while (reverseLow <= reverseHigh)
            {
                reverseMiddle = (reverseLow + (reverseHigh-reverseLow) / 2);
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
            if ((i+1) % 10 == 0)
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
        auto referenceSorted = getReferenceSortedArray(toSort);
        auto timeElapsed = hrc.now() - beforSort;
        out << "first 100 element of reference sorted array:\n\n";
        out << referenceSorted;
        out << "\n\n";
        out << "time used in reference sort: " << timeElapsed.count() << " ns.\n\n";

        beforSort = hrc.now();
        auto sorted = sortFunction(toSort);
        timeElapsed = hrc.now() - beforSort;
        out << "first 100 element of sorted array by sort function:\n\n";
        out << sorted << "\n\n";
        out << "time used in reference sort:" << timeElapsed.count() << " ns.\n\n";
    }
}