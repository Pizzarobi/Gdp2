#include <vector>
using namespace std;

class GraphObj {

private:
    int xCoord;
    int yCoord;
public:
    GraphObj(const int pXCoord, const int pYCoord);
    vector<int> getRefPoint() {return vector<int>{xCoord,yCoord};};
    vector<int> setRefPoint(const int pXCoord, const int pYCoord);
    virtual double area() = 0;
    virtual void draw();
};