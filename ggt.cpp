#include <iostream>
using namespace std;

int main(){
    int v1;
    int v2;
    cout << "GIB ZAHL DU BASTARD\n";
    cin >> v1;
    cin >> v2;
    while (v1 != v2){
        if (v1<v2){
            v2 -= v1;
        } else {
            v1 -= v2;
        }
    }
    cout << "Der groesste geimeinsame Teiler:" << v1 <<'\n';
}