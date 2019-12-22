#include<iostream>
#include<vector>
#include<random>
#include<chrono>
#include<cmath>

#include"foolamgraph.h"
#include"foolalgraph.h"

int main()
{
    //FoolAMGraph<char, int, 100>* hello = new FoolAMGraph<char, int, 100>;
    //CreateAMGraph(*hello);
    //hello->clearVisited();
    //hello->DFSM(0);
    //hello->DFSMTraverse();

    FoolALGraph<char, 100> test;
    CreateALGraph(test);
    return 0;
}

