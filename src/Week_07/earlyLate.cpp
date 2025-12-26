#include <iostream>
using namespace std;

class Shape
{
protected:
    int result;

public:
    virtual void area() = 0;
    virtual void display() = 0;
};

class Square : public Shape
{
    int s;

public:
    void area() override
    {
        cout << "\nEnter side of square: ";
        cin >> s;
        result = s * s;
    }

    void display() override
    {
        cout << "Area of square: " << result << endl;
    }
};

class Rectangle : public Shape
{
    int l, b;

public:
    void area() override
    {
        cout << "\nEnter length and breadth: ";
        cin >> l >> b;
        result = l * b;
    }

    void display() override
    {
        cout << "Area of rectangle: " << result << endl;
    }
};

int main()
{
    Square s;
    s.area();
    s.display();

    Shape *ptr;
    Rectangle r;
    ptr = &r;
    ptr->area();
    ptr->display();

    return 0;
}