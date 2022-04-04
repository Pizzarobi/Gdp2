#include <iostream>
#include "employee.h"
using namespace std;

int main(){
    Employee em("Yo","Mamma", {2001,5,20},500.0);
    em.riseSalary(0.5);
    em.print();
    cout << "\nAge: " << em.age() << "\n";
}