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

bool is_not_space(char c)
{
    return c != ' ';
}

std::string trim_left(std::string s)
{
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), is_not_space));
    return s;
}

std::string trim_right(std::string s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(), is_not_space).base(), s.end());
    return s;
}

int main()
{
    std::string hello = "   hello world      ";
    std::cout << '\"' << trim_right(trim_left(hello)) << '\"';
}