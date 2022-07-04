// Bruch uebungsblatt2
#include "bruch.h"
#include <iostream>
#include <numeric>
using namespace std;

void Bruch::kuerze(){
    int teiler = ggt(zaehler,nenner);
    if(teiler > 1){
        nenner /= teiler;
        zaehler /= teiler;
    }
}

void Bruch::normalisiere(){
    kuerze();
    if(nenner < 0){
        nenner *= -1;
        zaehler *= -1;
    }
}

Bruch::Bruch(const int pz, const int pn){
    zaehler = pz;
    if(pn == 0)
        nenner = 1;
    else
        nenner = pn;
}

// greates common divisor
int Bruch::ggt(int a, int b){
    return (b != 0)?ggt(b, a%b):a;
}

void Bruch::add(const Bruch bruch){

}

void Bruch::sub(const Bruch bruch){
    
}

// Multiply current Bruch with parameter bruch
void Bruch::mult(const Bruch bruch){
    zaehler = bruch.zaehler * zaehler;
    nenner = bruch.nenner * nenner;
}

// Divde current by parameter bruch
void Bruch::div(const Bruch bruch){
    Bruch kehrwert = Bruch(bruch.nenner,bruch.zaehler);
    mult(kehrwert);
}

int main(){
    Bruch a = Bruch(15,20);
    Bruch b = Bruch(3,-12);
    a.normalisiere();
    b.normalisiere();

    cout << a.toString() << " " << b.toString() << endl;
}