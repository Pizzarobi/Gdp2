#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void search(const string filename, const string txt)
{
    if (filename.empty())
        throw "file name must be non-empty";
    if (txt.empty())
        //throw "search string must be non-empty";
        throw invalid_argument("search string must be non-empty");

    ifstream infile(filename);
    string line;
    int line_nr = 0;

    while (infile.good())
    {
        getline(infile, line);
        line_nr++;
        if (line.find(txt) != string::npos)
        {
            cout.width(2);
            cout << line_nr << " : " << line << '\n';
        }
    }
    infile.close();
}

int main()
{
    try
    {
        search("DerWerwolf.txt", "wolf");
    }
    // hier den catch-Block einfuegen
    catch(const char* error){

    }

    catch(invalid_argument& error){
        cout << error.what() << '\n';
    }
}