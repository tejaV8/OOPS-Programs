#include <iostream>
using namespace std;

class RestaurantMeal
{
protected:
    string name;
    double price;
public:
    RestaurantMeal(string n, double p){
        name = n;
        price = p;
    }
    void displayMeal(){
        cout<< name <<"\t" << price;
    }
    double getPrice(){
        return price;
    }
};

class HotelService
{
    string serviceName;
    double serviceFee;
    int roomNo;
public:
    HotelService(string s, double f, int r){
        serviceName = s;
        serviceFee = f;
        roomNo = r;
    }
    void displayService(){
        cout <<" "<< serviceName << "\t" << serviceFee << "\t" << roomNo << "\t";
    }
    double getServiceFee(){
        return serviceFee;
    }
};

class RoomServiceMeal: public RestaurantMeal, public HotelService
{
public:
    RoomServiceMeal(string n, double p, string s, double f, int r) : RestaurantMeal(n, p), HotelService(s, f, r) {}
    void displayRoomServiceMeal(){
        displayMeal();
        displayService();
        cout << getPrice() + getServiceFee() << endl;
    }

};

int main() {
    RoomServiceMeal meal("Steak Dinner", 19.99, "Room Service", 4.00, 1202);
    cout<<"Meal\t price\t Service\t Service Fee\t Total Price\n";
    meal.displayRoomServiceMeal();
    return 0;
}