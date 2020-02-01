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
    std::cout << "    9---AVL sort\n";
}

int main()
{
    using namespace FoolSort;
    menu();
    int choice = -1;
    while (std::cin >> choice)
    {
        switch (choice)
        {
        case 1:
            std::cout << "\n\ninsertion sort\n\n";
            sortFunctionTestAndEfficiencyComparison(std::cout, 50000, insertSort);
            break;
        case 2:
            std::cout << "\n\nbinary insertion sort\n\n";
            sortFunctionTestAndEfficiencyComparison(std::cout, 50000, binaryInsertionSort);
            break;
        case 3:
            std::cout << "\n\nshell sort\n\n";
            sortFunctionTestAndEfficiencyComparison(std::cout, 10000000, shellSort);
            break;
        case 4:
            std::cout << "\n\nbubble sort\n\n";
            sortFunctionTestAndEfficiencyComparison(std::cout, 50000, bubbleSort);
            break;
        case 5:
            std::cout << "\n\nquick sort\n\n";
            sortFunctionTestAndEfficiencyComparison(std::cout, 100000000, quickSort);
            break;
        case 6:
            std::cout << "\n\nsimple select sort\n\n";
            sortFunctionTestAndEfficiencyComparison(std::cout, 50000, simpleSelectSort);
            break;
        case 7:
            std::cout << "\n\nheap sort\n\n";
            sortFunctionTestAndEfficiencyComparison(std::cout, 10000000, heapSort);
            break;
        case 8:
            std::cout << "\n\nmerge sort\n\n";
            sortFunctionTestAndEfficiencyComparison(std::cout, 50000000, mergeSort);
            break;
        case 9:
            std::cout << "\n\nAVL sort\n\n";
            sortFunctionTestAndEfficiencyComparison(std::cout, 10000000, AVLSort);
        default:
            break;
        }
    }
    return 0;
}