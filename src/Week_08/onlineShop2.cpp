#include<iostream>
using namespace std;

class Product
{
protected:
    int id;
    string pname;
    float price;

public:
    void getProduct()
    {
        cout<<"Enter Product ID: ";
        cin>>id;

        cout<<"Enter Product Name: ";
        cin>>pname;

        cout<<"Enter Product Price: ";
        cin>>price;
    }

    void showProduct()
    {
        cout<<"Product ID: "<<id<<endl;
        cout<<"Product Name: "<<pname<<endl;
        cout<<"Product Price: "<<price<<endl;
    }
};

class Item1 : public Product
{
protected:
    int q1;

public:
    void getItem1()
    {
        cout<<"Enter Quantity of Item1: ";
        cin>>q1;
    }

    float total1()
    {
        return price * q1;
    }
};

class Item2 : public Product
{
protected:
    int q2;

public:
    void getItem2()
    {
        cout<<"Enter Quantity of Item2: ";
        cin>>q2;
    }

    float total2()
    {
        return price * q2;
    }
};

class BillPayment : public Item1, public Item2
{
    float bill;

public:


    void displayBill()
    {
        bill = total1() + total2();
        cout<<"\n--- BILL DETAILS ---\n";

        cout<<"\nItem1 Details\n";
        Item1::showProduct();
        cout<<"Quantity: "<<q1<<endl;
        cout<<"Amount: "<<total1()<<endl;

        cout<<"\nItem2 Details\n";
        Item2::showProduct();
        cout<<"Quantity: "<<q2<<endl;
        cout<<"Amount: "<<total2()<<endl;

        cout<<"\nTotal Bill Amount = "<<bill<<endl;
    }
};

int main()
{
    BillPayment b;

    cout<<"Enter details for Item1\n";
    b.Item1::getProduct();
    b.getItem1();

    cout<<"\nEnter details for Item2\n";
    b.Item2::getProduct();
    b.getItem2();
    
    b.displayBill();

    return 0;
}