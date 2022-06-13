#include <chrono>
#include <iostream>
#include <random>
#include <thread>
#include <mutex>

std::mutex mtx;

class Sender
{
private:
    int number;
    int countdown;
    std::mt19937 r;
    std::thread senderThread;

    void run()
    {
        mtx.lock();
            //let sender sleep to make a thread change possible
            std::this_thread::sleep_for(std::chrono::milliseconds(1));

            std::cout << "\nsending message " << number << ": ";
            for (; countdown >= 0; countdown--)
            {
                std::cout << number << " ";
                std::this_thread::sleep_for(std::chrono::milliseconds(r()%200));
            }
        mtx.unlock();
    }

public:
    Sender(const int pNumber, const int pCountdown)
    {
        number = pNumber;
        countdown = pCountdown;
        senderThread = std::thread(Sender::run,this);
    }

    ~Sender()
    {
        senderThread.join();
    }
};

int main()
{
    Sender sender1(1, 20);
    Sender sender2(2, 20);
}
