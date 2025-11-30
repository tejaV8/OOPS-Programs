#include <iostream>
using namespace std;

class Volume
{
public:
    float l, b, h;

public:
    Volume()
    {
        cout << "\nDefault Constructor:\n";
        cout << "Enter length, breadth and height: ";
        cin >> l >> b >> h;
    }

    Volume(int x, int y, int z)
    {
        l = x;
        b = y;
        h = z;
    }

    void display()
    {
        cout << "Volume of cuboid: " << l * b * h;
    }
};

int main()
{
    Volume v1, v2(2, 3, 5);

    v1.display();

    cout << endl;

    cout << "\nParameterised Constructor:\n";
    v2.display();
    cout << endl;
}
