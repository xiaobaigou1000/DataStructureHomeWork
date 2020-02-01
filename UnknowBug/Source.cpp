#include<iostream>
#include<vector>
#include"LibTest.h"
#include"../BST Tree/FoolBST.h"
using std::cout;

//class Father
//{
//public:
//    void test();
//};
//
//class Child : public Father
//{
//public:
//    void test();
//};

//void Father::test()
//{
//    cout << "father test";
//}

//void Child::test()
//{
//    cout << "child test";
//}

int main() {
    FoolBST<int>::Node t;
    cout << sizeof(int) << "\n\n";
    LibTest test;
    test.test();

    std::vector<int> hello;
    hello.push_back(233);
    int* i = &hello.back();
    //cout << *i;
    //*i = 244;
    cout << &hello.back()<<' '<<i<<' '<<(i==&hello.back())<<' '<<&hello[0]<<' '<<hello[0]<<' '<<(&hello[0]==i)<<'\n';
    cout << &hello.back() <<' '<< &hello[0] <<' '<< (&hello.back() == &hello[0]);
    return 0;
}