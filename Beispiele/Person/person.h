#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>

class Person
{
private:
    std::string name;
    std::string firstName;
    std::vector<int> dateOfBirth;
public:
    Person();
    Person(const std::string pName, const std::string pFirstName,
           const std::vector<int> pDateOfBirth);
    void print() const;
    int age() const;
};

#endif
