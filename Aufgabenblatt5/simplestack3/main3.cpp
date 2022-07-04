#include "SimpleStack3.t"
#include <iostream>
using namespace std;

int main()
{
    SimpleStack3<int> einIntStack; // ein Stack f�r int-Zahlen
    for (int i = 0; i < 100; i++)
    {
        einIntStack.push(i); // Stack f�llen
    }
    cout << "Anzahl : " << einIntStack.size() << '\n';
    cout << "oberstes Element: " << einIntStack.top() << '\n';
    cout << "alle Elemente entnehmen und anzeigen: \n";
    while (!einIntStack.empty())
    {
        int i = einIntStack.top();
        einIntStack.pop();
        cout << i << '\t';
    }
    cout << '\n';
}
