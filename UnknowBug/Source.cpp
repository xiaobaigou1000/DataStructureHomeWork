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
    cin >> low >> high;

    auto start = hrc.now();
    vector<int> primers;
    bool* visited = new bool[high];
    memset(visited, 1, high);
    primers.reserve(1229);
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
    auto outputfunc = [&primers](int low, int high)
    {
        ostringstream oss;
        for (int i = low; i <= high; ++i) {
            int num = i;
            oss << num << '=';
            for (const auto& j : primers) {
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
    //vector<future<string>> group;
    //int groupSize = (low - high) / 10000;
    //--groupSize;
    //for (int i = 0; i < groupSize; ++i)
    //{
    //    group.push_back(std::async(std::launch::async, outputfunc, high - 10000, high));
    //    high -= 10001;
    //}
    cout << outputfunc(low, high);
    //for (auto i = group.rbegin(); i != group.rend(); ++i)
    //{
    //    cout << i->get();
    //}
    auto duration = hrc.now() - start;
    auto pastTime = std::chrono::duration_cast<std::chrono::milliseconds>(duration);
    cout << "\nusing " << pastTime.count() << " ms\n";

    return 0;
}
