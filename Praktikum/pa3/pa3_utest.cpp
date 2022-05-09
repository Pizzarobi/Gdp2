#define BOOST_TEST_MAIN
#include <cmath>
#include <type_traits>
#include <vector>
#include <boost/test/included/unit_test.hpp>
#include "ufo.h"
#include "ballistic.h"
#include "vertical.h"
//#include "route.h"
    
BOOST_AUTO_TEST_SUITE(pa_utest)

std::vector<float> dest1 = { 10.0, 10.0, 8.0 };
std::vector<float> dest2 = { 10.0, 0.0, 10.0 };
std::vector<float> dest3 = { 30.0, 30.0, 8.0 };
std::vector<float> dest4 = { -10.0, 0.0, 4.0 };

BOOST_AUTO_TEST_CASE(vertical_distance)
{
    BOOST_CHECK(fabs(Vertical::distance(0.0, 1.0, 0.0, 1.0, 10.0) - 20.0) < 0.001);
    BOOST_CHECK(fabs(Vertical::distance(1.0, -1.0, -10.5, -20.11, 0.0) - 22.3034) < 0.001);
    BOOST_CHECK(fabs(Vertical::distance(1.0, -1.0, -10.5, -20.11, 8.0) - 38.3034) < 0.001);
}

float myDist(const float, const float, const float, const float, const float)
{
    return 3.0;
}

BOOST_AUTO_TEST_SUITE_END()