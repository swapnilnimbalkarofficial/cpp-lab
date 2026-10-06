#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;

class Patient {
    int id;
    string name;
    int age;
    string disease;
    string doctor;
    float charges;

public:
    void inputDetails() {
        cout << "Enter Patient Name : ";
        cin >> name;
        cout << "Enter Age : ";
        cin >> age;
        cout << "Enter Disease : ";
        cin >> disease;
        cout << "Enter Doctor Name : ";
        cin >> doctor;
        cout << "Enter Hospital Charges : ";
        cin >> charges;
    }

    void input() {
        cout << "Enter Patient ID : ";
        cin >> id;
        inputDetails();
    }

    void display() {
        cout << id << "\t" << name << "\t" << age << "\t"
             << disease << "\t" << doctor << "\t" << charges << endl;
    }

    void writeToFile(ofstream &fout) {
        fout << id << " " 
        << name << " " 
        << age << " "
        << disease << " " 
        << doctor << " " 
        << charges << endl;
    }

    bool readFromFile(ifstream &fin) {
        if (fin >> id >> name >> age >> disease >> doctor >> charges) {
            return true;
        }
        return false;
    }

    int getId() {
        return id;
    }
};

void addPatient() {
    Patient p, old;
    p.input();

    ifstream fin("patients.txt");
    while (old.readFromFile(fin)) {
        if (old.getId() == p.getId()) {
            cout << "Patient ID already exists." << endl;
            fin.close();
            return;
        }
    }
    fin.close();

    ofstream fout("patients.txt", ios::app);
    p.writeToFile(fout);
    fout.close();
    cout << "Patient record added successfully." << endl;
}

void displayAll() {
    Patient p;
    bool found = false;

    ifstream fin("patients.txt");
    cout << "ID\tName\tAge\tDisease\tDoctor\tCharges" << endl;
    while (p.readFromFile(fin)) {
        p.display();
        found = true;
    }
    fin.close();

    if (found == false) {
        cout << "No patient records found." << endl;
    }
}

void searchPatient() {
    Patient p;
    int searchId;
    bool found = false;

    cout << "Enter Patient ID to search : ";
    cin >> searchId;

    ifstream fin("patients.txt");
    while (p.readFromFile(fin)) {
        if (p.getId() == searchId) {
            cout << "Patient found." << endl;
            p.display();
            found = true;
            break;
        }
    }
    fin.close();

    if (found == false) {
        cout << "Patient not found." << endl;
    }
}

void updatePatient() {
    Patient p;
    int searchId;
    bool found = false;

    cout << "Enter Patient ID to update : ";
    cin >> searchId;

    ifstream fin("patients.txt");
    ofstream fout("temp.txt");

    while (p.readFromFile(fin)) {
        if (p.getId() == searchId) {
            found = true;
            cout << "Enter new details :" << endl;
            p.inputDetails();
        }
        p.writeToFile(fout);
    }
    fin.close();
    fout.close();

    remove("patients.txt");
    rename("temp.txt", "patients.txt");

    if (found == true) {
        cout << "Patient record updated successfully." << endl;
    } else {
        cout << "Patient not found." << endl;
    }
}

void deletePatient() {
    Patient p;
    int searchId;
    bool found = false;

    cout << "Enter Patient ID to delete : ";
    cin >> searchId;

    ifstream fin("patients.txt");
    ofstream fout("temp.txt");

    while (p.readFromFile(fin)) {
        if (p.getId() == searchId) {
            found = true;
        } else {
            p.writeToFile(fout);
        }
    }
    fin.close();
    fout.close();

    remove("patients.txt");
    rename("temp.txt", "patients.txt");

    if (found == true) {
        cout << "Patient record deleted successfully." << endl;
    } else {
        cout << "Patient not found." << endl;
    }
}

int main() {
    int choice;

    do {
        cout << endl;
        cout << "===== HOSPITAL PATIENT MANAGEMENT SYSTEM =====" << endl;
        cout << "1. Add Patient" << endl;
        cout << "2. Display All Patients" << endl;
        cout << "3. Search Patient" << endl;
        cout << "4. Update Patient" << endl;
        cout << "5. Delete Patient" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice) {
            case 1: addPatient(); break;
            case 2: displayAll(); break;
            case 3: searchPatient(); break;
            case 4: updatePatient(); break;
            case 5: deletePatient(); break;
            case 6: cout << "Thank you." << endl; break;
            default: cout << "Invalid choice." << endl;
        }
    } while (choice != 6);

    return 0;
}