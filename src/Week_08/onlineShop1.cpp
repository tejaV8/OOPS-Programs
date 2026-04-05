#include <iostream>
using namespace std;

class product
{
protected:
    int pid;
    string pname;
    float price;

public:
    void getProduct()
    {
        cout << "Enter product id: ";
        cin >> pid;
        cout << "Enter product name: ";
        cin >> pname;
        cout << "Enter product price: ";
        cin >> price;
    }
    void showProduct()
    {
        cout << "Product id: " << pid << endl;
        cout << "Product name: " << pname << endl;
        cout << "Product price: " << price << endl;
    }
};

class Item1 : public product
{
    int quantity;

public:
    void getItem()
    {
        getProduct();
        cout << "Enter Quantity: ";
        cin >> quantity;
    }
    float calculateTotal()
    {
        return quantity * price;
    }
    void showItem()
    {
        showProduct();
        cout << "Quantity: " << quantity << endl;
        cout << "Total Price: " << calculateTotal() << endl;
    }
};

class BillPayment : public Item1
{
    float total;

public:
    void generateBill()
    {
        total = calculateTotal();
        cout << "\n---BILL PAYMENT---\n";
        showItem();
        cout << "Total Bill: " << total << endl;
    }
};

int main()
{
    BillPayment bill;
    bill.getItem();
    bill.generateBill();
    return 0;
}