#include <iostream>
#include <string>
using namespace std;

class equals
{
    int uid;
    string pwd;

public:
    equals()
    {
        uid = 0;
        pwd = "";
    }
    equals(int uid, string pwd)
    {
        this->uid = uid;
        this->pwd = pwd;
    }
    void show()
    {
        cout << "User ID: " << uid << endl;
        cout << "Password: " << pwd << endl;
    }
    bool operator==(const equals &u2)
    {
        return uid == u2.uid;
    }
};

int main()
{
    equals u1(456, "abcd");
    equals u2(450, "abcd123");
    if (u1 == u2)
    {
        cout << "UID already existing" << endl;
    }
    else
    {
        u1.show();
        u2.show();
    }
    return 0;
}