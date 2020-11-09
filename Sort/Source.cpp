#include<iostream>
#include"foolsort.h"
#include"AlgorithmLab.h"

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
    std::cout << "    9---AVL sort\n";
}

int main()
{
    calculateSortTimeAlgorithm(500, 500, 100, 4, "bubbleSort", FoolSort::inplace_bubbleSort<size_t>);
    calculateSortTimeAlgorithm(500, 500, 100, 4, "insertSort", FoolSort::inplace_insert_sort<size_t>);
    calculateSortTimeAlgorithm(500, 500, 100, 4, "binaryInsersionSort", FoolSort::inplace_binaryInsertionSort<size_t>);
    calculateSortTimeAlgorithm(100000, 100000, 100, 4, "shellSort", FoolSort::inplace_shellSort<size_t>);
    calculateSortTimeAlgorithm(100000, 100000, 100, 4, "heap_sort", FoolSort::inplace_heapSort<size_t>);
    calculateSortTimeAlgorithm(100000, 100000, 100, 4, "quick_sort", FoolSort::inplace_quickSort<size_t>);
    calculateSortTimeAlgorithm(100000, 100000, 100, 4, "merge_sort", FoolSort::inplace_mergeSort<size_t>);

    return 0;
}