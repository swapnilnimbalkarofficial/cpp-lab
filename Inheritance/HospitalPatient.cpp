#include <iostream>
using namespace std;

class Patient{
protected:
    string patientName;
    int age;
    int patientId;

public:
    Patient(string name, int age, int id){
        this->patientName = name;
        this->age = age;
        this->patientId = id;
    }
};

class InPatient : public Patient{
private:
    float roomCharges;
    int numberOfDays;
    float totalBill;

public:

    InPatient(string name, int age, int id, float charges, int days):Patient(name, age, id){
        this->roomCharges = charges;
        this->numberOfDays = days;
    }

    float calculateBill(){
        totalBill = roomCharges * numberOfDays;
        return totalBill;
    }

    void display(){
        cout << "\nPatient ID = " << patientId;
        cout << "\nPatient Name = " << patientName;
        cout << "\nAge = " << age;
        cout << "\nRoom Charges = " << roomCharges;
        cout << "\nNumber of Days = " << numberOfDays;
        cout << "\nTotal Hospital Bill = " << totalBill;
    }
};

int main()
{
    InPatient p("Swapnil", 25, 101, 3000, 5);
    p.calculateBill();
    p.display();
    return 0;
}