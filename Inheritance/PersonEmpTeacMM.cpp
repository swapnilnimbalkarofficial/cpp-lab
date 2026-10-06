#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    void getPersonInfo() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
    }

    void displayPersonInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Employee {
protected:
    int empId;
    float salary;

public:
    void getEmployeeInfo() {
        cout << "Enter Employee ID: ";
        cin >> empId;
        cout << "Enter Salary: ";
        cin >> salary;
    }

    void displayEmployeeInfo() {
        cout << "Employee ID: " << empId << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Teacher : public Person, public Employee {
public:
    void getData() {
        getPersonInfo();
        getEmployeeInfo();
    }

    void display() {
        displayPersonInfo();
        displayEmployeeInfo();
    }
};

int main() {
    Teacher t;

    t.getData();

    cout << endl;
    cout << "Teacher Information" << endl;
    t.display();

    return 0;
}