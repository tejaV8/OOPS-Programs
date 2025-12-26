#include <iostream>
using namespace std;

class Assign
{
    int x;

public:
    Assign()
    {
        x = 0;
    }

    Assign(int x)
    {
        this->x = x;
    }

    void operator=(const Assign &a)
    {
        x = a.x;
    }

    void show()
    {
        cout << "Value of x: " << x << endl;
    }
};

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    Assign a(n), b;

    b = a;

    a.show();
    b.show();

    return 0;
}
