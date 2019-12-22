#pragma once
#include<iostream>
#include<algorithm>
#include<array>
#include<deque>

template<class Data, int maxVertexNum>
class FoolALGraph
{
public:
    struct ArcNode
    {
        int adjVertexIndex;
        ArcNode* next;

        ArcNode()
            :adjVertexIndex(0), next(nullptr)
        {

        }

        ArcNode(int adjVertexIndex, ArcNode* next)
            :adjVertexIndex(adjVertexIndex), next(next)
        {

        }
    };

    struct VNode
    {
        Data data;
        ArcNode* firstArc;

        VNode()
            :data(), firstArc(nullptr)
        {

        }

        VNode(const Data& data, ArcNode* firstArc)
            :data(data), firstArc(firstArc)
        {

        }
    };

    FoolALGraph()
        :vertexNumber(0), arcNumber(0)
    {
        std::fill(std::begin(vertices), std::end(vertices), VNode());
        clearVisited();
    }

    inline void clearVisited()
    {
        std::fill(std::begin(visited), std::end(visited), int());
    }

    void BFSL(int v)
    {
        std::deque<int> vertexVisited;
        visited[v] = 1;
        std::cout << "Now visiting No." << v << "---" << vertices[v].data << '\n';
        vertexVisited.push_back(v);
        while (!vertexVisited.empty())
        {
            int i = vertexVisited.front();
            vertexVisited.pop_front();
            ArcNode* currentArc = vertices[i].firstArc;
            while (currentArc)
            {
                if (visited[currentArc->adjVertexIndex] == 0)
                {
                    visited[currentArc->adjVertexIndex] = 1;
                    std::cout << "traverse the graph from vertex: No." << currentArc->adjVertexIndex << "---" 
                        << vertices[currentArc->adjVertexIndex].data << '\n';
                    vertexVisited.push_back(currentArc->adjVertexIndex);
                }
                currentArc = currentArc->next;
            }
        }
    }

    void BFSLTraverse()
    {
        clearVisited();
        for (int i = 0; i < vertexNumber; i++)
        {
            if (!visited[i])
            {
                std::cout << "traverse graph with BFSL from vertex: " << vertices[i].data << '\n';
                BFSL(i);
            }
        }
    }

    int vertexNumber, arcNumber;
    std::array<VNode, maxVertexNum> vertices;
    std::array<int, maxVertexNum> visited;
};

void CreateALGraph(FoolALGraph<char, 100>& toInit)
{
    int flag = 0;
    std::cout << "input 0 for directed graph, 1 for undirected graph.\n";
    std::cin >> flag;
    std::cout << "please input quantity of vertex and arcs: ";
    std::cin >> toInit.vertexNumber >> toInit.arcNumber;
    std::cout << "please input vertex info.\n";
    for (int i = 0; i < toInit.vertexNumber; i++)
    {
        std::cin >> toInit.vertices[i].data;
    }
    for (int i = 0; i < toInit.vertexNumber; i++)
    {
        std::cout << "No. " << i << "\t" << toInit.vertices[i].data << '\n';
    }
    std::cout << "please input vertex for every arc\n"
        "please notice that vertex index begin from 0\n";
    for (int i = 0; i < toInit.arcNumber; i++)
    {
        int xaxis, yaxis;
        std::cin >> xaxis >> yaxis;
        if (xaxis < 0 || xaxis >= toInit.vertexNumber || yaxis < 0 || yaxis >= toInit.vertexNumber)
        {
            std::cout << "Wrong input.\n";
            i--;
            continue;
        }
        std::cout << toInit.vertices[xaxis].data << "---" << toInit.vertices[yaxis].data << '\n';
        auto newArc = new FoolALGraph<char, 100>::ArcNode(yaxis, toInit.vertices[xaxis].firstArc);
        toInit.vertices[xaxis].firstArc = newArc;
        if (flag == 1)
        {
            auto oppositeArc = new FoolALGraph<char, 100>::ArcNode(xaxis, toInit.vertices[yaxis].firstArc);
            toInit.vertices[yaxis].firstArc = oppositeArc;
        }
    }
}