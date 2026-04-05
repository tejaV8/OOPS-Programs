#include <iostream>
using namespace std;

class A
{
public:
    virtual void set()
    {
        int x, y;
        cout << "Enter x and y: ";
        cin >> x >> y;
    }

    virtual void display()
    {
        cout << "Base class display" << endl;
    }
};

class B : public A
{
    int a, b;

public:
    void set() override
    {
        cout << "Enter a and b: ";
        cin >> a >> b;
    }

    void display() override
    {
        cout << "a = " << a << ", b = " << b << endl;
    }
};

int main()
{
    A *ptr;
    B obj;

    ptr = &obj;

    ptr->set();
    ptr->display(); 

    return 0;
}