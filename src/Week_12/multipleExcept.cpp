#include <iostream>
using namespace std;
int main(){
    double x;
    try{
        cout<<"Enter a value: ";
        cin>>x;
        if(x == 1){
            throw 1;
        }
        if(x == 'c')
            throw 'c';
        if(x == 1.5)
        throw 1.5;
        cout<<"No exception occured."<<endl;
    }
    catch(int i){
        cout<<"Integer exception: "<<i<<endl;
    }
    catch(char c){
        cout<<"Character exception: "<<c<<endl;
    }
    catch(double d){
        cout<<"Double exception: "<<d<<endl;
    }
    catch(...){
        cout<<"Unknown exception occurred."<<endl;
    }
}