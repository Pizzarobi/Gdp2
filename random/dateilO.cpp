#include <fstream>
#include <iostream>
#include <string>
using namespace std;

//Sehr simple implementierung nur zum Test

int main(){
    string dateiname = "test.txt";

    ifstream datei(dateiname);

    while (datei.good()){
        string zeile;
        getline(datei, zeile);
        cout << zeile << '\n';
    }
}