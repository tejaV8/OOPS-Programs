#include <iostream>
using namespace std;

class MusicalComposition
{
    string title;
    string composer;
    int year;

public:
    MusicalComposition(string t = "", string c = "", int y = 0)
    {
        title = t;
        composer = c;
        year = y;
    }

    void musicDisplay()
    {
        cout << title << "\t" << composer << "\t" << year;
    }
};

class NationalAnthem : public MusicalComposition
{
    string country;

public:
    NationalAnthem(string t = "", string c = "", int y = 0, string ctr = "") 
        : MusicalComposition(t, c, y)
    {
        country = ctr;
    }

    void anthemDisplay()
    {
        musicDisplay();
        cout << country << endl;
    }
};

int main()
{
    NationalAnthem n1("Jana Gana Mana", "Rabindranath Tagore", 1911, "India");
    NationalAnthem n2("The Star-Spangled Banner", "Francis Scott Key", 1814, "USA");
    NationalAnthem n3("O Canada", "Calixa Lavallée", 1880, "Canada");

    cout << "Title\t\t\tComposer\tYear\tCountry\n";

    n1.anthemDisplay();
    n2.anthemDisplay();
    n3.anthemDisplay();

    return 0;
}