#include "person.h"
#include <iostream>

Person::Person(const std::string pName, const std::string pFirstName, const std::vector<int> pDateOfBirth){
    name = pName;
    firstName = pFirstName;
    dateOfBirth = pDateOfBirth;
}

void Person::print() const
{
    std::cout << "Name:       " << name << '\n';
    std::cout << "Vorname:    " << firstName << '\n';
    std::cout << "Geburtstag: ";
    std::cout.width(2);
    std::cout.fill('0');
    std::cout << dateOfBirth[2] << '.';
    std::cout.width(2);
    std::cout.fill('0');
    std::cout << dateOfBirth[1] << '.' << dateOfBirth[0] << '\n';
}

int Person::age() const
{
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