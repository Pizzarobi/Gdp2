#include <iostream>
using namespace std;

// Call-by-value
int fac1(int n)
{
    int res = 1;
    for (int i = 1; i <= n; i++)
        res = res * i;
    // n ist lokal in der Funtion
    n = 0;
    return res;
}

int fac2(const int n)
{
    int res = 1;
    for (int i = 1; i <= n; i++)
        res = res * i;
    //n = 0; // Fehler: Der Parameter ist const.
    return res;
}

// Call-by-reference
int fac3(int& n)
{
    int res = 1;
    for (int i = 1; i <= n; i++)
        res = res * i;
    n = 0; // Die globale Variable n wird geaendert.
    return res;
}

int fac4(const int& n)
{
    int res = 1;
    for (int i = 1; i <= n; i++)
        res = res * i;
    //n = 0; // Fehler: Der Parameter ist const.
    return res;
}

void fac5(int n, int& res)
{
    res = 1;
    for (int i = 1; i <= n; i++)
        res = res * i;
}

void replace1(string& str, const char c, const char d)
{
    for (size_t i = 0; i < str.length(); i++)
        if (str[i] == c)
            str[i] = d;
}

string& replace2(string& str, const char c, const char d)
{
    for (size_t i = 0; i < str.length(); i++)
        if (str[i] == c)
            str[i] = d;
    return str;
}

const string& replace3(string& str, const char c, const char d)
{
    for (size_t i = 0; i < str.length(); i++)
        if (str[i] == c)
            str[i] = d;
    return str;
}

string replace4(string& str, const char c, const char d)
{
    for (size_t i = 0; i < str.length(); i++)
        if (str[i] == c)
            str[i] = d;
    return str;
}

int main()
{
    int n = 3;

    cout << "fac1: " << fac1(n) << " is the factorial of " << n << '\n';
    cout << "fac2: " << fac2(n) << " is the factorial of " << n << '\n';
    cout << "fac3: " << fac3(n) << " is the factorial of " << n << '\n';
    // Fehler: Es kann keine Referenz auf 3 erstellt werden.
    //cout << "fac3: " << fac3(3) << " is the factorial of " << "3" << '\n';
    n = 3;
    cout << "fac4: " << fac4(n) << " is the factorial of " << n << '\n';
    cout << "fac4: " << fac4(3) << " is the factorial of " << "3" << '\n';
    int res5 = 1;
    fac5(n, res5);
    cout << "fac5: " << res5 << " is the factorial of " << n << '\n' << '\n';

    string str = "Technische Hochschule";
    replace1(str, 's', 't');
    cout << "replace1: " << str << " is the replacement of " << str << '\n';
    str = "Technische Hochschule";
    string& rep2 = replace2(str, 's', 't');
    cout << "replace2: " << rep2 << " is the replacement of " << str << '\n';
    rep2[0] = 'X';
    cout << "After replace2: rep2 is a reference to str, rep2: "
         << rep2 << ", str: " << str << '\n';
    str = "Technische Hochschule";
    // const erforderlich
    const string& rep3 = replace3(str, 's', 't');
    cout << "replace3: " << rep3 << " is the replacement of " << str << '\n';
    // Fehler, weil const
    //rep3[0] = 'X';
    str = "Technische Hochschule";
    string rep4 = replace4(str, 's', 't');
    cout << "replace4: " << rep4 << " is the replacement of " << str << '\n';
    rep4[0] = 'X';
    cout << "After replace3: rep4 and str are different strings, rep4: "
         << rep4 << ", str: " << str << '\n';

    return 0;
}
