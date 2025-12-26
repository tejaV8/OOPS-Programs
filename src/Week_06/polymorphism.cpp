#include <iostream>
using namespace std;

class A
{
    int x, y;

public:
    void set()
    {
        cout << "Enter x and y: ";
        cin >> x >> y;
    }
    void display()
    {
        cout << "x = " << x << ", y = " << y << endl;
    }
};

class B : public A
{
    int a, b;

public:
    void set()
    {
        cout << "Enter a and b: ";
        cin >> a >> b;
    }
    void display()
    {
        cout << "a = " << a << ", b = " << b << endl;
    }
};

int main()
{
    A a;
    B b;

    b.set();
    b.A::set();
    b.display();
    b.A::display();
}