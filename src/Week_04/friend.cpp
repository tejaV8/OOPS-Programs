#include <iostream>
using namespace std;

class account2;

class account1
{
    int acno, cid, bal;

public:
    account1(int acno, int cid, int bal)
    {
        this->acno = acno;
        this->cid = cid;
        this->bal = bal;
    }

    void display()
    {
        cout << acno << "\t" << cid << "\t" << bal << endl;
    }

    friend void transfer(account1 &, account2 &, int);
};

class account2
{
    int acno, cid, bal;

public:
    account2(int acno, int cid, int bal)
    {
        this->acno = acno;
        this->cid = cid;
        this->bal = bal;
    }

    void display()
    {
        cout << acno << "\t" << cid << "\t" << bal << endl;
    }

    friend void transfer(account1 &a1, account2 &a2, int amt);
};

void transfer(account1 &a1, account2 &a2, int amt)
{
    int ch;

    cout << "\nEnter 1 to transfer from Account1 to Account2\n";
    cout << "Enter 2 to transfer from Account2 to Account1\n";
    cout << "Enter your choice : ";
    cin >> ch;

    switch (ch)
    {
    case 1:
        if (a1.bal >= amt)
        {
            a1.bal -= amt;
            a2.bal += amt;
            cout << "\nTransfer Successful!\n";
        }
        else
            cout << "\nInsufficient balance in Account1\n";
        break;

    case 2:
        if (a2.bal >= amt)
        {
            a2.bal -= amt;
            a1.bal += amt;
            cout << "\nTransfer Successful!\n";
        }
        else
            cout << "\nInsufficient balance in Account2\n";
        break;

    default:
        cout << "\nInvalid transfer choice\n";
    }
}

int main()
{
    int acno1, cid1, bal1;
    int acno2, cid2, bal2;

    cout << "Enter Account 1 (acno cid bal): ";
    cin >> acno1 >> cid1 >> bal1;

    cout << "Enter Account 2 (acno cid bal): ";
    cin >> acno2 >> cid2 >> bal2;

    account1 a1(acno1, cid1, bal1);
    account2 a2(acno2, cid2, bal2);

    int ch, amt;

    cout << "\n1. Transfer Amount\n";
    cout << "2. Display Accounts\n";
    cout << "3. Exit";

    do
    {
        cout << "\nEnter your choice : ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter amount: ";
            cin >> amt;
            transfer(a1, a2, amt);
            break;

        case 2:
            cout << "\nACNO\tCID\tBalance\n";
            a1.display();
            a2.display();
            break;

        case 3:
            cout << "\nExiting...\n";
            break;

        default:
            cout << "\nInvalid menu choice\n";
        }

    } while (ch != 3);

    return 0;
}