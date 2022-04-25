#ifndef VERTICAL_H
#define VERTICAL_H

#include <vector>
#include "ufo.h"

class Vertical : public Ufo {
    public:
        // Konstruktor
        Vertical(const std::string pId);
        
        void flyToDest(const float x, const float y, const float height, const int speed) override;
};

#endif