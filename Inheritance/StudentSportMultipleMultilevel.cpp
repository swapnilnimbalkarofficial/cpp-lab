#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
    string name;
    int rollNo;

public:
    void getStudentInfo() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Roll No: ";
        cin >> rollNo;
    }

    void displayStudentInfo() {
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollNo << endl;
    }
};

class Sports {
protected:
    int sportsMarks;

public:
    void getSportsInfo() {
        cout << "Enter Sports Marks: ";
        cin >> sportsMarks;
    }

    void displaySportsInfo() {
        cout << "Sports Marks: " << sportsMarks << endl;
    }
};

class Result : public Student, public Sports {
    int academicMarks;
    int total;

public:
    void getData() {
        getStudentInfo();
        cout << "Enter Academic Marks: ";
        cin >> academicMarks;
        getSportsInfo();
    }

    void calculateTotal() {
        total = academicMarks + sportsMarks;
    }

    void display() {
        displayStudentInfo();
        cout << "Academic Marks: " << academicMarks << endl;
        displaySportsInfo();
        cout << "Total Marks: " << total << endl;
    }
};

int main() {
    Result r;

    r.getData();
    r.calculateTotal();

    cout << endl;
    cout << "Result" << endl;
    r.display();

    return 0;
}