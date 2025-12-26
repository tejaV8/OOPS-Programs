#include <iostream>
using namespace std;

class Smaller
{
    int x;

public:
    Smaller()
    {
        x = 0;
    }

    Smaller(int x)
    {
        this->x = x;
    }

    bool operator<(const Smaller &l)
    {
        return x < l.x;
    }
};

int main()
{
    int n1, n2;

    cout << "Enter two numbers: ";
    cin >> n1 >> n2;

    Smaller a(n1), b(n2);

    if (a < b)
        cout << "a is less than b";
    else
        cout << "a is greater or equal to b";

    return 0;
}
