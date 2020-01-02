#include<iostream>
#include"foolsort.h"

void menu()
{
    std::cout << "\n\nuniform int distribution sort example program.\n\n";
    std::cout << "    1---insertion sort\n";
    std::cout << "    2---binary insertion sort\n";
    std::cout << "    3---shell sort\n";
    std::cout << "    4---bubble sort\n";
    std::cout << "    5---quick sort\n";
    std::cout << "    6---simple select sort\n";
    std::cout << "    7---heap sort\n";
    std::cout << "    8---two side merge sort\n";
}

int main()
{
    menu();


    using namespace FoolSort;
    std::cout << "\n\nshell sort\n\n";
    sortFunctionTestAndEfficiencyComparison(std::cout, 10000000,shellSort);
    std::cout << "\n\ninsertion sort\n\n";
    sortFunctionTestAndEfficiencyComparison(std::cout, 50000,insertSort);
    std::cout << "\n\nbinary insertion sort\n\n";
    sortFunctionTestAndEfficiencyComparison(std::cout, 50000,binaryInsertionSort);
    std::cout << "\n\nbubble sort\n\n";
    sortFunctionTestAndEfficiencyComparison(std::cout, 50000, bubbleSort);
    std::cout << "\n\nsimple select sort\n\n";
    sortFunctionTestAndEfficiencyComparison(std::cout, 50000, simpleSelectSort);
    std::cout << "\n\nmerge sort\n\n";
    sortFunctionTestAndEfficiencyComparison(std::cout, 10000000,mergeSort);
    std::cout << "\n\nquick sort\n\n";
    sortFunctionTestAndEfficiencyComparison(std::cout, 100000000, quickSort);
    std::cout << "\n\nheap sort\n\n";
    sortFunctionTestAndEfficiencyComparison(std::cout, 10000000, heapSort);

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

    auto ret = heapSort(test);
    return 0;
}