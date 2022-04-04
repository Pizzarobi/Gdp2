#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <vector>
#include <ctime>

class Employee
{
    private:
        std::string name;
        std::string firstName;
        std::vector<int> dateOfBirth;
        float salary;

    public:
        Employee(const std::string pName, const std::string pFirstName,
                 const std::vector<int> pDateOfBirth, const float pSalary);
        float getSalary() const;
        void print() const;
        int age() const;
        void riseSalary(float rise);
};

#endif