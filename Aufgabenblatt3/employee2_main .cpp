#include <iostream>
#include "employee2.h"
using namespace std;

int main()
{
    Employee em("Alster", "Ingrid", {1990, 6, 11}, 4000.0);
    em.riseSalary(1.5);
    em.print();
    em.printEmployee();
}
