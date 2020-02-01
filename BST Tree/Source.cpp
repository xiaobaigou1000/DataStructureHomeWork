#include<iostream>
#include"FoolAVL.h"
#include<set>
#include<random>
#include<chrono>
#include<sstream>

int main()
{
    using std::cout;

    FoolAVL<int> helloAVL;
    helloAVL.insert({ 41,20,65,11,29,50,26,23,55 });
    cout << helloAVL << '\n';
    cout << "max element: " << helloAVL.max() << '\n';
    cout << "min element: " << helloAVL.min() << '\n';

    std::default_random_engine dre(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> uid(1, 10000000000);
    for (size_t i = 0; i < 500000; i++)
    {
        helloAVL.insert(uid(dre));
    }

    //helloAVL.root=helloAVL.leftRotate(helloAVL.root);
    std::ostringstream oss;
    oss << helloAVL << '\n';
    cout << oss.str();
    cout << "max element: " << helloAVL.max() << '\n';
    cout << "min element: " << helloAVL.min() << '\n';

    return 0;
}