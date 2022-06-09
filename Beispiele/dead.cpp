#include <chrono>
#include <iostream>
#include <random>
#include <thread>
#include <mutex>

std::mt19937 r;
std::mutex mtxA;
std::mutex mtxB;
bool stopRequested = false;

void run1()
{
    while (!stopRequested)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(r()%2000));

        mtxA.lock();
        std::cout << "thread1 locked A\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(r()%50));

        mtxB.lock();
        std::cout << "thread1 locked B\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(r()%50));

        std::cout << "thread1 unlocked A and B\n\n";
        mtxB.unlock();
        mtxA.unlock();
    }
}

void run2()
{
    while (!stopRequested)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(r()%2000));

        mtxB.lock();
        std::cout << "thread2 locked B\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(r()%50));

        mtxA.lock();
        std::cout << "thread2 locked A\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(r()%50));

        std::cout << "thread2 unlocked A and B\n\n";
        mtxA.unlock();
        mtxB.unlock();
    }
}

int main()
{
    std::thread thread1(run1);
    std::thread thread2(run2);

    std::string s;
    std::cin >> s;
    stopRequested = true;

    thread2.join();
    thread1.join();
}