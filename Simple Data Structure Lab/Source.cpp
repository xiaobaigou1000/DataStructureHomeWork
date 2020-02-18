#include<unordered_map>
#include<iostream>
int main()
{
    using std::unordered_map;
    using std::cout;
    using std::string;

    unordered_map<string, double> test;
    test["hello"] = 2.33;
    test["world"] = 24.4;
    

    cout << test["hello"] << ' ' << test["world"] << '\n';
}