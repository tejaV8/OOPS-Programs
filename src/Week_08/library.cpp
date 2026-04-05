#include <iostream>
#include <string>
using namespace std;

class Book
{
protected:
    string bookName, author;
    int bookId;

public:
    void getBook()
    {
        cout << "Enter book name: ";
        cin >> bookName;

        cout << "Enter author name: ";
        cin >> author;

        cout << "Enter book ID: ";
        cin >> bookId;
    }
};

class Member
{
protected:
    string memberName;
    int memberId;

public:
    void getMember()
    {
        cout << "Enter member name: ";
        cin >> memberName;

        cout << "Enter member ID: ";
        cin >> memberId;
    }
};

class Library : public Book, public Member
{
    int days;
    float fine;

public:
    void getIssueDetails()
    {
        cout << "Enter number of days: ";
        cin >> days;

        if(days > 7)
            fine = (days - 7) * 5;
        else
            fine = 0;
    }

    void display()
    {
        cout << bookId << "\t"
             << bookName << "\t"
             << author << "\t"
             << memberId << "\t"
             << memberName << "\t"
             << days << "\t"
             << fine << endl;
    }
};

int main()
{
    int n;

    cout << "Enter number of entries: ";
    cin >> n;

    Library l[n];

    for(int i = 0; i < n; i++)
    {
        cout << "\nEntry " << i+1 << endl;

        l[i].getBook();
        l[i].getMember();
        l[i].getIssueDetails();
    }

    cout << "\nBookID\tBookName\tAuthor\tMemberID\tMemberName\tDays\tFine\n";

    cout<<"Library Records:\n";
    for(int i = 0; i < n; i++)
    {
        l[i].display();
    }

    return 0;
}