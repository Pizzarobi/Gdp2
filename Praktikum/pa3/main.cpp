#include <vector>
#include <iostream>

#include "ufo.h"
#include "ballistic.h"
#include "vertical.h"
#include "route.h"

int main(){
    Route route;
    // works
    // route.add(1.0,1.0);
    // route.add(2.0,2.0);
    // route.add(3.0,3.0);

    // does not work
    // route.add(10.0,5.0);
    // route.add(10.0,0.0);
    // route.add(0.0,10.0);

    // from boost check
    route.add(55.0, 20.0);
    route.add(-116.5, 95.0);
    route.add(-10.0, -40.0);
    route.add(-115.0, 95.0);
    
    route.setHeight(10.0);

    route.setDist(&Vertical::distance);
    cout << "First Test: " << route.distance() << endl;

    route.shortestRoute();
    cout << "Shortest Route: " << route.distance() << endl;
}