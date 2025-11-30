#include <iostream>
using namespace std;

class AddNum {
    int a, b, sum;

public:

    AddNum() {
        cout << "\nDefault constructor is invoked.";
        cout << "\nEnter two numbers: ";
        cin >> a >> b;
        sum = a + b;
    }


    AddNum(int x, int y) {
        cout << "\nParameterized constructor is invoked.\n";
        a = x;
        b = y;
        sum = a + b;
    }


    void show() {
        cout << "Sum = " << sum << endl;
    }


    ~AddNum() {
        cout << "\nDestructor is invoked.";
    }
};

int main() {
    AddNum obj1;
    obj1.show();

    AddNum obj2(5, 10);
    obj2.show();

    return 0;
}