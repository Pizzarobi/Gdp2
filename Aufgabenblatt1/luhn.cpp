#include <string>
#include <iostream>
#include <vector>
using namespace std;

// KEIN BOCK DES FERTIG ZU MACHEN PEPELA
bool check(const string& knum, const int anz){
    //ueberpruefe ob string nur Buchstaben und Ziffern hat
    if(!(knum.find_first_not_of("0123456789 ")==string::npos))
        throw "enthaelt Buchstaben";
    // check anz == zifern in knum
    int ziffern = knum.length();
    for (int i = 0; i < knum.length(); i++)
    {   
        if(knum.at(i)==' '){
            ziffern--;
            //cout << ziffern << endl;
        }
    }
    if(anz!=ziffern)
        throw "anz!=ziffern";
    
    // matches anfangs voraussetzungen
    // load out to number array
    vector<int> nums;
    for (int i = 0; i < knum.length(); i++)
    {
        if(isdigit(knum.at(i)))
            nums.push_back(knum.at(i)-'0');
    }
    
    return 0;
}

int main(int argc, char *argv[]){
    string ecCard = "1234567";
    int anz = 7;
    try{
        cout << check(ecCard,anz) << endl;
    } catch(const char* error) {
        cout << error << endl;
    }
}
