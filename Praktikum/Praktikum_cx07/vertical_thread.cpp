#include <thread>
#include <iostream>
#include "vertical_thread.h"

void VerticalThread::runner(const float x, const float y, const float height){
    Vertical vert("yo");
    vert.flyToDest(x,y,height,SPEED);
    completed = true;
    return;
}

void VerticalThread::startUfo(const float x, const float y, const float height){
    completed = false;
    flyThread = std::thread(&VerticalThread::runner,this,x,y,height);
    flyThread.detach();
}

VerticalThread::~VerticalThread(){
    if(flyThread.joinable()){
        flyThread.join();
    }  
}