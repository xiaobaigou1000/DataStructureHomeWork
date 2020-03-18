#include<iostream>
#include<thread>
#include<functional>
#include<mutex>
#include<array>
#include<vector>
#include<chrono>
using namespace std::chrono_literals;

int main()
{
    std::array<std::mutex, 5> locks;

    auto eat = [&locks](uint32_t i)
    {
        std::lock(locks[i], locks[(i + 1) % 5]);
        std::lock_guard<std::mutex> lhsLock(locks[i], std::adopt_lock);
        std::lock_guard<std::mutex> rhsLock(locks[(i + 1) % 5], std::adopt_lock);
        printf("%i eat\n", i);
        std::this_thread::sleep_for(500ms);
    };
    std::vector<std::thread> threads;
    for (uint32_t i = 0; i < 5; i++)
    {
        threads.push_back(std::move(std::thread([&eat, i] {
            std::this_thread::sleep_for(100ms * i);
            while (true)
            {
                eat(i);
            }
            })));
    }
    for (auto& i : threads)
    {
        i.join();
    }
    return 0;
}
