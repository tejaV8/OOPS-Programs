#include <iostream>
#include <string>
using namespace std;

class Student
{
    string sname;
    int sid, age;
    static string clgname;

public:
    void setValues();
    void profile();
};

string Student::clgname = "SRIIT";

void Student::setValues()
{
    cin.ignore();
    cout << "Enter student name: ";
    getline(cin, sname);
    cout << "Enter ID: ";
    cin >> sid;
    cout << "Enter age: ";
    cin >> age;
}

void Student::profile()
{
    cout << sname << "\t" << sid << "\t" << age << "\t" << clgname << endl;
}

int main()
{
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student s[n];

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter details of student " << i + 1 << endl;
        s[i].setValues();
    }

    cout << "\nName\tID\tAge\tCollege\n";
    for (int i = 0; i < n; i++)
        s[i].profile();

    return 0;
}