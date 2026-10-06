#include <iostream>
#include <string>
using namespace std;

class Student {
    int rollNo;
    string name;
    int marks1, marks2, marks3;
    int total;
    float percentage;
    static int count;

public:
    Student(int r, string n, int m1, int m2, int m3) {
        rollNo = r;
        name = n;
        marks1 = m1;
        marks2 = m2;
        marks3 = m3;
        total = marks1 + marks2 + marks3;
        percentage = total / 3.0;
        count++;
    }

    ~Student() {
        cout << "Student object destroyed: " << name << endl;
    }

    void display() {
        cout << rollNo << "\t" << name << "\t" << marks1 << "\t"
             << marks2 << "\t" << marks3 << "\t" << total << "\t"
             << percentage << "%" << endl;
    }

    float getPercentage() {
        return percentage;
    }

    static void displayCount() {
        cout << "Total number of students = " << count << endl;
    }
};

int Student::count = 0;

int main() {
    Student s[5] = {
        Student(1, "Amit", 78, 85, 90),
        Student(2, "Sneha", 92, 88, 95),
        Student(3, "Rahul", 65, 70, 72),
        Student(4, "Priya", 80, 76, 84),
        Student(5, "Karan", 55, 60, 68)
    };

    cout << "Roll\tName\tM1\tM2\tM3\tTotal\tPercentage" << endl;
    cout << "------------------------------------------------------" << endl;
    for (int i = 0; i < 5; i++) {
        s[i].display();
    }
    cout << endl;

    Student::displayCount();
    cout << endl;

    int topIndex = 0;
    for (int i = 1; i < 5; i++) {
        if (s[i].getPercentage() > s[topIndex].getPercentage()) {
            topIndex = i;
        }
    }

    cout << "Student with highest percentage :" << endl;
    s[topIndex].display();
    cout << endl;

    return 0;
}