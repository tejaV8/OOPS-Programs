#include<iostream>
using namespace std;

class Inline{

    int x, y ,z;
        
public:
    
        Inline(){
            cout<<"Enter x, y and z values: ";
            cin>>x>>y>>z;
        }
        
        inline void sum(){
            cout<<"Sum = "<<x+y+z<<endl;
        }
        
        inline void avg(){
            cout<<"Average = "<<(x+y+z)/3<<endl;
        }
};

int main()
{
   Inline D1;
   
   D1.sum();
   D1.avg();
   
   return 0;
}