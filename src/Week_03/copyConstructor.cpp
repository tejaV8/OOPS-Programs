#include <iostream>
using namespace std;

class Rectangle
{
    int l, b;

public:
    Rectangle()
    {
        cout << "\nDefault constructor";
        cout << endl
             << "Enter length and breadth: ";
        cin >> l >> b;
    }

    Rectangle(int x, int y)
    {
        l = x;
        b = y;
    }

    Rectangle(Rectangle &obj)
    {
        l = obj.l;
        b = obj.b;
    }

    void area()
    {
        cout << "Area of rectangle is " << l * b << endl;
    }
};

int main()
{
    Rectangle R1, R2(10, 20);
    Rectangle R3 = R2;
    Rectangle R4(R2);

    R1.area();

    cout << "\nParamterised conctructor:\n";
    R2.area();

    cout << "\nShallow copy:\n";
    R3.area();

    cout << "\nDeep copy:\n";
    R4.area();

    cout << endl;

    return 0;
}