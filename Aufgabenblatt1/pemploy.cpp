#include <iostream>
#include <vector>
using namespace std;


void print(string name, string firstName, vector<int> dateOfBirth, float salary){
    cout << "Name:       " << name << "\n";
    cout << "Vorname:    " << firstName << "\n";
    cout << "Geburtstag: " << dateOfBirth[2] << "."<< dateOfBirth[1] << "." << dateOfBirth[0] << "\n";
    cout << "Gehalt:     " << salary << " Euro\n";

}


int main(){
    cout.width(2);
    cout.fill('0');
    cout.setf(ios::fixed);
    cout.precision(2);

    string name = "Hentai";
    string firstName = "Steven";

    vector<int> dateOfBirth = {1969, 9, 6};
    float salary = 2.0;

    print(name, firstName, dateOfBirth, salary);

    return 0;
}