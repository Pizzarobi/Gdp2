#ifndef BRUCH_H
#define BRUCH_H

#include <string>

class Bruch
{
private:
    int zaehler;
    int nenner;

public:
    Bruch(const int pz, const int pn);
    std::string toString();
    void add(const Bruch bruch);
    void sub(const Bruch bruch);
    void mult(const Bruch bruch);
    void div(const Bruch bruch);
    void kuerze();
    void normalisiere();
    static int ggt(int a, int b);
};

#endif
