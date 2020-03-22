#pragma once
#include<fstream>
#include<vector>
#include<algorithm>

namespace count_file_lines
{
    std::ifstream open_file(const std::string& fileName)
    {
        return std::ifstream{ fileName };
    }

    size_t count_lines(std::ifstream& in)
    {
        std::streamoff counts = std::count(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>(), '\n');
        return static_cast<size_t>(counts);
    }

    std::vector<size_t> count_file_lines(const std::vector<std::string> fileNames)
    {
        std::vector<size_t> results;
        std::vector<std::ifstream> fileStreams;
        results.resize(fileNames.size());
        fileStreams.resize(fileNames.size());

        std::transform(fileNames.begin(), fileNames.end(), fileStreams.begin(), open_file);
        std::transform(fileStreams.begin(), fileStreams.end(), results.begin(), count_lines);
        return results;
    }
}
