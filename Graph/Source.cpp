#include<iostream>
#include<vector>
#include<random>
#include<chrono>
#include<cmath>

#include"foolamgraph.h"
#include"foolalgraph.h"

void menu()
{
    std::cout << "\n\n";
    std::cout << "graph traverse example program\n\n";
    std::cout << "    1---create an AMGraph\n";
    std::cout << "    2---create an ALGraph\n";
    std::cout << "    3---deep-first search(AMGraph)\n";
    std::cout << "    4---breadth first search(AMGraph)\n";
    std::cout << "    5---deep-first search(ALGraph)\n";
    std::cout << "    6---breadth first search(ALGraph)\n";
}

int main()
{
    FoolAMGraph<char, int, 100> AMGraph;
    FoolALGraph<char, 100> ALGraph;
    int choice = -1;
    int searchBeginPosition = 0;
    menu();
    while (std::cin >> choice)
    {
        switch (choice)
        {
        case 1:
            CreateAMGraph(AMGraph);
            std::cout << "create AMGraph success.\n";
            break;
        case 2:
            CreateALGraph(ALGraph);
            std::cout << "create ALGraph success.\n";
            break;
        case 3:
            std::cout << "please input search begin position: ";
            std::cin >> searchBeginPosition;
            AMGraph.DFSM(searchBeginPosition);
            break;
        case 4:
            AMGraph.DFSMTraverse();
            break;
        case 5:
            std::cout << "please input search begin position: ";
            std::cin >> searchBeginPosition;
            ALGraph.BFSL(searchBeginPosition);
            break;
        case 6:
            ALGraph.BFSLTraverse();
            break;
        default:
            break;
        }
    }
    return 0;
}

