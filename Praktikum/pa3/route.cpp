#include <vector>
#include <algorithm>
#include <iostream>
#include "route.h"
using namespace std;

void Route::add(const float destX, const float destY){
    destinations.push_back(make_pair(destX, destY));
}

void Route::setDist(float (*pDist)(const float, const float, const float, const float, const float)){
    dist = pDist;
}

// Calculate distance from current destinations vector
float Route::distance() const{
    if(destinations.size()==0){
        return 0.0;
    }

    // Calculate distance to first waypoint
    float distance = dist(0.0,0.0,destinations[0].first,destinations[0].second,height);
    int size = destinations.size();

    // Iterate through the destinations
    for(int i = 1; i < size;i++){
        distance += dist(destinations[i-1].first,destinations[i-1].second,destinations[i].first,destinations[i].second,height);
    }
    distance += dist(destinations[size-1].first,destinations[size-1].second,0.0,0.0,height);

    //cout << "currDist: " << distance << endl;
    return distance;
}

// Rearrange destinations to shortest route
void Route::shortestRoute(){
    vector<pair<float,float>> destBuffer = destinations;
    float bestDist = 0.0;
    float currDist = 0.0;
    //cout << "Destinations Size: " << destinations.size() << endl;

    //cout << "Testing perm: " << std::next_permutation(destinations.begin(), destinations.end()) << endl;
    if(destinations.size()>=1){
        while(next_permutation(destinations.begin(), destinations.end())){
            currDist = distance();

            if(currDist < bestDist || bestDist == 0.0){
                bestDist = currDist;
                destBuffer = destinations;
            }

            //cout << "currDist: " << currDist << " bestDist: " << bestDist << endl;
        }
        destinations = destBuffer;
    }


    //cout << "nach while" << endl;
}