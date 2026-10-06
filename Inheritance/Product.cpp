#include <iostream>
using namespace std;

class Product {
protected:
    int productId;
    string name;
    float price;

public:
    Product(int id, string n, float p) {
        productId = id;
        name = n;
        price = p;
    }
};

class ElectronicProduct : public Product {
private:
    int warrantyPeriod;
    float gstPercentage;
    float gstAmount;
    float finalPrice;

public:
    ElectronicProduct(int id, string n, float p, int warrenty, float gst):Product(id,n,p){
        this->warrantyPeriod=warrantyPeriod;
        this->gstPercentage=gstPercentage;
        this->gstAmount=gstAmount;
        this->finalPrice=finalPrice;
    }
    
    float calculateGst(){
        gstAmount = price * gstPercentage / 100;
        return gstAmount;
    }

    float calculateFinalPrice(){
        finalPrice = price + calculateGst();
        return finalPrice;
    }

     void display(){
        cout << "\nProduct ID = " << productId;
        cout << "\nName = " << name;
        cout << "\nPrice = " << price;
        cout << "\nWarranty Period = " << warrantyPeriod;
        cout << "\nGST Percentage = " << gstPercentage << "%";
        cout << "\nGST Amount = " << gstAmount;
        cout << "\nFinal Price = " << finalPrice;
    }
};
int main(){
ElectronicProduct e(101, "Laptop", 575039, 2, 18);

    e.calculateGst();
    e.calculateFinalPrice();
    e.display();

    return 0;
}