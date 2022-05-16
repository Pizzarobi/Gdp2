#include <cassert>
#include <ctime>
#include <iostream>
#include "person.h"
using namespace std;

Person::Person(){}
Person::Person(const string pName, const string pFirstName,
               const vector<int> pDateOfBirth)
{
    name = pName;
    firstName = pFirstName;
    dateOfBirth = pDateOfBirth;
}

void Person::print() const
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
}

int Person::age() const
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
