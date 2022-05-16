#include <iostream>
#include <map>
#include <string>
#include "person.h"
using namespace std;

int main()
{
    map<string, Person> persons;
    persons.insert({"1001", Person("Castro", "Fidel", {1900, 10, 15})});
    persons.insert({"1002", Person("Lopez", "Jennifer", {1991, 6, 3})});
    persons.insert({"1003", Person("Duck", "Donald", {1923, 4, 1})});
    persons.insert({"1004", Person("Alster", "Ingrid", {1991, 6, 3})});

    // Der Konstruktor Person() wird fuer die folgende Zeile benoetigt
    cout << "Alter der Person mit Id 1003: " << persons["1003"].age() << "\n\n";

    for (const auto& p: persons)
    {
        cout << "Id:         " << p.first << '\n';
        p.second.print();
        cout << '\n';
    }

    cout << "Alter der Person mit ID 1003: " << persons["1003"].age() << endl << endl;

    return 0;
}