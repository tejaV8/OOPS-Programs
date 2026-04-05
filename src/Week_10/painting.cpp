#include <iostream>
using namespace std;

class Painting
{
protected:
    string title;
    string artist;
    double value;

public:
    Painting(string t, string a, double v = 400)
    {
        title = t;
        artist = a;
        value = v;
    }

    void displayPainting()
    {
        cout << title << "\t" << artist << "\t" << value << endl;
    }
};

class FamousPainting : public Painting
{
public:
    FamousPainting(string t, string a) : Painting(t, a, 25000) {}
};

int main()
{
    Painting *p[4];
    string t, a;

    for (int i = 0; i < 4; i++)
    {
        cout << "Enter title and artist of painting " << i + 1 << ": ";
        cin >> t >> a;

        if (a == "Degas" || a == "Monet" || a == "Picasso" || a == "Rembrandt")
            p[i] = new FamousPainting(t, a);
        else
            p[i] = new Painting(t, a);
    }

    cout << "Title\tArtist\tValue\n";
    for (int i = 0; i < 4; i++)
        p[i]->displayPainting();

    return 0;
}