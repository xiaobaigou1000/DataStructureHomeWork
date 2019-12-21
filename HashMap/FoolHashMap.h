#pragma once
#include<iostream>
#include<array>
#include<random>
#include<chrono>
#include<iomanip>

template<class Data>
class FoolHashMap
{
public:
    struct Node
    {
        std::pair<int, int> key;
        Data data;
        Node* next;

        Node(std::pair<int, int> key, Data data, Node* next)
            :key(key), data(data), next(next)
        {

        }

        Node()
        {
            data = Data();
            next = nullptr;
        }
    };

    Node* findHash(std::pair<int, int> key)
    {
        int hashValue = (std::get<0>(key) + std::get<1>(key)) % 100;
        Node* ptr = hashMap[hashValue];
        while (ptr)
        {
            if (ptr->key == key)
            {
                break;
            }
            ptr = ptr->next;
        }

        return ptr;
    }

    void InsertHash(std::pair<int, int> key, Data data)
    {
        int hashValue = (std::get<0>(key) + std::get<1>(key)) % 100;
        Node* toAdd = new Node(key, data, hashMap[hashValue]);
        hashMap[hashValue] = toAdd;
    }

    void CreateHash()
    {
        std::fill(std::begin(hashMap), std::end(hashMap), nullptr);
        std::default_random_engine dre(std::chrono::system_clock::now().time_since_epoch().count());
        std::uniform_int_distribution<int> uid(1, 1000);
        std::normal_distribution<double> nd(5.0f, 1.0f);
        for (int i = 0; i < 1000; ++i)
        {
            std::pair<int, int> key(uid(dre), uid(dre));
            if (findHash(key))
                --i;
            else
            {
                Data value = nd(dre);
                std::cout << std::setw(5) << std::get<0>(key) << std::setw(5) << std::get<1>(key) << std::setw(10) << value << '\n';
                InsertHash(key, value);
            }
        }
    }

private:
    std::array<Node*, 100> hashMap;
};

int beFoolToTestTheMap()
{
    FoolHashMap<double> fhm;
    fhm.CreateHash();
    int row, col;

    while (true)
    {
        std::cout << "\nPlease input row and col:\n";
        std::cin >> row >> col;
        FoolHashMap<double>::Node* ptr;
        ptr = fhm.findHash(std::make_pair(row, col));
        if (ptr)
        {
            std::cout << ptr->data;
        }
        else
        {
            std::cout << "find failed\n";
        }
    }
    return 0;
}