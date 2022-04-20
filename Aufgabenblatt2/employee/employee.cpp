#include <cassert>
#include <ctime>
#include <iostream>
#include "employee.h"
using namespace std;

const string Employee::company = "CP Soft";

Employee::Employee(const string pName, const string pFirstName,
         const vector<int> pDateOfBirth, const float pSalary)
{
    name = pName;
    firstName = pFirstName;
    dateOfBirth = pDateOfBirth;
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

void Employee::print() const
{
    assert(dateOfBirth.size() == 3);
    cout << "Name:       " << name << '\n';
    cout << "Vorname:    " << firstName << '\n';
    cout << "Geburtstag: ";
    cout.width(2);
    cout.fill('0');
    cout << dateOfBirth[2] << '.';
    cout.width(2);
    cout.fill('0');
    cout << dateOfBirth[1] << '.' << dateOfBirth[0] << '\n';
    cout << "Company:    " << company << '\n';
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "Gehalt:     " << salary << " Euro\n";
}

int Employee::age() const
{
    assert(dateOfBirth.size() == 3);
    time_t now = time(nullptr);
    tm* t = localtime(&now);
    int year = t->tm_year + 1900;
    int month = t->tm_mon + 1;
    int day = t->tm_mday;

    int res = year - dateOfBirth[0] - 1;
    if (month >= dateOfBirth[1] && day >= dateOfBirth[2])
        res = res + 1;
    return res;
}

void Employee::riseSalary(const float rise)
{
    salary = salary * (1 + rise / 100);
}

