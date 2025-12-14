#include <iostream>
using namespace std;

class unaryop
{
    int x, y;

public:
    void set()
    {
        cout << "enter the values of x,y: ";
        cin >> x >> y;
    }
    void show()
    {
        cout << "x = " << x << ", y = " << y << endl;
    }
    void operator++()
    {
        x++, y++;
    }
    void operator--()
    {
        --x, --y;
    }
};

int main()
{
    unaryop m2;

    m2.set();
    m2.show();

    cout << "\nAfter ++: ";
    ++m2;
    m2.show();

    cout << "After --: ";
    --m2;
    m2.show();

    return 0;
}