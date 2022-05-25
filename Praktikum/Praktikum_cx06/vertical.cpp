#include "vertical.h"
#include <math.h>

Vertical::Vertical(const std::string pId): Ufo(pId){
    Ufosim::setSpeedup(4);
}

void Vertical::flyToDest(const float x, const float y, const float height, const int speed){
    // rise to flight height
    sim.flyTo(sim.getX(), sim.getY(), height, speed, 0);
    // go to end position at same flight height
    sim.flyTo(x,y,height,speed,0);
    // fly down to 0.0
    sim.flyTo(x,y,0.0,speed,0);
}

// return the total distance that the Ufo is flying.
float Vertical::distance(const float x1, const float y1, const float x2, const float y2, const float h){
    float distance = h*2;
    // calculate vector from x1 to x2
    float vx = x2-x1;
    float vy = y2-y1;

    // calculate length of vector x/y
    distance += sqrt(vx*vx + vy*vy);

    return distance;
}
