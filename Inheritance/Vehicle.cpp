#include <iostream>
#include <iomanip>
using namespace std;

class Vehicle{

    protected:
    string brand;
    string model;
    double price;

    public:
    Vehicle(string brand, string model, double price){
        this->brand=brand;
        this->model=model;
        this->price=price;
    }
};

class Car:public Vehicle{
    private:
    int no_doors;
    string fuel_type;

    public:

    Car(string brand, string model, double price, int no_doors, string fuel_type):Vehicle(brand, model, price){
        this->no_doors=no_doors;
        this->fuel_type=fuel_type;
    }

    void displayDetails(){
        cout<<"\nBrand: "<<brand;
        cout<<"\nModel: "<<model;
        cout<<"\nPrice: "<<price;
        cout<<"\nno_doors: "<<no_doors;
        cout<<"\nfuel_type: "<<fuel_type;
    }

    double calculateFinalPrice(){
        double discountAmount=price*discountAmount/100;
        return price-discountAmount;
    }

};

int main(){
    Car c("Toyota", "Fortuner", 4000000, 4, "Diesel");
    c.displayDetails();
    cout << "\nFinal Price: "
         << c.calculateFinalPrice();
    return 0;
}