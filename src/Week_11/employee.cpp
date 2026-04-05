#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
fstream fp;

class Employee
{
public:
    int eid, exp;
    float sal;
    char ename[50], desig[50];
    void addEmployee()
    {
        cout << "Enter Employee ID: ";
        cin >> eid;
        cout << "Enter Employee Name: ";
        cin >> ename;
        cout << "Enter Employee Designation: ";
        cin >> desig;
        cout << "Enter Employee Experience: ";
        cin >> exp;
        cout << "Enter Employee Salary: ";
        cin >> sal;
    }
    void display()
    {
        cout << eid << "\t" << ename << "\t" << desig << "\t" << exp << "\t" << sal << endl;
    }
};

void appraisal();

int main()
{
    fp.open("C:/Users/Win 11/Documents/OOPS-Programs/src/Week_11/emp.dat", ios::out | ios::binary | ios::app);
    if (!fp.is_open())
    {
        cout << "Unable to open file." << endl;
        return 1;
    }
    Employee emp;
    char choice;
    do
    {
        emp.addEmployee();
        fp.write((char *)&emp, sizeof(emp));
        cout << "Do you want to add another employee? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    fp.close();
    appraisal();
    return 0;
}

void appraisal()
{
    Employee emp;
    fp.open("C:/Users/Win 11/Documents/OOPS-Programs/src/Week_11/emp.dat", ios::in | ios::binary);
    if (!fp.is_open())
    {
        cout << "Unable to open file." << endl;
        return;
    }
    cout << "ID\tName\tDesignation\tExperience\tSalary" << endl;
    cout << "-------------------------------------------------------------" << endl;
    while (fp.read((char *)&emp, sizeof(emp)))
    {
        if (emp.exp > 15)
        {
            strcpy(emp.desig, "Manager");
            emp.sal += emp.sal * 0.20;
        }
        else if (emp.exp > 10)
        {
            strcpy(emp.desig, "Senior architect");
            emp.sal += emp.sal * 0.10;
        }
        emp.display();
    }
    fp.close();

}