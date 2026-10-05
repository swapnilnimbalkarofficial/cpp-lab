#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void addBook()
{
    int id, quantity;
    string name, author;
    float price;

    ofstream file("books.txt", ios::app);

    cout << "\nEnter Book ID: ";
    cin >> id;

    cin.ignore();

    cout << "Enter Book Name: ";
    getline(cin, name);

    cout << "Enter Author Name: ";
    getline(cin, author);

    cout << "Enter Price: ";
    cin >> price;

    cout << "Enter Quantity: ";
    cin >> quantity;

    file << id << endl;
    file << name << endl;
    file << author << endl;
    file << price << endl;
    file << quantity << endl;

    file.close();

    cout << "\nBook record added successfully.\n";
}

void showBooks()
{
    int id, quantity;
    string name, author;
    float price;

    ifstream file("books.txt");

    if (!file)
    {
        cout << "\nNo book records found.\n";
        return;
    }

    cout << "\n----- Book Records -----\n";

    while (file >> id)
    {
        file.ignore();

        getline(file, name);
        getline(file, author);

        file >> price;
        file >> quantity;

        cout << "\nBook ID     : " << id;
        cout << "\nBook Name   : " << name;
        cout << "\nAuthor      : " << author;
        cout << "\nPrice       : " << price;
        cout << "\nQuantity    : " << quantity << endl;
    }

    file.close();
}

void checkAvailability()
{
    int searchId;
    int id, quantity;
    string name, author;
    float price;
    bool found = false;

    cout << "\nEnter Book ID to check: ";
    cin >> searchId;

    ifstream file("books.txt");

    while (file >> id)
    {
        file.ignore();

        getline(file, name);
        getline(file, author);

        file >> price;
        file >> quantity;

        if (id == searchId)
        {
            found = true;

            cout << "\nBook Name : " << name;

            if (quantity > 0)
                cout << "\nBook is Available.\n";
            else
                cout << "\nBook is Not Available.\n";

            break;
        }
    }

    file.close();

    if (!found)
        cout << "\nBook not found.\n";
}

void modifyBook()
{
    int searchId;
    int id, quantity;
    string name, author;
    float price;
    bool found = false;

    cout << "\nEnter Book ID to modify: ";
    cin >> searchId;

    ifstream file("books.txt");
    ofstream temp("temp.txt");

    while (file >> id)
    {
        file.ignore();

        getline(file, name);
        getline(file, author);

        file >> price;
        file >> quantity;

        if (id == searchId)
        {
            found = true;

            cin.ignore();

            cout << "\nEnter New Book Name: ";
            getline(cin, name);

            cout << "Enter New Author Name: ";
            getline(cin, author);

            cout << "Enter New Price: ";
            cin >> price;

            cout << "Enter New Quantity: ";
            cin >> quantity;
        }

        temp << id << endl;
        temp << name << endl;
        temp << author << endl;
        temp << price << endl;
        temp << quantity << endl;
    }

    file.close();
    temp.close();

    remove("books.txt");
    rename("temp.txt", "books.txt");

    if (found)
        cout << "\nBook record modified successfully.\n";
    else
        cout << "\nBook not found.\n";
}

void deleteBook()
{
    int searchId;
    int id, quantity;
    string name, author;
    float price;
    bool found = false;

    cout << "\nEnter Book ID to delete: ";
    cin >> searchId;

    ifstream file("books.txt");
    ofstream temp("temp.txt");

    while (file >> id)
    {
        file.ignore();

        getline(file, name);
        getline(file, author);

        file >> price;
        file >> quantity;

        if (id == searchId)
        {
            found = true;
            continue;
        }

        temp << id << endl;
        temp << name << endl;
        temp << author << endl;
        temp << price << endl;
        temp << quantity << endl;
    }

    file.close();
    temp.close();

    remove("books.txt");
    rename("temp.txt", "books.txt");

    if (found)
        cout << "\nBook record deleted successfully.\n";
    else
        cout << "\nBook not found.\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n\n===== BOOKSHOP MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Book Records";
        cout << "\n2. Show Book Records";
        cout << "\n3. Check Availability";
        cout << "\n4. Modify Book Records";
        cout << "\n5. Delete Book Records";
        cout << "\n6. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addBook();
                break;

            case 2:
                showBooks();
                break;

            case 3:
                checkAvailability();
                break;

            case 4:
                modifyBook();
                break;

            case 5:
                deleteBook();
                break;

            case 6:
                cout << "\nThank you!\n";
                break;

            default:
                cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}