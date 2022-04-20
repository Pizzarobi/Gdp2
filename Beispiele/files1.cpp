#include <iostream>
using namespace std;


class File
{
    private:
        string name;
        
    public:
        File(const string pName)
        {
            name = pName;
        }
        string getName() const {return name;}
        int fsize() const {return 0;}
};

class ImageFile: public File
{
    private:
        // other attributes omitted, e.g. path, access rights, ...
        int height;
        int width;
        int bits;
    public:
        ImageFile(const string pName, const int pHeight,
                const int pWidth, const int pBits): File(pName)
        {
            height = pHeight;
            width = pWidth;
            bits = pBits;       // bits per pixel
        }
};

class TextFile: public File
{
    private:
        // other attributes omitted, e.g. path, access rights, ...
        int chars;              // number of characters in file
        int bytes;              // bytes per character
    public:
        TextFile(const string pName, const int pChars,
                const int pBytes): File(pName)
        {
            chars = pChars;
            bytes = pBytes;
        }
};

int main()
{
    ImageFile ifile("image.bmp", 480, 640, 16);
    cout << ifile.getName() << " " << ifile.fsize() << '\n';
    TextFile tfile("text.txt", 1000, 2);
    cout << tfile.getName() << " " << tfile.fsize() << '\n';
}
