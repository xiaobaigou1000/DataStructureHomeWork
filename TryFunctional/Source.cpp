#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

double average_score(const std::vector<int>& scores)
{
    return std::accumulate(scores.begin(), scores.end(), 0, std::plus<int>()) / static_cast<double>(scores.size());
}

int main()
{
    std::vector<int> scores{ 5,5,4,7,8,22,14 };
    double result = average_score(scores);

    std::cout << result << '\n';
}
