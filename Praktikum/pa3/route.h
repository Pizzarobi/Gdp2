#ifndef ROUTE_H
#define ROUTE_H

#include <vector>
using namespace std;

class Route {
private:
    vector<pair<float, float>> destinations;
    float height;
    // dist function whatever
    float (*dist)(const float, const float, const float, const float, const float);

public:
    void add(const float destX, const float destY);
    const vector<pair<float, float>> getDestinations() const { return destinations;};
    const float getHeight() {return height;};
    void setHeight(const float pHeight) {height = pHeight;};
    void setDist(float (*pDist)(const float x1, const float y1, const float x2, const float y2, const float h));
    const float distance();
    void shortestRoute();
};



#endif