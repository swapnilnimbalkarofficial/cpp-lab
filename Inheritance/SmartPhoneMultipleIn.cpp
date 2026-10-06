#include <iostream>
#include <string>
using namespace std;

class Phone {
protected:
    string brand;
    string model;
    string phoneNumber;

public:
    void getPhoneInfo() {
        cout << "Brand: ";
        cin >> brand;
        cout << "Model: ";
        cin >> model;
        cout << "Phone Number: ";
        cin >> phoneNumber;
    }

    void displayPhoneInfo() {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Phone Number: " << phoneNumber << endl;
    }
};

class Camera {
protected:
    int resolution;
    int lenses;

public:
    void getCameraInfo() {
        cout << "Camera Resolution (in MP): ";
        cin >> resolution;
        cout << "Number of Lenses: ";
        cin >> lenses;
    }

    void displayCameraInfo() {
        cout << "Camera Resolution: " << resolution << " MP" << endl;
        cout << "Number of Lenses: " << lenses << endl;
    }
};

class Smartphone : public Phone, public Camera {
public:
    void getData() {
        getPhoneInfo();
        getCameraInfo();
    }

    void display() {
        displayPhoneInfo();
        displayCameraInfo();
    }
};

int main() {
    Smartphone s;

    cout << "Enter smartphone details" << endl;
    s.getData();

    cout << endl;
    cout << "Smartphone Specifications" << endl;
    s.display();

    return 0;
}