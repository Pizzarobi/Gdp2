#include "ufo.h"
#include <math.h>

Ufo::Ufo(const std::string pId){
    id = pId;
    Ufosim::setSpeedup(4);
}

// getter
const std::string Ufo::getId(){
    return id;
}
const std::vector<float> Ufo::getPosition(){
    std::vector<float> pos = {sim.getX(),sim.getY(),sim.getZ()};
    return pos;
}
float Ufo::getFtime(){
    return sim.getFtime();
}

void Ufo::flyToDest(const float x, const float y, const float height, const int speed){
    // rise to flight height
    sim.flyTo(sim.getX(), sim.getY(), height, speed, 0);
    // go to end position at same flight height
    sim.flyTo(x,y,height,speed,0);
    // fly down to 0
    sim.flyTo(x,y,0,speed,0);
}

float Ufo::angle(const float x1, const float y1, const float x2, const float y2){
    float vx2 = x2-x1;
    float vy2 = y2-y1;

    float angle = std::atan2(vx2,vy2); // gekürzt, da der standardvektor [0,1] ist
    angle = ((angle*(180/std::numbers::pi))+360);

    return fmod(angle,360);
}