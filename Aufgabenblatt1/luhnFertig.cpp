#include <cctype>
#include <iostream>
#include <string>
using namespace std;

bool check(const string& knum, const int anz)
{

    // Im String knum duerfen ausser Leerzeichen nur Ziffern sein.
    // Es muessen genau anz Ziffern enthalten sein.
    // Beispiel:
    //   anz = 16
    //   knum "4683 4578 2931 6528"
    //
    // Wir pruefen die Syntax ohne regexp Patterns und dergleichen.

    // 1) Gehe von rechts nach links durch String
    //    Verdopple jede zweite Ziffer und bilde deren Quersumme falls > 9
    // 2) Summiere alle Positionen
    // 3) Pruefe, ob Summe % 10 == 0

    int checksum = 0;
    int anzFound = 0;
    bool doDouble = false; // Flag fuer Aktivierung der Verdopplung

    for (int i = knum.length() -1 ; i >= 0; i--) {
        char c = knum.at(i);

        if (c != ' ' && !isdigit(c)) {
            return false;
        }

        if (c != ' ') { // Wir haben eine Ziffer
            anzFound++;
        }
        else {
            continue;
        }

        int value;

        if (doDouble) {
            value = 2 * (c - '0');

            // Der folgende Code berechnet die Quersumme der
            // Zahl 0 <= value < 20
            // Falls value > 9 muss gelten value = 10 + x
            // Daher gilt fuer die Quersumme q = 1 + x wobei x = value - 10
            // 1 + x = 1 + (value - 10) = value - 9
            checksum += value > 9 ? value - 9 : value;
        }
        else {
            value = c - '0';
            checksum += value;
        }

        doDouble = ! doDouble;
    }

    if (anzFound != anz) {
        return false;
    }

    return (checksum % 10 == 0);
}

int main()
{
    cout << check("4683 4578 2931 6528", 16) << '\n'; // true
    cout << check("4683 4578 2931 6538", 16) << '\n'; // false
    cout << check("4683 29 31 6538", 16) << '\n';     // false
    cout << check("4683 4578 2931 X528", 16) << '\n'; // false
}
