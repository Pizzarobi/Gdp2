#ifndef EMPLOYEE2_H
#define EMPLOYEE2_H

#include <string>
#include <vector>
#include "person.h"

class Employee : public Person
{
private:
    float salary;
    static const std::string company;
public:
    Employee(const std::string pName, const std::string pFirstName,
             const std::vector<int> pDateOfBirth, const float pSalary);
    static std::string getCompany();
    float getSalary() const;
    void printEmployee() const;
    void riseSalary(const float rise);
};

#endif
