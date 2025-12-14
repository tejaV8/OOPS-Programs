#include <iostream>
using namespace std;

class Shape
{
public:
    float volume(float s)
    {
        return s * s * s;
    }

    float volume(float l, float b, float h)
    {
        return l * b * h;
    }

    float volume(float r, float h)
    {
        return 3.14 * r * r * h;
    }
};

int main()
{
    Shape S;
    float s, l, b, h, r;

    cout << "\nEnter the length of Cube: ";
    cin >> s;

    cout << "Volume of cube = " << S.volume(s) << endl;

    cout << "\nEnter the length, breadth and height of Cuboid: ";
    cin >> l >> b >> h;

    cout << "Volume of Cuboid = " << S.volume(l, b, h) << endl;

    cout << "\nEnter the height and radius of Cylinder: ";
    cin >> h >> r;

    cout << "Volume of Cuboid = " << S.volume(h, r) << endl;

    return 0;
}
