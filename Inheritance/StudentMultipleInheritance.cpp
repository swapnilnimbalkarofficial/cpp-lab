#include <iostream>
#include <string>
using namespace std;

class PersonalInfo {
protected:
    string name;
    int age;

public:
    void getPersonalInfo() {
        cout << "Name: ";
        cin >> name;
        cout << "Age: ";
        cin >> age;
    }

    void displayPersonalInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class AcademicInfo {
protected:
    int rollNo;
    int marks;
    int totalMarks;

public:
    void getAcademicInfo() {
        cout << "Roll No: ";
        cin >> rollNo;
        cout << "Marks: ";
        cin >> marks;
        cout << "Total Marks: ";
        cin >> totalMarks;
    }

    void displayAcademicInfo() {
        cout << "Roll No: " << rollNo << endl;
        cout << "Marks: " << marks << "/" << totalMarks << endl;
    }
};

class Student : public PersonalInfo, public AcademicInfo {
    float percentage;

public:
    void getData() {
        getPersonalInfo();
        getAcademicInfo();
    }

    void calculatePercentage() {
        percentage = (float)marks / totalMarks * 100;
    }

    void display() {
        displayPersonalInfo();
        displayAcademicInfo();
        cout << "Percentage: " << percentage << "%" << endl;
    }
};

int main() {
    Student s;

    cout << "Enter student details" << endl;
    s.getData();
    s.calculatePercentage();

    cout << endl;
    cout << "Student Information" << endl;
    s.display();

    return 0;
}