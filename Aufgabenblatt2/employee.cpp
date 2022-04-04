#include "employee.h"
using namespace std;

Employee::Employee(const string pName, const string pFirstName,
                   const vector<int> pDateOfBirth, const float pSalary){
    name = pName;
    firstName = pFirstName;
    dateOfBirth = pDateOfBirth;
    salary = pSalary;
}

float Employee::getSalary() const{
    return salary;
}

void Employee::print() const{
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "Name:       " << name << "\n";
    cout << "Vorname:    " << firstName << "\n" << "Geburtstag: ";
    cout.width(2); cout.fill('0');
    cout << dateOfBirth[2] << ".";
    cout.width(2); cout.fill('0');
    cout << dateOfBirth[1] << "." << dateOfBirth[0] << "\n";
    cout << "Gehalt:     " << salary << " Euro\n";
}

int Employee::age() const {
    // Get current time
    time_t now = time(nullptr);
    tm * t = localtime(&now);
    int year = t->tm_year + 1900;
    int month = t->tm_mon + 1;
    int day = t->tm_mday;

    int age_Y = year - dateOfBirth[0];
    int age_M = month - dateOfBirth[1];
    int age_D = day - dateOfBirth[2];

    if(age_M <= 0)
        if(age_D < 0)
            age_Y--;

    return age_Y;
}

void Employee::riseSalary(const float rise){
    salary *= 1+rise;
}
