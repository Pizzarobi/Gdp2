#ifndef VERTICAL_H
#define VERTICAL_H

#include <vector>
#include "ufosim.h"

class Vertical {
    private:
        static std::string type;
        std::string id;
        Ufosim sim;

    public:
        // Konstruktor
        Vertical(const std::string pId);
        // getter
        static std::string getType();
        const std::string getId();
        const std::vector<float> getPosition();
        float getFtime();
        //
        void flyToDest(const float x, const float y, const float height, const int speed);
        
        static float angle(const float x1, const float y1, const float x2, const float y2);
};

#endif