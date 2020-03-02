#include<iostream>
#include<chrono>
#include<thread>
#include<mutex>

int main()
{
    using namespace std;
    using namespace std::chrono;
    using namespace std::chrono_literals;
    mutex loc1;
    mutex loc2;
    std::thread testA([&] {
        while (true)
        {
            {
                this_thread::sleep_for(500ms);
                lock_guard<mutex> lg1(loc1);
                cout << "lock 1\n";
                this_thread::sleep_for(500ms);
                lock_guard<mutex> lg2(loc2);
                cout << "lock 2\n";
            }
            cout << "unlock\n";
        }
        });
    std::thread testB([&] {
        while (true)
        {
            {
                this_thread::sleep_for(3s);
                lock_guard<mutex> lg1(loc2);
                cout << "lock 2\n";
                this_thread::sleep_for(3s);
                lock_guard<mutex> lg2(loc1);
                cout << "lock 1\n";
            }
            cout << "unlock\n";
        }
        });
    testA.join();
    testB.join();
    return 0;
}