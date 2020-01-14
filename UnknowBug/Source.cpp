#include<iostream>
#include<vector>
#include<chrono>
#include<sstream>

int main() {
    using std::cin;
    using std::cout;
    using std::vector;
    using std::ostringstream;
    std::chrono::high_resolution_clock hrc;
    int low, high = 0;
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> low >> high;

    auto start = hrc.now();
    vector<int> primers;
    vector<vector<int>> result;
    primers.reserve(1229);
    for (int j = 2; j <= high; j++) {
        int current = j;
        for (int i : primers)
        {
            while (current % i == 0)
            {
                current /= i;
                if (current <= i)
                    break;
            }
        }
        if (current == j)
            primers.push_back(j);
    }

    int maxRowLength = 0;
    for (int i = low; i <= high; ++i) {
        int num = i;
        result.push_back(vector<int>{});
        auto back = result.rbegin();
        back->push_back(num);
        for (const auto& j : primers) {
            while (num % j == 0) {
                back->push_back(j);
                num /= j;
                if (num == 1)
                {
                    break;
                }
            }
        }
    }

    ostringstream oss;
    for (const auto& i : result)
    {
        auto begin = i.begin();
        auto end = i.end();
        oss << *begin++ << '=';
        oss << *begin++;
        for (auto j = begin; j < end; ++j)
        {
            oss << '*' << *j;
        }
        oss << '\n';
    }
    cout << oss.str();

    auto duration = hrc.now() - start;
    auto pastTime = std::chrono::duration_cast<std::chrono::milliseconds>(duration);
    cout << "\nusing " << pastTime.count() << " ms\n";

    return 0;
}
