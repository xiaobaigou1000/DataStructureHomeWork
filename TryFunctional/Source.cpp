#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

std::ifstream open_file(std::string fileName)
{
    return std::ifstream{ fileName };
}

size_t count_lines(std::ifstream& in)
{
    std::streamoff counts = std::count(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>(), '\n');
    return static_cast<size_t>(counts);
}

int main()
{
    std::vector<std::string> files{ "../Graph/foolalgraph.h","../Graph/foolamgraph.h","../Graph/Source.cpp" };

    std::vector<size_t> results;
    std::vector<std::ifstream> fileStreams;
    results.resize(files.size());
    fileStreams.resize(files.size());

    std::transform(files.begin(), files.end(), fileStreams.begin(), open_file);
    std::transform(fileStreams.begin(), fileStreams.end(), results.begin(), count_lines);

    for (auto i : results)
    {
        std::cout << i<<' ';
    }
}