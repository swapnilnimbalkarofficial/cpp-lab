#include <iostream>
using namespace std;

class PersonalInfo{
protected:
    string name;
    int age;

public:
    PersonalInfo(string name, int age){
        this->name = name;
        this->age = age;
    }
};

class AcademicInfo{
protected:
    int rollNo;
    float marks;

public:
    AcademicInfo(int rollNo, float marks){
        this->rollNo = rollNo;
        this->marks = marks;
    }
};

class Student : public PersonalInfo, public AcademicInfo{
private:
    float totalMarks;
    float percentage;

public:
    Student(string name, int age, int rollNo, float marks, float total): PersonalInfo(name, age), AcademicInfo(rollNo, marks){
        this->totalMarks = total;
    }

    float calculatePercentage() {
        percentage = marks / totalMarks * 100;
        return percentage;
    }

    void display(){
        cout << "\nName = " << name;
        cout << "\nAge = " << age;
        cout << "\nRoll No = " << rollNo;
        cout << "\nMarks = " << marks;
        cout << "\nTotal Marks = " << totalMarks;
        cout << "\nPercentage = " << percentage << "%";
    }
};

int main(){
    Student s("Priya", 20, 25, 450, 500);
    s.calculatePercentage();
    s.display();
    return 0;
}