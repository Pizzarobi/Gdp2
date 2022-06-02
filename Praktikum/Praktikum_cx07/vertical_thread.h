#ifndef VERTICAL_THREAD_H
#define VERTICAL_THREAD_H

#include <thread>
#include "vertical.h"

class VerticalThread {
    private:
        const static int SPEED = 10;
        std::thread flyThread;
        bool completed = false;
        void runner(const float x, const float y, const float height);
    public:
        void startUfo(const float x, const float y, const float height);
        ~VerticalThread();
        bool getCompleted() {return completed;}
};

#endif
//g++ -std=c++20 -I"C:\Program Files\boost_1_78_0" ballistic.cpp vertical.cpp ufo.cpp route.cpp vertical_thread.cpp ufosim.cpp pa5_utest.cpp -o pa5.exe