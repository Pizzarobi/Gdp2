#include "graphObj.h"
#include <vector>

class Line : public GraphObj{

private:
    int endX;
    int endY;
public:
    Line(const int pXCoord, const int pYCoord, const int pEndX, const int pEndY):
    GraphObj(pXCoord,pYCoord){endX=pEndX;endY=pEndY;};
    vector<int> getEndPoint();
    double length();
    virtual double area(){return 0;};
    virtual void draw();
};