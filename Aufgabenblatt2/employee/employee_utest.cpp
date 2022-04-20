#define BOOST_TEST_MAIN
#include <ctime>
#include "boost/test/included/unit_test.hpp"
#include "employee.h"

BOOST_AUTO_TEST_SUITE(employee_utest)

std::vector<int> today()
{
    time_t now = time(nullptr);
    tm* t = localtime(&now);
    std::vector<int> d = {t->tm_year + 1900, t->tm_mon + 1, t->tm_mday};
    return d;
}

BOOST_AUTO_TEST_CASE(age1)
{
    // birthday later in the year or today
    std::vector<int> d = today();
    int theAge = 20;
    d[0] = d[0] - theAge;
    if (d[1] == 12 && d[2] == 31)
    {
        Employee em("Alster", "Ingrid", d, 4000.0);
        BOOST_CHECK(em.age() == theAge);
    }
    else
    {
        d[1] = 12;
        d[2] = 31;
        Employee em("Alster", "Ingrid", d, 4000.0);
        BOOST_CHECK(em.age() == theAge-1);
    }
}

BOOST_AUTO_TEST_CASE(age2)
{
    // birthday today
    std::vector<int> d = today();
    int theAge = 20;
    d[0] = d[0] - theAge;
    Employee em("Alster", "Ingrid", d, 4000.0);
    BOOST_CHECK(em.age() == theAge);
}

BOOST_AUTO_TEST_CASE(age3)
{
    // birthday earlier in the year or today
    std::vector<int> d = today();
    int theAge = 20;
    d[0] = d[0] - theAge;
    d[1] = 1;
    d[2] = 1;
    Employee em("Alster", "Ingrid", d, 4000.0);
    BOOST_CHECK(em.age() == theAge);
}

BOOST_AUTO_TEST_CASE(rise1)
{
    Employee em("Alster", "Ingrid", {1990, 6, 11}, 4000.0);
    em.riseSalary(5);
    BOOST_CHECK(em.getSalary() == 4200.0);
}

BOOST_AUTO_TEST_CASE(rise2)
{
    Employee em("Alster", "Ingrid", {1990, 6, 11}, 4000.0);
    em.riseSalary(0);
    BOOST_CHECK(em.getSalary() == 4000.0);
}

BOOST_AUTO_TEST_CASE(getCompany)
{
    BOOST_CHECK(Employee::getCompany() == "CP Soft");
}

BOOST_AUTO_TEST_SUITE_END()
