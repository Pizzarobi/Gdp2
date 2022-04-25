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
    // fly down to 0
    sim.flyTo(x,y,0,speed,0);
}