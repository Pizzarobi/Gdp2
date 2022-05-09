#include <vector>
#include <algorithm>
#include <iostream>
#include "route.h"

void Route::add(const float destX, const float destY) {
    destinations.push_back(make_pair(destX, destY));
}

void Route::setDist(float (*pDist)(const float, const float, const float, const float, const float)){
    dist = pDist;
}

// Calculate distance from current destinations vector
const float Route::distance(){
    // Calculate distance to first waypoint
    float distance = dist(0.0,0.0,destinations[0].first,destinations[0].second,height);
    
    // Iterate through the destinations
    for(int i = 0; i < destinations.size();i++){
        distance += dist(destinations[i].first,destinations[i].second,destinations[i+1].first,destinations[i+1].second,height);
    }

    //cout << "currDist: " << distance << endl;
    return distance;
}

// Rearrange destinations to shortest route
void Route::shortestRoute(){
    vector<pair<float,float>> destBuffer = destinations;
    float bestDist = 0.0;
    float currDist = 0.0;
    cout << "Vor While" << endl;
    do{
        currDist = distance();

        if(currDist < bestDist || bestDist == 0.0){
            bestDist = currDist;
            destBuffer = destinations;
        }

        cout << "currDist: " << currDist << " bestDist: " << bestDist << endl;
    }while(std::next_permutation(destinations.begin(),destinations.end()));
    cout << "nach while" << endl;
}