#include <string>

class Bruch {
private:
    int zaehler;
    int nenner;

    void kuerze();
    static int ggt(int a, int b);

public:
    void normalisiere();
    Bruch(const int pz, const int pn);
    std::string toString() const{ return std::to_string(zaehler) + "/" + std::to_string(nenner); }
    void add(const Bruch bruch);
    void sub(const Bruch bruch);
    void mult(const Bruch bruch);
    void div(const Bruch bruch);
};