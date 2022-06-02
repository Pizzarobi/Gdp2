#include <iostream>
#include "vertical_thread.h"
int main()
{
    VerticalThread vthread;
    std::cout
        << "When the flight is completed, type exit to exit the program\n"
        << "or something else to start another flight.\n\n";
    std::string s;
    while (s != "exit")
    {
        float x;
        float y;
        float height;
        std::cout << "Input x, y, height: ";
        std::cin >> x >> y >> height;
        vthread.startUfo(x, y, height);
        std::cin >> s;
    }
    return 0;
}