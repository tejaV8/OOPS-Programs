#include <iostream>
using namespace std;

class Investment {
     double initialValue;
     double currentValue;
     double profit;
     double percentProfit;
public:
    Investment(double iv, double cv){
        initialValue = iv;
        currentValue = cv;
        profit = currentValue - initialValue;
        percentProfit = profit/initialValue * 100;
    }

    void displayInvestment(){
        cout<<initialValue<<"\t"<<currentValue<<"\t"<<profit<<"\t"<<percentProfit;
    }
};

class House
{
protected:
    string address;
    int squareFeet;
public:
    House(string a, int s){
        address = a;
        squareFeet = s;
    }

    void displayHouse(){
        cout<<address<<"\t"<<squareFeet<<endl;
    }
};

class HouseInvestment : public Investment, public House {
public: 
    HouseInvestment(double iv, double cv, string a, int s) : Investment(iv, cv), House(a, s) {
    }

    void displayHouseInvestment(){
        displayInvestment();
        displayHouse();
    }
};

int main() {
     HouseInvestment hi(5000000, 6500000, "123 Main St", 24000);
     cout<<"InitialValue\tCurrentValue\tProfit\tPercentProfit\tAddress\tSquareFeet"<<endl;
     hi.displayHouseInvestment();
    return 0;
}