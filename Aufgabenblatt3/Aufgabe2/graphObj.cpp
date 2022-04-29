#include "graphObj.h"

std::vector<int> GraphObj::getRefPoint(){
    return {xCoord,yCoord};
}

std::vector<int> GraphObj::setRefPoint(const int pXCoord, const int pYCoord){
    std::vector<int> old = {xCoord,yCoord};
    xCoord = pXCoord;
    yCoord = pYCoord;
    return old;
}

void GraphObj::draw(){
    
}