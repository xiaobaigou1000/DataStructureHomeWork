#include<iostream>
#include"foolsort.h"

int main()
{
    using namespace FoolSort;

    std::vector<int> test;
    std::default_random_engine dre(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> uid(0, 100);
    for (size_t i = 0; i < 5; i++)
    {
        test.push_back(uid(dre));
    }

    auto ret = insertSort(test);
    return 0;
}