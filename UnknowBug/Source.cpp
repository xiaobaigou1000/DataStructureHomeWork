#include<iostream>
#include<memory>
using namespace std;

struct UPTest
{
    int a;
    int b;

    UPTest():a(),b() { cout << "UPTest object constructed. [default constructor]\n"; }
    UPTest(const UPTest& from) { a = from.a; b = from.b; cout << "UPTest copy constructor called.\n"; }
    UPTest(UPTest&& from)noexcept { a = from.a; b = from.b; cout << "UPTest move constructor called.\n"; }
    UPTest& operator=(const UPTest& from) { a = from.a; b = from.b; cout << "copy assignment called.\n"; return *this; }
    UPTest& operator=(UPTest&& from)noexcept { a = move(from.a); b = move(from.b); cout << "move assignment called.\n"; return *this; }
    ~UPTest() { cout << "UPTest object deleted.\n"; }
};

int main()
{
    UPTest hello;
    UPTest world(hello);
    UPTest third(std::move(hello));
    UPTest forth = world;
    UPTest fifth;
    fifth = world;
    world = move(fifth);

    return 0;
}