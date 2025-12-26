#include <iostream>
using namespace std;

class Greater
{
    int x;

public:
    Greater()
    {
        x = 0;
    }

    Greater(int x)
    {
        this->x = x;
    }

    bool operator>(const Greater &g)
    {
        return x > g.x;
    }
};

int main()
{
    int n1, n2;

    cout << "Enter two numbers: ";
    cin >> n1 >> n2;

    Greater a(n1), b(n2);

    if (a > b)
        cout << "a is greater than b";
    else
        cout << "b is greater or equal to a";

    return 0;
}
