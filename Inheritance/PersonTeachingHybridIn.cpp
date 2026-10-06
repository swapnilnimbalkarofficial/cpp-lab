#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    void getPersonInfo() {
        cout << "Name: ";
        cin >> name;
        cout << "Age: ";
        cin >> age;
    }

    void displayPersonInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Student : virtual public Person {
protected:
    int rollNo;

public:
    void getStudentInfo() {
        cout << "Roll No: ";
        cin >> rollNo;
    }

    void displayStudentInfo() {
        cout << "Roll No: " << rollNo << endl;
    }
};

class Employee : virtual public Person {
protected:
    string employeeId;

public:
    void getEmployeeInfo() {
        cout << "Employee ID: ";
        cin >> employeeId;
    }

    void displayEmployeeInfo() {
        cout << "Employee ID: " << employeeId << endl;
    }
};

class TeachingAssistant : public Student, public Employee {
public:
    void getData() {
        getPersonInfo();
        getStudentInfo();
        getEmployeeInfo();
    }

    void display() {
        displayPersonInfo();
        displayStudentInfo();
        displayEmployeeInfo();
    }
};

int main() {
    TeachingAssistant ta;

    cout << "Enter Teaching Assistant details" << endl;
    ta.getData();

    cout << endl;
    cout << "Teaching Assistant Information" << endl;
    ta.display();

    return 0;
}