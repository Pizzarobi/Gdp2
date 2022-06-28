#include <iostream>
#include <vector>
using namespace std;

class File
{
private:
    string name;
    // other attributes omitted, e.g. path, access rights, ...
public:
    File(const string pName)
    {
        name = pName;
    }
    string getName() const { return name;}
    virtual int fsize() const = 0;
};

int File::fsize() const { return 0; }

class ImageFile : public File
{
private:
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
    virtual int fsize() const override { return height * width * bits; }
};

class TextFile : public File
{
private:
    int chars;              // number of characters in file
    int bytes;              // bytes per character
public:
    TextFile(const string pName, const int pChars,
             const int pBytes): File(pName)
    {
        chars = pChars;
        bytes = pBytes;
    }
    virtual int fsize() const override { return chars * bytes * 8; }
};

int main()
{
    ImageFile ifile("image.bmp", 480, 640, 16);
    TextFile tfile("text.txt", 1000, 2);
    vector<File*> files = { &ifile, &tfile };
    for (auto fp: files)
        cout << fp->getName() << " " << fp->fsize() << '\n';
}
