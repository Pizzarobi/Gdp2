#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int anzahl;
    cin >> anzahl;

    vector<double> kosten(anzahl); // dynamic vector size
    //kosten = {1.0,2.0,3.0,4.0};

    for (auto& x: kosten){ // for each
        x = 1.0; // braucht referenz &
    }

    kosten.push_back(2.0); // Anfügen am Ende

    //ranges::sort(kosten); braucht -std=c++20

    cout.setf(ios::fixed);
    cout.precision(2); // set precision of variables in cout

    for (double x: kosten){
        cout << x << ' ';
    }

    return 0;
}