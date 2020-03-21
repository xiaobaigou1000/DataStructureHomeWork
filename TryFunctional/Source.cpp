#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<fstream>
#include<ios>

int foldFunc(int previousCount, char c)
{
    return c != '\n' ? previousCount : previousCount + 1;
}

int count_lines(const std::vector<char>& s)
{
    return std::accumulate(s.begin(), s.end(), 1, foldFunc);
}

int main()
{
    std::ifstream in("Source.cpp", std::ios::ate);
    std::streamoff end = in.tellg();
    in.seekg(std::ios::beg);
    std::vector<char> fileString(static_cast<size_t>(end - in.tellg()));
    std::copy(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>(), fileString.begin());
    int result = count_lines(fileString);

    std::cout << result<<'\n';
}