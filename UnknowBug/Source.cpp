#include<iostream>
#include<vector>
#include<chrono>
#include<sstream>
#include<future>
#include<cstring>

int main() {
    using std::cin;
    using std::cout;
    using std::vector;
    using std::ostringstream;
    using std::future;
    using std::string;
    std::chrono::high_resolution_clock hrc;
    int low, high = 0;
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cin >> low >> high;
    low = 2;
    high = 400000;

    auto start = hrc.now();
    vector<int> primers;
    primers.reserve(1229);

    auto eularPrime = [&primers](int high)
    {
        bool* visited = new bool[high];
        memset(visited, 1, high);
        for (int j = 2; j <= high; j++) {
            int current = j;
            if (visited[j])
            {
                primers.push_back(current);
                while ((current += j) < high)
                {
                    visited[current] = false;
                }
            }
        }
    };

    auto eratosthenesPrime = [&primers](int high)
    {
        for (int j = 2; j <= high; j++) {
            int current = j;
            int sqrtCurrent = std::sqrt(j);
            for (int i : primers)
            {
                if (current % i == 0)
                {
                    --current;
                    break;
                }
                if (i > sqrtCurrent)
                    break;
            }
            if (current == j)
                primers.push_back(j);
        }
    };

    if (high < 15000)
        eratosthenesPrime(high);
    else
        eularPrime(high);
    auto duration = hrc.now() - start;
    auto spawnPrimeTime = std::chrono::duration_cast<std::chrono::milliseconds>(duration);
    start = hrc.now();
    auto outputfunc = [&primers](int low, int high)
    {
        ostringstream oss;
        for (int i = low; i < high; ++i) {
            int num = i;
            oss << num << '=';
            for (auto j : primers) {
                while (num % j == 0) {
                    oss << j;
                    num /= j;
                    if (num != 1)
                    {
                        oss << '*';
                    }
                    else
                    {
                        break;
                    }
                }
            }
            oss << '\n';
        }
        return oss.str();
    };
    vector<future<string>> group;
    int groupSize = (low - high) / 10000;
    --groupSize;
    ++high;
    for (int i = 0; i < groupSize; ++i)
    {
        group.push_back(std::async(std::launch::async, outputfunc, high - 10000, high));
        high -= 10000;
    }
    auto result = outputfunc(low, high);
    duration = hrc.now() - start;
    auto breakupTime = std::chrono::duration_cast<std::chrono::milliseconds>(duration);
    start = hrc.now();

    cout << result;
    for (auto i = group.rbegin(); i != group.rend(); ++i)
    {
        cout << i->get();
    }
    duration = hrc.now() - start;
    auto outputTime = std::chrono::duration_cast<std::chrono::milliseconds>(duration);

    cout << "\nspawn prime used " << spawnPrimeTime.count() << " ms\n";
    cout << "break up used " << breakupTime.count() << " ms\n";
    cout << "output used " << outputTime.count() << " ms\n";

    return 0;
}
