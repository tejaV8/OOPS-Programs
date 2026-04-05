#include <iostream>
using namespace std;

int main() {
    int seats;
    
    while(1){
        cout<<"Enetr number of seats to book: ";
        cin>> seats;
        try {
            if(seats > 4){
                throw 1;
            }
            cout<<"Booking successful for "<< seats <<"seats."<<endl;
            break;
        }
        catch(int i){
            cout<<"Cannot book more than 4 seats. Please try again."<<endl;
        }
    }
    return 0;
}