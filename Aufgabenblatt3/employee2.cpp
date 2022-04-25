#include <iostream>
#include "employee2.h"
using namespace std;

const string Employee::company = "CP Soft";

Employee::Employee(const string pName, const string pFirstName,
                   const vector<int> pDateOfBirth, const float pSalary)
                   : Person(pName, pFirstName, pDateOfBirth)
{
    salary = pSalary;
}

string Employee::getCompany()
{
    return company;
}

float Employee::getSalary() const
{
    return salary;
}

void Employee::printEmployee() const
{
    cout << "Company:    " << company << '\n';
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "Gehalt:     " << salary << " Euro\n";
}

void Employee::riseSalary(const float rise)
{
    salary = salary * (1 + rise / 100);
}

