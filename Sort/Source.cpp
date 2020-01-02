#include<iostream>
#include"foolsort.h"

int main()
{
    using namespace FoolSort;
    std::cout << "\n\nshell sort\n\n";
    sortFunctionTestAndEfficiencyComparison(std::cout, 10000000,shellSort);
    std::cout << "\n\ninsertion sort\n\n";
    sortFunctionTestAndEfficiencyComparison(std::cout, 50000,insertSort);
    std::cout << "\n\nbinary insertion sort\n\n";
    sortFunctionTestAndEfficiencyComparison(std::cout, 50000,binaryInsertionSort);
    std::cout << "\n\nbubble sort\n\n";
    sortFunctionTestAndEfficiencyComparison(std::cout, 50000, bubbleSort);
    std::cout << "\n\nmerge sort\n\n";
    sortFunctionTestAndEfficiencyComparison(std::cout, 10000000,mergeSort);
    std::cout << "\n\nquick sort\n\n";
    sortFunctionTestAndEfficiencyComparison(std::cout, 100000000, quickSort);
    //std::vector<int> test;
    //test.push_back(2);
    //test.push_back(1);
    //test.push_back(3);
    //auto ite = test.rbegin();

    std::vector<int> test;
    std::default_random_engine dre(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> uid(0, 100);
    for (size_t i = 1; i < 5; i++)
    {
        test.push_back(10 * i);
    }
    for (size_t i = 1; i < 5; i++)
    {
        test.push_back(10 * i + 5);
    }

    std::vector<int> tempArray;
    tempArray.resize(test.size());

    auto ret = bubbleSort(test);
    mergeSub(std::begin(test), std::begin(test) + (std::end(test) - std::begin(test)) / 2, std::end(test), std::begin(tempArray));
    

    //test.push_back(20);
    //test.push_back(10);
    //test.push_back(30);

    //auto ret = binaryInsertionSort(test);
    return 0;
}