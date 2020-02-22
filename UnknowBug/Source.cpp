#include<algorithm>
#include<iostream>
#include<vector>
#include<random>
#include<chrono>

int main()
{
    using namespace std;
    default_random_engine dre(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> hello(0, 1000);
    int toSort[100];

    for (size_t i = 0; i < 100; i++)
    {
        toSort[i] = hello(dre);
    }

    int l = 3, r = 10, k = 2;
    cout << "please input l(left boundry), r(right boundry), k\n";
    cin >> l >> r >> k;

    --l;
    --k;
    sort(begin(toSort) + l, begin(toSort) + r, [](int a, int b) {return a > b; });
    auto beg = begin(toSort);
    int result = *(begin(toSort) + l + k);
    cout << "result is :" << result << '\n';
    for (auto i = begin(toSort); i != begin(toSort) + l; ++i)
    {
        cout << *i << ' ';
    }
    cout << " [ ";
    for (auto i = begin(toSort) + l; i != begin(toSort) + l + k; ++i)
    {
        cout << *i << ' ';
    }
    cout << '(' << *(begin(toSort) + l + k) << ") ";
    for (auto i = begin(toSort) + l + k + 1; i != begin(toSort) + r; ++i)
    {
        cout << *i << ' ';
    }
    cout << " ] ";
    for (auto i = begin(toSort) + r; i != begin(toSort) + r + 5; ++i)
    {
        cout << *i << ' ';
    }
    cout << endl;
    return 0;
}