#include <iostream>
using namespace std;

class Complex
{
    int real, imag;

public:
    Complex()
    {
        real = 0;
        imag = 0;
    }

    Complex(int real, int imag)
    {
        this->real = real;
        this->imag = imag;
    }

    void show()
    {
        cout << real << " + " << imag << "i";
    }

    friend Complex operator+(Complex &C1, Complex &C2);
};

Complex operator+(Complex &C1, Complex &C2)
{
    Complex C3;
    C3.real = C1.real + C2.real;
    C3.imag = C1.imag + C2.imag;
    return C3;
}

int main()
{
    Complex C1(5, 10);
    Complex C2(3, 5), C3;

    cout << "C1 = ";
    C1.show();
    cout << endl;

    cout << "C2 = ";
    C2.show();
    cout << endl;

    C3 = C1 + C2;

    cout << "\nC1 + C2 = ";
    C3.show();
    cout << endl;

    return 0;
}
