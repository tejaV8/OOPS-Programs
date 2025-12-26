#include <iostream>
using namespace std;

class Bank
{
public:
    virtual int returnBal() = 0;
    virtual void withdraw(int) = 0;
    virtual void deposit(int) = 0;
    virtual void showBal() = 0;
};

class Account : public Bank
{
protected:
    int bal;

public:
    Account(int bal)
    {
        this->bal = bal;
    }

    int returnBal()
    {
        return bal;
    }

    void showBal()
    {
        cout << "Current Balance: " << bal << endl;
    }

    void deposit(int amount) { bal += amount; }
    void withdraw(int amount)
    {
        if (amount <= bal)
            bal -= amount;
    }
};

class Transaction : public Bank
{
private:
    Account &acc;

public:
    Transaction(Account &a) : acc(a) {}

    void deposit(int amount)
    {
        acc.deposit(amount);
        cout << "Deposit Successful\n";
    }

    void withdraw(int amount)
    {
        if (amount <= acc.returnBal())
        {
            acc.withdraw(amount);
            cout << "Withdrawal Successful\n";
        }
        else
        {
            cout << "Insufficient Balance\n";
        }
    }

    int returnBal()
    {
        return acc.returnBal();
    }

    void showBal()
    {
        acc.showBal();
    }
};

int main()
{
    Account Cus(50000);
    Transaction T(Cus);

    Bank *ptr = &T;

    ptr->deposit(5000);
    ptr->showBal();

    ptr->withdraw(50000);
    ptr->showBal();

    return 0;
}