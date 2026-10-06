#include<iostream>
using namespace std;

class Employee{
    protected:
    string name;
    double salary;

    public:

    Employee(string name, double salary){
        this->name=name;
        this->salary=salary;
    }

    string getName(){
        return name;
    }

};

class Manager:public Employee{
    private:    
    double bonus;

    public:
    Manager(string name, double salary, double bonus):Employee(name, salary){
        this->bonus=bonus;
    }

    double getTotalSalary(){
        return salary+bonus;
    }
};

int main(){
    Manager m("swapnil",50000,5000);
    cout<<"Name: "<<m.getName()<<endl;
    cout<<"total salary: "<<m.getTotalSalary();
    return 0;
}