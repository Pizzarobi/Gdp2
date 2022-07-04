#include <iostream>
#include "bruch.h"

int main()
{
    Bruch b1(1, -2);
    Bruch b2(1, 4);

    b1.add(b2);
    std::cout << b1.toString() << '\n';
}
