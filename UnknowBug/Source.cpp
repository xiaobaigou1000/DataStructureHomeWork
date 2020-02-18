#include<iostream>
#include<chrono>
#include<thread>

int main() 
{
    using namespace std::chrono;
    using namespace std::chrono_literals;
    using std::cout;

    auto startTimePoint = steady_clock::now();
    auto lastFrameTimePoint = steady_clock::now();

    auto sleepPeriod = 1.2s;
    
    while (true)
    {
        std::this_thread::sleep_for(sleepPeriod);
        auto currentTime = steady_clock::now();
        float intervalTime = duration_cast<duration<float, std::ratio<1, 1>>>(currentTime - lastFrameTimePoint).count();
        lastFrameTimePoint = currentTime;
        float timeFromProgramBegin = duration_cast<duration<float, std::ratio<1, 1>>>(currentTime - startTimePoint).count();

        cout << "interval from last frame: " << intervalTime << "s, total run time: " << timeFromProgramBegin << '\n';
    }

    return 0;
}
