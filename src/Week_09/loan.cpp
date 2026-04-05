#include <iostream>
using namespace std;

class Loan
{
protected:
    int loanAccNo;
    string branch;

public:
    Loan(int LoanAccNo, string branch)
    {
        this->loanAccNo = LoanAccNo;
        this->branch = branch;
    }
};

class VehicleLoan : public Loan
{
    int vehicleType;
    float amount;
    float interest;

public:
    VehicleLoan(int LoanAccNo, string branch, int vehicleType, float amount) : Loan(LoanAccNo, branch)
    {
        this->vehicleType = vehicleType;
        this->amount = amount;
        if (vehicleType == 0)
            interest = 10.5;
        else
            interest = 9.5;
        this->amount += (this->amount * interest / 100);
    }

    void display()
    {
        cout << "\nVehicle Loan Details:\n";
        cout << "Loan Account No: " << loanAccNo << endl;
        cout << "Branch: " << branch << endl;
        cout << "Vehicle Type: " << (vehicleType == 0 ? "Car" : "Bike") << endl;
        cout << "Interest: " << interest << "%\n";
        cout << "Total Amount to be Paid: " << amount << endl;
    }
};

class HomeLoan : public Loan
{
    int locality;
    float amount;
    float interest;

public:
    HomeLoan(int LoanAccNo, string branch, int locality, float amount) : Loan(LoanAccNo, branch)
    {
        this->locality = locality;
        this->amount = amount;
        if (locality == 0)
            interest = 10.5;
        else
            interest = 9.5;
        this->amount += (this->amount * interest / 100);
    }

    void display()
    {
        cout << "\nHome Loan Details:\n";
        cout << "Loan Account No: " << loanAccNo << endl;
        cout << "Branch: " << branch << endl;
        cout << "Locality: " << (locality == 0 ? "Urban" : "Rural") << endl;
        cout << "Interest: " << interest << "%\n";
        cout << "Total Amount to be Paid: " << amount << endl;
    }
};

int main()
{
    int loanType, loanAccNo, vehicleType, locality;
    float amount;
    string branch;
    cout << "Enter Loan Account No: ";
    cin >> loanAccNo; 
    cout << "Enter Branch: ";
    cin >> branch;
    cout << "Enter Loan Type (0 for Vehicle Loan, 1 for Home Loan): ";
    cin >> loanType;
    if (loanType == 0)
    {
        cout << "Enter Vehicle Type (0 for Car, 1 for Bike): ";
        cin >> vehicleType;
        cout << "Enter Amount: ";
        cin >> amount;
        VehicleLoan vLoan(loanAccNo, branch, vehicleType, amount);
        vLoan.display();
    }
    else
    {
        cout << "Enter Locality (0 for Urban, 1 for Rural): ";
        cin >> locality;
        cout << "Enter Amount: ";
        cin >> amount;
        HomeLoan hLoan(loanAccNo, branch, locality, amount);
        hLoan.display();
    }
    return 0;
}