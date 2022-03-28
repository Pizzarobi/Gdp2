#include <iostream>
#include <vector>
#include <ctime>
using namespace std;


void print(const string& name, const string& firstName, const vector<int>& dateOfBirth, const float& salary){
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

int age(const vector<int> dateOfBirth){
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

void riseSalary(float& salary, const float rise){
    salary *= 1+rise;
}


int main(){

    string firstName = "Yo";
    string name = "Momma";

    vector<int> dateOfBirth = {2001,3, 2};
    float salary = 100.0;

    riseSalary(salary,0.5);

    print(name, firstName, dateOfBirth, salary);
    printf("Age:        %d\n",age(dateOfBirth));

    return 0;
}