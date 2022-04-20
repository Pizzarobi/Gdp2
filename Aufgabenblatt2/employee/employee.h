#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <vector>

class Employee
{
private:
    std::string name;
    std::string firstName;
    std::vector<int> dateOfBirth;
    static const std::string company;
    float salary;
public:
    Employee(const std::string pName, const std::string pFirstName,
             const std::vector<int> pDateOfBirth, const float pSalary);
    static std::string getCompany();
    float getSalary() const;
    void print() const;
    int age() const;
    void riseSalary(const float rise);
};

#endif
