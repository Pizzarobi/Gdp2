#include <vector>
#include <iostream>

#include "ufo.h"
#include "ballistic.h"
#include "vertical.h"
#include "route.h"

int main(){
    Route route;
    route.add(10.0,5.0);
    route.add(10.0,0.0);
    route.add(0.0,10.0);
    route.setHeight(3.0);

    route.setDist(&Vertical::distance);
    route.distance();

    route.shortestRoute();
    //cout << "Shortest Route: " << route.distance() << endl;
}