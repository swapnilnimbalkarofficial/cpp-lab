#include <iostream>
using namespace std;

class BankAccount{
    protected:
    int account_no;
    string name;
    double balance;

    public:

    BankAccount(int accout_no,string name, double balance){
        this->account_no=account_no;
        this->balance=balance;
        this->name=name;
    }
};

class SavingsAccount:public BankAccount{
    private:
    int interestRate;

    public:
    SavingsAccount(int account_no, string name, double balance, int interestRate)
    : BankAccount(account_no, name, balance)
    {
        this->interestRate = interestRate;
    }

    int calculateInterest(){
        return balance*interestRate/100;
    }

    double updatedBalance(){
        return balance+calculateInterest();
    }
};

int main(){
    SavingsAccount s(4111,"Swapnil",34000,5);
     cout << "Interest: " << s.calculateInterest() << endl;
    cout << "Updated Balance: " << s.updatedBalance() << endl;
}