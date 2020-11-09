#pragma once
#include"foolsort.h"
#include<chrono>
#include<fstream>

template<typename SortFunc>
void calculateSortTimeAlgorithm(size_t datasetSize, size_t step, size_t iterTimes, size_t repeatTimes, const std::string& fileName, SortFunc func) {

    std::vector<std::chrono::high_resolution_clock::duration> avgTimes;
    for (size_t i = 0; i < iterTimes; i++)
    {
        std::vector<size_t> rawArray = FoolSort::spawnOriginData<size_t>(datasetSize);
        std::chrono::high_resolution_clock::duration multipleDuration{};
        for (size_t j = 0; j < repeatTimes + 2; j++)
        {
            auto beginTimePoint = std::chrono::high_resolution_clock::now();
            func(rawArray);
            auto passedTime = std::chrono::high_resolution_clock::now() - beginTimePoint;
            if (j > 1)
            {
                multipleDuration += passedTime;
            }
            std::random_shuffle(rawArray.begin(), rawArray.end());
        }
        std::chrono::high_resolution_clock::duration avgTime = multipleDuration / repeatTimes;
        avgTimes.push_back(avgTime);
        std::cout << "Data size of: " << datasetSize<<" used: " << avgTime.count() << "ns\n";
        datasetSize += step;
    }

    std::ofstream ofile(fileName + ".csv");
    ofile << "size,time\n";
    for (int i = 0; i < avgTimes.size(); i++)
    {
        ofile << i * step << ',' << avgTimes[i].count() << "\n";
    }
}