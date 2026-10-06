#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;

class Stock {
    int id;
    string name;
    string category;
    float price;
    int quantity;
    string supplier;

public:
    void inputDetails() {
        cout << "Enter Product Name : ";
        cin >> name;
        cout << "Enter Category : ";
        cin >> category;
        cout << "Enter Price : ";
        cin >> price;
        cout << "Enter Quantity : ";
        cin >> quantity;
        cout << "Enter Supplier Name : ";
        cin >> supplier;
    }

    void input() {
        cout << "Enter Product ID : ";
        cin >> id;
        inputDetails();
    }

    void display() {
        cout << id << "\t" << name << "\t" << category << "\t"
             << price << "\t" << quantity << "\t" << supplier << endl;
    }

    void writeToFile(ofstream &fout) {
        fout << id << " " << name << " " << category << " "
             << price << " " << quantity << " " << supplier << endl;
    }

    bool readFromFile(ifstream &fin) {
        if (fin >> id >> name >> category >> price >> quantity >> supplier) {
            return true;
        }
        return false;
    }

    int getId() {
        return id;
    }

    int getQuantity() {
        return quantity;
    }

    void setQuantity(int q) {
        quantity = q;
    }

    float getValue() {
        return price * quantity;
    }
};

void addProduct() {
    Stock s, old;
    s.input();

    ifstream fin("stock.txt");
    while (old.readFromFile(fin)) {
        if (old.getId() == s.getId()) {
            cout << "Product ID already exists." << endl;
            fin.close();
            return;
        }
    }
    fin.close();

    ofstream fout("stock.txt", ios::app);
    s.writeToFile(fout);
    fout.close();
    cout << "Product added successfully." << endl;
}

void displayAll() {
    Stock s;
    bool found = false;

    ifstream fin("stock.txt");
    cout << "ID\tName\tCategory\tPrice\tQty\tSupplier" << endl;
    while (s.readFromFile(fin)) {
        s.display();
        found = true;
    }
    fin.close();

    if (found == false) {
        cout << "No products in stock." << endl;
    }
}

void searchProduct() {
    Stock s;
    int searchId;
    bool found = false;

    cout << "Enter Product ID to search : ";
    cin >> searchId;

    ifstream fin("stock.txt");
    while (s.readFromFile(fin)) {
        if (s.getId() == searchId) {
            cout << "Product found." << endl;
            s.display();
            found = true;
            break;
        }
    }
    fin.close();

    if (found == false) {
        cout << "Product not found." << endl;
    }
}

void updateProduct() {
    Stock s;
    int searchId;
    bool found = false;

    cout << "Enter Product ID to update : ";
    cin >> searchId;

    ifstream fin("stock.txt");
    ofstream fout("temp.txt");

    while (s.readFromFile(fin)) {
        if (s.getId() == searchId) {
            found = true;
            cout << "Enter new details :" << endl;
            s.inputDetails();
        }
        s.writeToFile(fout);
    }
    fin.close();
    fout.close();

    remove("stock.txt");
    rename("temp.txt", "stock.txt");

    if (found == true) {
        cout << "Product updated successfully." << endl;
    } else {
        cout << "Product not found." << endl;
    }
}

void deleteProduct() {
    Stock s;
    int searchId;
    bool found = false;

    cout << "Enter Product ID to delete : ";
    cin >> searchId;

    ifstream fin("stock.txt");
    ofstream fout("temp.txt");

    while (s.readFromFile(fin)) {
        if (s.getId() == searchId) {
            found = true;
        } else {
            s.writeToFile(fout);
        }
    }
    fin.close();
    fout.close();

    remove("stock.txt");
    rename("temp.txt", "stock.txt");

    if (found == true) {
        cout << "Product deleted successfully." << endl;
    } else {
        cout << "Product not found." << endl;
    }
}

void purchaseStock() {
    Stock s;
    int searchId, amount;
    bool found = false;

    cout << "Enter Product ID : ";
    cin >> searchId;
    cout << "Enter quantity to purchase : ";
    cin >> amount;

    ifstream fin("stock.txt");
    ofstream fout("temp.txt");

    while (s.readFromFile(fin)) {
        if (s.getId() == searchId) {
            found = true;
            s.setQuantity(s.getQuantity() + amount);
            cout << "Stock purchased. New quantity = " << s.getQuantity() << endl;
        }
        s.writeToFile(fout);
    }
    fin.close();
    fout.close();

    remove("stock.txt");
    rename("temp.txt", "stock.txt");

    if (found == false) {
        cout << "Product not found." << endl;
    }
}

void sellStock() {
    Stock s;
    int searchId, amount;
    bool found = false;

    cout << "Enter Product ID : ";
    cin >> searchId;
    cout << "Enter quantity to sell : ";
    cin >> amount;

    ifstream fin("stock.txt");
    ofstream fout("temp.txt");

    while (s.readFromFile(fin)) {
        if (s.getId() == searchId) {
            found = true;
            if (s.getQuantity() >= amount) {
                s.setQuantity(s.getQuantity() - amount);
                cout << "Stock sold. Remaining quantity = " << s.getQuantity() << endl;
            } else {
                cout << "Not enough stock. Available = " << s.getQuantity() << endl;
            }
        }
        s.writeToFile(fout);
    }
    fin.close();
    fout.close();

    remove("stock.txt");
    rename("temp.txt", "stock.txt");

    if (found == false) {
        cout << "Product not found." << endl;
    }
}

void calculateValue() {
    Stock s;
    float total = 0;

    ifstream fin("stock.txt");
    while (s.readFromFile(fin)) {
        total = total + s.getValue();
    }
    fin.close();

    cout << "Total stock value = " << total << endl;
}

int main() {
    int choice;

    do {
        cout << endl;
        cout << "===== STOCK MANAGEMENT SYSTEM =====" << endl;
        cout << "1. Add Product" << endl;
        cout << "2. Display All Products" << endl;
        cout << "3. Search Product" << endl;
        cout << "4. Update Product" << endl;
        cout << "5. Delete Product" << endl;
        cout << "6. Purchase Stock" << endl;
        cout << "7. Sell Stock" << endl;
        cout << "8. Calculate Stock Value" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice) {
            case 1: addProduct(); break;
            case 2: displayAll(); break;
            case 3: searchProduct(); break;
            case 4: updateProduct(); break;
            case 5: deleteProduct(); break;
            case 6: purchaseStock(); break;
            case 7: sellStock(); break;
            case 8: calculateValue(); break;
            case 9: cout << "Thank you." << endl; break;
            default: cout << "Invalid choice." << endl;
        }
    } while (choice != 9);

    return 0;
}