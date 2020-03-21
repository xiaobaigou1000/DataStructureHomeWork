#include<iostream>
#include"count_file_lines.h"

int main()
{
    std::vector<std::string> files{ "../Graph/foolalgraph.h","../Graph/foolamgraph.h","../Graph/Source.cpp" };
    auto results = count_file_lines::count_file_lines(files);

    for (auto i : results)
    {
        std::cout << i<<' ';
    }
}
