#include <iostream>
using namespace std;

class A
{
public:
    virtual void display()
    {
        cout << "Class A\n";
    }
};

class B : public A
{
public:
    virtual void display()
    {
        cout << "Class B\n";
    }
};

class C : public B
{
public:
    virtual void display()
    {
        cout << "Class C\n";
    }
};

int main()
{
    A *ptr;
    B b;
    C c;

    ptr = &b;
    ptr->display();

    ptr = &c;
    ptr->display();

    cout << endl;
    b.display();
    c.display();

    return 0;
}
