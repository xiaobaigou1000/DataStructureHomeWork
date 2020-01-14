#include<iostream>
#include<vector>
#include<chrono>

int main() {
    using std::cin;
    using std::cout;
    using std::vector;
    std::chrono::high_resolution_clock hrc;
    int low, high = 0;
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> low >> high;

    auto start = hrc.now();
    vector<int> primers;
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
    for (int i = low; i <= high; ++i) {
        cout << i << "=";
        int num = i;
        for (const auto& j : primers) {
            while (num % j == 0) {
                cout << j;
                num /= j;
                if (num != 1) {
                    cout << "*";
                }
                else
                {
                    cout << "\n";
                    break;
                }
            }

        }
    }
    auto duration = hrc.now() - start;
    auto pastTime = std::chrono::duration_cast<std::chrono::milliseconds>(duration);
    cout << "\nusing " << pastTime.count() << " ms\n";

    return 0;
}
