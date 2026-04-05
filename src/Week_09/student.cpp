#include <iostream>
using namespace std;

class Student
{
protected:
    int rollNo;
    string name;

public:
    void getDetails()
    {
        cout << "Enter Roll No: ";
        cin >> rollNo;
        cout << "Enter Name: ";
        cin >> name;
    }
};

class Course : virtual public Student
{
protected:
    int cid;
    float cfee;

public:
    void getCourseDetails()
    {
        cout << "Enter Course ID: ";
        cin >> cid;
        cout << "Enter Course Fee: ";
        cin >> cfee;
    }
};

class Transport : virtual public Student
{
protected:
    int tid;
    float tfee;

public:
    void getTransportDetails()
    {
        cout << "Enter Transport ID: ";
        cin >> tid;
        cout << "Enter Transport Fee: ";
        cin >> tfee;
    }
};

class Account : public Course, public Transport
{
    int accNo;
    float totalFee;

public:
    void calculateTotalFee()
    {
        cout<<"Enter Account No: ";
        cin>>accNo;
        getDetails();
        getCourseDetails();
        getTransportDetails();
        totalFee = cfee + tfee;
    }
    void display()
    {
        cout << accNo << "\t" << rollNo << "\t" << name << "\t" << totalFee << endl;
    }
};

int main()
{
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    Account *students = new Account[n];
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter details for student " << (i + 1) << ":\n";
        students[i].calculateTotalFee();
    }
    cout << "\nStudent Details:\n";
    cout << "AccNo\tRollNo\tName\tTotalFee\n";
    for (int i = 0; i < n; i++)
    {
        students[i].display();
    }
    return 0;
}