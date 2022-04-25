#ifndef UFO_H
#define UFO_H

#include <vector>
#include "ufosim.h"
using namespace std;

class Ufo {
    private:
        string id;
    protected:
        Ufosim sim;

    public:
        // Konstruktor
        Ufo(const string pId);        
        // getter
        const std::string getId();
        const std::vector<float> getPosition();
        float getFtime();
        virtual void flyToDest(const float x, const float y, const float height, const int speed);
        static float angle(const float x1, const float y1, const float x2, const float y2);

};

#endif