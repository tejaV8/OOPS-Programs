#include <iostream>
using namespace std;

class Person
{
protected:
    int age;
    string name;
public:
    void getPerson()
    {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
    }

};

class Student : public Person
{
protected:
    int rollNo;
    string course;
public:
    void getStudent()
    {
        getPerson();
        cout << "Enter roll number: ";
        cin >> rollNo;
        cout << "Enter course: ";
        cin >> course;
    }
};

class Grade : public Student
{
    float marks;
    char grade;
public:
    void getGrade(){
        cout<<"Enter marks: ";
        cin>>marks;
        if(marks>=90)
            grade='A';
        else if(marks>=80)
            grade='B';
        else if(marks>=70)
            grade='C';
        else if(marks>=60)
            grade='D';
        else
            grade='F';
    }
    void display(){
        cout<<rollNo<<"\t"<<name<<"\t"<<age<<"\t"<<course<<"\t"<<marks<<"\t"<<grade<<endl;
    }
};


int main() {
    int n;
    cout<<"Enter number of students: ";
    cin>>n;
    Grade students[n];
    for(int i=0;i<n;i++){
        cout<<"\nEnter details for student "<<i+1<<":\n";
        students[i].getStudent();
        students[i].getGrade();
    }
    cout<<"\nRollNo\tName\tAge\tCourse\tMarks\tGrade\n";
    for(int i=0;i<n;i++){
        students[i].display();
    }

    return 0;
}