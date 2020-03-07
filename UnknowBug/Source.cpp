#include<iostream>
#include<chrono>
#include<thread>
#include<mutex>
#include<vector>
#include<random>

struct MutexedData
{
    std::mutex mut;
    uint32_t data;
};

int main()
{
    using namespace std;
    using namespace std::chrono;
    using namespace std::chrono_literals;

    default_random_engine dre(system_clock::now().time_since_epoch().count());
    uniform_int_distribution<uint32_t> uid(0, 100);
    std::vector<MutexedData> datalist(20);
    for (uint32_t i = 0; i < 20; ++i)
    {
        datalist[i].data = i;
    }

    thread a([&datalist] {
        auto ptr = datalist.begin();
        auto end = --datalist.end();
        while (ptr != end)
        {
            lock_guard<mutex> la(ptr->mut);
            lock_guard<mutex> lb((ptr + 1)->mut);
            printf("thread a is now visiting %d\n", ptr->data);
            ++ptr;
        }
        });

    thread b([&datalist] {
        auto ptr = datalist.rbegin();
        auto end = --datalist.rend();
        while (ptr != end)
        {
            lock_guard<mutex> la(ptr->mut);
            lock_guard<mutex> lb((ptr + 1)->mut);
            printf("thread b is now visiting %d\n", ptr->data);
            ++ptr;
        }
        });

    a.join();
    b.join();

    return 0;
}