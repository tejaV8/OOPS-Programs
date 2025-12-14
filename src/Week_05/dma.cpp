#include <iostream>
using namespace std;

class DMA
{
    int *rno;

public:
    DMA()
    {
        rno = new int[10];
        cout << "Enter 10 roll numbers:\n";
        for (int i = 0; i < 10; i++)
        {
            cin >> rno[i];
        }
    }

    void display()
    {
        cout << "\nRoll numbers are:\n";
        for (int i = 0; i < 10; i++)
        {
            cout << rno[i] << "\t";
        }
        cout << endl;
    }

    ~DMA()
    {
        cout << "\nDestructor called and Object memory is released.\n";
        delete[] rno;
        cout << "Array memory released.\n";
    }
};

int main()
{

    DMA *d = new DMA();

    d->display();

    delete d;

    return 0;
}