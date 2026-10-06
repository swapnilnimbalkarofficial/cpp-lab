#include <iostream>
using namespace std;

class Employee {
protected:
    int empid;
    string name;
    float salary;

public:
    Employee(int id, string n, float sal) {
        empid = id;
        name = n;
        salary = sal;
    }
};

class Manager : public Employee {
private:
    float bonusPercentage;
    float bonus;
    float totalSalary;

public:
    Manager(int id, string n, float sal, float bonusPer)
        : Employee(id, n, sal) {
        bonusPercentage = bonusPer;
        bonus = salary * bonusPercentage / 100;
        totalSalary = salary + bonus;
    }

    void display() {
        cout << "\nEmployee ID =" << empid;
        cout << "\nName = " << name;
        cout << "\nSalary = " << salary;
        cout << "\nBonus Percentage = " << bonusPercentage << "%";
        cout << "\nBonus = " << bonus;
        cout << "\nTotal Salary = " << totalSalary;
    }
};

int main() {
    Manager m(101, "ram", 67400, 5);
    m.display();
    return 0;
}