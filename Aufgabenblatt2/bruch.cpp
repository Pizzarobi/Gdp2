// Bruch uebungsblatt2
#include "bruch.h"
#include <iostream>
using namespace std;

Bruch::Bruch(const int pz, const int pn){
    zaehler = pz;
    if(pn == 0)
        nenner = 1;
    else
        nenner = pn;
}

int Bruch::ggt(int a, int b){
    if (a == 0)
        return b;
    return ggt(b % a, a);
}

void Bruch::add(const Bruch bruch){

}

void Bruch::mult(const Bruch bruch){
    zaehler = bruch.zaehler + zaehler;
    nenner = bruch.nenner + nenner;
}

void Bruch::div(const Bruch bruch){
    Bruch kehrwert = Bruch(bruch.nenner,bruch.zaehler);
    string kehrStr = kehrwert.zaehler + "/" + kehrwert.nenner;
    cout << kehrStr;
}

int main(){
    Bruch a = Bruch(2,3);
    Bruch b = Bruch(3,4);
    a.div(b);

}