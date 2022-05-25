#ifndef BALLISTIC_H
#define BALLISTIC_H

#include "ufo.h"

class Ballistic : public Ufo{
    private:
        float takeOffAngle;
        float landingAngle;
    public:
        Ballistic(string pId, float pTakeOffAngle, float pLandingAngle);
        float getTakeOffAngle();
        float getLandingAngle();
        void flyToDest(const float x, const float y, const float height, const int speed) override;
        vector<float> firstWaypoint(const float x, const float y, const float height) const;
        vector<float> secondWaypoint(const float x, const float y, const float height) const;
};

#endif
// g++ -std=c++20 -I"C:\Program Files\boost_1_78_0" -L"C:\Program Files\boost_1_78_0\stage\lib" -l:libboost_unit_test_framework-mgw11-mt-d-x64-1_78.dll -D BOOST_TEST_DYN_LINK ballistic.cpp vertical.cpp ufo.cpp ufosim.cpp pa2_utest.cpp -o pa2.exe