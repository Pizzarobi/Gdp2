#include <string>

class Bruch {
private:
    int zaehler;
    int nenner;

    void kuerze();
    void normalisiere();
    static int ggt(int a, int b);

public:
    Bruch(const int pz, const int pn);
    std::string toString() const{ return (zaehler + "/" + nenner); }
    void add(const Bruch bruch);
    void sub(const Bruch bruch);
    void mult(const Bruch bruch);
    void div(const Bruch bruch);
};