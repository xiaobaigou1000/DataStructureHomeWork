#include<iostream>
#include"foolsort.h"

int main()
{
    using namespace FoolSort;
    sortFunctionTestAndEfficiencyComparison(std::cout, shellSort);
    //sortFunctionTestAndEfficiencyComparison(std::cout, insertSort);
    //sortFunctionTestAndEfficiencyComparison(std::cout, binaryInsertionSort);
    //std::vector<int> test;
    //test.push_back(2);
    //test.push_back(1);
    //test.push_back(3);
    //auto ite = test.rbegin();

    std::vector<int> test;
    std::default_random_engine dre(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> uid(0, 100);
    for (size_t i = 7; i >0; i--)
    {
        test.push_back(10*i);
    }
    auto ret = shellSort(test);
    //test.push_back(20);
    //test.push_back(10);
    //test.push_back(30);

    //auto ret = binaryInsertionSort(test);
    return 0;
}