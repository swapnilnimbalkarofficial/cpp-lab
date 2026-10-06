#include<iostream>
using namespace std;

class Employee{
    protected:
    int empId;
    string name;
    public:
    Employee(int eid, string name){
        this->empId=eid;
        this->name=name;
    }
};

class Salary{
    protected:
    float basicSalary;
    float allowances;
    public :
    Salary(float bs, float allow){
        this->basicSalary=bs;
        this->allowances=allow;
    }

};

class Payroll : public Employee, public Salary{
private:
    float deductions;
    float netSalary;

public:
    Payroll(int id, string name, float basic, float allowance, float deduction): Employee(id, name), Salary(basic, allowance){
        this->deductions = deduction;
    }

    float calculateNetSalary(){
        float grossSalary = basicSalary + allowances;
        netSalary = grossSalary - deductions;

        return netSalary;
    }

    void display(){
        cout << "\nEmployee ID = " << empId;
        cout << "\nName = " << name;
        cout << "\nBasic Salary = " << basicSalary;
        cout << "\nAllowances = " << allowances;
        cout << "\nDeductions = " << deductions;
        cout << "\nNet Salary = " << netSalary;
    }
};

int main(){
    Payroll p(101, "Priya", 30000, 5000, 3000);
    p.calculateNetSalary();
    p.display();

    return 0;
};
