#include <iostream>
using namespace std;

class Employee
{
    int salary, exp;
    string ename, desig;

public:
    int eid;

    void setDetails()
    {
        cin.ignore();

        cout << "Enter employee name: ";
        getline(cin, ename);

        cout << "Enter employee ID: ";
        cin >> eid;
        cin.ignore();

        cout << "Enter designation: ";
        getline(cin, desig);

        cout << "Enter experience: ";
        cin >> exp;

        cout << "Enter salary: ";
        cin >> salary;
    }

    void setInr()
    {
        if (exp >= 20)
            salary += salary * 0.15;
        else if (exp >= 10)
            salary += salary * 0.10;
        else
            salary += salary * 0.05;
    }

    void profile()
    {
        cout << "\nEmployee ID: " << eid
             << "\tName: " << ename
             << "\tDesignation: " << desig
             << "\tExperience: " << exp
             << "\tUpdated Salary: " << salary << endl;
    }
};

int main()
{
    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    Employee e[n];

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter details of employee " << i + 1 << ": \n";
        e[i].setDetails();
    }

    for (int i = 0; i < n; i++)
        e[i].setInr();

    cout << "\n===== Employee Details =====\n";
    for (int i = 0; i < n; i++)
        e[i].profile();

    return 0;
}