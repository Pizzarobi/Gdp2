#include "ballistic.h"
#include <math.h>
#include <numbers>

Ballistic::Ballistic(string pId, float pTakeOffAngle, float pLandingAngle) : Ufo(pId){
    if(pTakeOffAngle > 0 && pTakeOffAngle < 90)
        takeOffAngle = pTakeOffAngle;
    else
        takeOffAngle = 45;
    
    if(pLandingAngle > 0 && pLandingAngle < 90)
        landingAngle = pLandingAngle;
    else
        landingAngle = 45;
}

// getter
float Ballistic::getTakeOffAngle(){
    return takeOffAngle;
}
float Ballistic::getLandingAngle(){
    return landingAngle;
}

void Ballistic::flyToDest(const float x, const float y, const float height, const int speed) {
    //calculate x1 and y1
    const vector<float> w1 = Ballistic::firstWaypoint(x, y, height);
    sim.flyTo(w1[0],w1[1],height,speed,speed);

    // calculate x2 and y2
    const vector<float> w2 = Ballistic::secondWaypoint(x, y, height);
    sim.flyTo(w2[0],w2[1],height,speed,speed);

    // fly to end position
    sim.flyTo(x,y,height,speed,0);
}

vector<float> Ballistic::firstWaypoint(const float x, const float y, const float height) const{
    // get current position
    vector<float> currPos = {sim.getX(),sim.getY()};
    // calculate vector to end position
    float vx = x - currPos[0];
    float vy = y - currPos[1];
    // calculate length of vector
    float lengthTotal = std::sqrt(vx*vx + vy*y);
    // calculate length to position w1
    float length = height / std::tan(takeOffAngle*(180/std::numbers::pi));
    // calculate w1x and w1y
    float lengthToW1x = (length/lengthTotal) * vx;
    float lengthToW1y = (length/lengthTotal) * vy;

    vector<float> w1 = {lengthToW1x+currPos[0], lengthToW1y+currPos[1]};

    return w1;
}

vector<float> Ballistic::secondWaypoint(const float x, const float y, const float height) const{
    // get current position
    vector<float> currPos = {sim.getX(),sim.getY()};
    // calculate vector to end position
    float vx = x - currPos[0];
    float vy = y - currPos[1];
    // calculate length of vector
    float lengthTotal = std::sqrt(vx*vx + vy*vy);
    // calculate length to position w2
    float length = height / std::tan(landingAngle*(180/std::numbers::pi));
    // calculate w2x and w2y
    float lengthToW2x = ((length/lengthTotal)*vx) - vx;
    float lengthToW2y = ((length/lengthTotal)*vy) - vy;

    vector<float> w2 = {lengthToW2x+currPos[0], lengthToW2y+currPos[1]}; 
    
    return w2;
}
