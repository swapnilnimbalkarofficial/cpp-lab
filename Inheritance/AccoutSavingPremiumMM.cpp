#include <iostream>
using namespace std;

class Account {
protected:
    int accountNo;
    float balance;

public:
    void getAccountInfo() {
        cout << "Enter Account Number: ";
        cin >> accountNo;
        cout << "Enter Balance: ";
        cin >> balance;
    }

    void displayAccountInfo() {
        cout << "Account Number: " << accountNo << endl;
        cout << "Balance: " << balance << endl;
    }
};

class SavingsAccount : public Account {
protected:
    float interestRate;

public:
    void getSavingsInfo() {
        cout << "Enter Interest Rate (%): ";
        cin >> interestRate;
    }

    void displaySavingsInfo() {
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

class PremiumAccount : public SavingsAccount {
    float minBalance;

public:
    void getData() {
        getAccountInfo();
        getSavingsInfo();
        cout << "Enter Minimum Balance: ";
        cin >> minBalance;
    }

    void display() {
        displayAccountInfo();
        displaySavingsInfo();
        cout << "Minimum Balance: " << minBalance << endl;
    }
};

int main() {
    PremiumAccount p;

    p.getData();

    cout << endl;
    cout << "Account Details" << endl;
    p.display();

    return 0;
}