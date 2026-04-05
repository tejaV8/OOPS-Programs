#include <iostream>
using namespace std;

class Inventory
{
    int stock_no;
    int quantity;
    float price;

public:
    friend istream& operator>>(istream &in, Inventory &i)
    {
        cout << "Enter Stock Number: ";
        in >> i.stock_no;

        if(i.stock_no < 0 || i.stock_no > 999)
            throw "Invalid Stock Number!";

        cout << "Enter Quantity: ";
        in >> i.quantity;

        if(i.quantity < 0)
            throw "Invalid Quantity!";

        cout << "Enter Price: ";
        in >> i.price;

        if(i.price > 10000)
            throw "Price exceeds limit!";

        return in;
    }

    friend ostream& operator<<(ostream &out, Inventory &i)
    {
        out << "\nStock Number: " << i.stock_no;
        out << "\nQuantity: " << i.quantity;
        out << "\nPrice: " << i.price << endl;

        return out;
    }
};

int main()
{
    Inventory item;

    try
    {
        cin >> item;
        cout << item;
    }
    catch(const char* msg)
    {
        cout << "Error: " << msg << endl;
    }

    return 0;
}