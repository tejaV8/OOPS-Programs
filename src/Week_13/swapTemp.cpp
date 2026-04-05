#include<iostream>
using namespace std;

template<class t>

void swapNums(t &a, t &b){
    t temp;
    temp = a;
    a = b;
    b = temp;
}

int main(){
    int x = 10, y = 20;
    float a = 1.5, b = 2.5;

    cout<<"Before swapping: "<<endl;
    cout<<"x: "<<x<<" y: "<<y<<endl;
    cout<<"a: "<<a<<" b: "<<b<<endl;

    swapNums(x, y);
    swapNums(a, b);

    cout<<"After swapping: "<<endl;
    cout<<"x: "<<x<<" y: "<<y<<endl;
    cout<<"a: "<<a<<" b: "<<b<<endl;

    return 0;
}