#include <iostream>
using namespace std;

int main() {
    int nr, dr;
    cout<<"Enter numerator: ";
    cin>>nr;
    cout<<"Enter denominator: ";
    cin>>dr;
    try{
        if(dr == 0)
            throw runtime_error("Division by zero is not allowed.");
        cout<<"Result: "<<nr/dr<<endl;
    }
    catch(runtime_error& e){
        cout<<"Error: "<<e.what()<<endl;
    }
    return 0;
}