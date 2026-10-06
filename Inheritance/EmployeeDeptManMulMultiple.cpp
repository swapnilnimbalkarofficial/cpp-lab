#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string empName;
    int empId;

public:
    void getEmployeeInfo() {
        cout << "Enter Employee Name: ";
        cin >> empName;
        cout << "Enter Employee ID: ";
        cin >> empId;
    }

    void displayEmployeeInfo() {
        cout << "Employee Name: " << empName << endl;
        cout << "Employee ID: " << empId << endl;
    }
};

class Department {
protected:
    string deptName;

public:
    void getDepartmentInfo() {
        cout << "Enter Department Name: ";
        cin >> deptName;
    }

    void displayDepartmentInfo() {
        cout << "Department Name: " << deptName << endl;
    }
};

class Manager : public Employee, public Department {
public:
    void getData() {
        getEmployeeInfo();
        getDepartmentInfo();
    }

    void display() {
        displayEmployeeInfo();
        displayDepartmentInfo();
    }
};

int main() {
    Manager m;

    m.getData();

    cout << endl;
    cout << "Manager Information" << endl;
    m.display();

    return 0;
}