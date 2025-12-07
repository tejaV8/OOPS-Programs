#include <iostream>
#include <string>
using namespace std;

class Customer
{
    int acno, cid;
    string cname;

public:
    void set(int acno, int cid, string cname)
    {
        this->acno = acno;
        this->cid = cid;
        this->cname = cname;
    }

    void display()
    {
        cout << acno << "\t" << cid << "\t" << cname << endl;
    }
};

int main()
{
    int n;

    cout << "Enter number of customer: ";
    cin >> n;

    Customer C[n];

    int acno, cid;
    string cname;

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter details of customer " << i + 1 << ": " << endl;
        cout << "Enter account number: ";
        cin >> acno;

        cout << "Enter customer id: ";
        cin >> cid;

        cin.ignore();
        cout << "Enter Customer name: ";
        getline(cin, cname);

        C[i].set(acno, cid, cname);
    }

    cout << "\nAcc No.\tC ID\tC Name" << endl;

    for (int i = 0; i < n; i++)
    {
        C[i].display();
    }
    cout << endl;
    return 0;
}
