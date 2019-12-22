#pragma once
#include<array>
#include<algorithm>
#include<iostream>

template<class Data, class ArcType, int maxVertexNum>
class FoolAMGraph
{
public:
    //too big for member variables, warped in an struct
    struct _Data
    {
        std::array<Data, maxVertexNum> vertices;
        std::array<std::array<ArcType, maxVertexNum>, maxVertexNum> arcs;
        std::array<int, maxVertexNum> visited;
        int vertexNumber, arcNumber;
    };
    _Data* __insideData = new _Data;
    std::array<Data, maxVertexNum>& vertices = __insideData->vertices;
    std::array<std::array<ArcType, maxVertexNum>, maxVertexNum>& arcs = __insideData->arcs;
    int& vertexNumber = __insideData->vertexNumber;
    int& arcNumber = __insideData->arcNumber;
    std::array<int, maxVertexNum>& visited = __insideData->visited;

    FoolAMGraph()
    {
        vertexNumber = 0;
        arcNumber = 0;

        std::fill(std::begin(vertices), std::end(vertices), Data());
        std::array<ArcType, maxVertexNum> temp;
        std::fill(std::begin(temp), std::end(temp), ArcType());
        std::fill(std::begin(arcs), std::end(arcs), temp);
        clearVisited();
    }

    inline void clearVisited()
    {
        std::fill(std::begin(visited), std::end(visited), 0);
    }

    void DFSM(int vertexIndex)
    {
        visited[vertexIndex] = 1;
        std::cout << "Now visit" << vertexIndex << "---" << vertices[vertexIndex] << '\n';
        for (int i = 0; i < vertexNumber; i++)
        {
            if (arcs[vertexIndex][i] != 0 && !visited[i])
            {
                DFSM(i);
            }
        }
    }

    void DFSMTraverse()
    {
        clearVisited();
        for (int i = 0; i < vertexNumber; i++)
        {
            if (!visited[vertexNumber])
            {
                std::cout << "traverse the map with DFSM from vertex: " << vertices[i] << '\n';
                DFSM(i);
            }
        }
    }

    ~FoolAMGraph()
    {
        delete __insideData;
    }
};

void CreateAMGraph(FoolAMGraph<char, int, 100>& toInit)
{
    std::cout << "input 0 for directed graph,1 for undirected graph\n";
    int flag = 0;
    std::cin >> flag;
    std::cout << "please input vertex number and arc number\n";
    std::cin >> toInit.vertexNumber >> toInit.arcNumber;
    std::cout << "please input vertex information\n";
    for (int i = 0; i < toInit.vertexNumber; i++)
    {
        std::cin >> toInit.vertices[i];
    }
    for (int j = 0; j < toInit.vertexNumber; j++)
    {
        std::cout << "No. " << j << "\t" << toInit.vertices[j] << '\n';
    }
    std::cout << "please input vertex for every arc\n"
        "please notice that vertex index begin from 0\n";
    for (int i = 0; i < toInit.arcNumber; i++)
    {
        
        std::cout << "please input " << i << " arc.\n";
        int xaxis, yaxis;
        std::cin >> xaxis >> yaxis;
        if (xaxis<0 || xaxis>toInit.vertexNumber || yaxis<0 || yaxis>toInit.vertexNumber)
        {
            std::cout << "Wrong input.\n";
            i--;
            continue;
        }
        std::cout << toInit.vertices[xaxis] << "---" << toInit.vertices[yaxis] << '\n';
        toInit.arcs[xaxis][yaxis] = 1;
        if (flag == 1)
            toInit.arcs[yaxis][xaxis] = 1;
    }
}