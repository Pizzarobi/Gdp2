#include "vertical.h"
#include <math.h>

# define MY_PI 3.14159265358979323846

std::string Vertical::type = "vertical";

Vertical::Vertical(const std::string pId){
    id = pId;
    Ufosim::setSpeedup(4);
}

// getter
std::string Vertical::getType(){
    return type;
}
const std::string Vertical::getId(){
    return id;
}
const std::vector<float> Vertical::getPosition(){
    std::vector<float> pos = {sim.getX(),sim.getY(),sim.getZ()};
    return pos;
}
float Vertical::getFtime(){
    return sim.getFtime();
}

void Vertical::flyToDest(const float x, const float y, const float height, const int speed){
    // rise to flight height
    sim.flyTo(sim.getX(), sim.getY(), height, speed, 0);
    // go to end position at same flight height
    sim.flyTo(x,y,height,speed,0);
    // fly down to 0
    sim.flyTo(x,y,0,speed,0);
}

float Vertical::angle(const float x1, const float y1, const float x2, const float y2){
    float vx2 = x2-x1;
    float vy2 = y2-y1;

    float angle = std::atan2(vx2,vy2); // gekürzt, da der standardvektor [0,1] ist
    angle = ((angle*(180/std::numbers::pi))+360);

    return fmod(angle,360);
}