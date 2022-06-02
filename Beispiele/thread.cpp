#include <thread>
#include <iostream>

bool stopRequested = false;

void run() {
    std::cout << "Thread startet!\n";

    while(!stopRequested) {
        std::cout << ". ";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
void runPar(int countdown) {
    std::cout << "Thread startet!\n";

    for(; countdown >= 0; countdown--) {
        std::cout << ". ";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Thread terminated!\n";
}


int main(){
    std::thread myThread;
    myThread = std::thread(runPar,30);
    std::cout << "Waiting for Thread to end\n";
    
    //std::this_thread::sleep_for(std::chrono::milliseconds(100));
    
    // std::string s;
    // std::cin >> s;
    //stopRequested = true;

    myThread.join();
}