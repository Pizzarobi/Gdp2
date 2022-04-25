#include "ballistic.h"

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
    // calculate angle between start point and end point
    vector<float> currPos = {sim.getX(),sim.getY()};

    
    vector<float> w1 = {0,0};
    return w1;
}

vector<float> Ballistic::secondWaypoint(const float x, const float y, const float height) const{
    vector<float> w2 = {0,0};
    return w2;
}
