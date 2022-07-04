#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string infile = "punkte.csv";
    ifstream instream(infile);
    string outfile = "noten.txt";
    ofstream outstream(outfile);

    if (!instream.good())
        return 1;

    outstream << "Matrikel   A1   A2   A3   A4   A5   A6   A7   A8 Punkte Note\n";

    size_t pos;
    float summe;

    while (instream.good())
    {
        string line;
        getline(instream, line);
        if ((pos = line.find(';')) != string::npos)
        {
            outstream.width(8);
            outstream << line.substr(0, pos);
            line = line.substr(pos + 1, line.length());
        }
        summe = 0;
        while ((pos = line.find(';')) != string::npos)
        {
            summe = summe + stof(line.substr(0, pos));
            outstream.width(5);
            outstream << line.substr(0, pos);
            line = line.substr(pos + 1, line.length());
        }
        if (line != "")
        {
            summe = summe + stof(line);
            outstream.width(5);
            outstream << line;
            outstream.width(7);
            outstream.setf(ios::fixed);
            outstream.precision(1);
            outstream << summe;
            outstream << "  1.0" << '\n';
        }
    }
}
