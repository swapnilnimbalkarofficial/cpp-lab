#include <iostream>
#include <string>
using namespace std;

class Book {
    int bookId;
    string title;
    string author;
    bool isAvailable;

public:
    Book() {
        bookId = 0;
        title = " ";
        author = " ";
        isAvailable = true;
    }

    Book(int id, string t, string a) {
        bookId = id;
        title = t;
        author = a;
        isAvailable = true;
    }

    ~Book() {
        cout << "Book object destroyed: " << title << endl;
    }

    void displayBook() {
        cout << "Book ID   : " << bookId << endl;
        cout << "Title     : " << title << endl;
        cout << "Author    : " << author << endl;
        if (isAvailable == true) {
            cout << "Status    : Available" << endl;
        } else {
            cout << "Status    : Issued" << endl;
        }
        cout << endl;
    }

    void issueBook() {
        if (isAvailable == true) {
            isAvailable = false;
            cout << "Book \"" << title << "\" issued successfully." << endl;
        } else {
            cout << "Book \"" << title << "\" is already issued." << endl;
        }
    }

    void returnBook() {
        if (isAvailable == false) {
            isAvailable = true;
            cout << "Book \"" << title << "\" returned successfully." << endl;
        } else {
            cout << "Book \"" << title << "\" was not issued." << endl;
        }
    }
};

int main() {
    Book b1;
    Book b2(101, "C++_Programming", "Balaguruswamy");
    Book b3(102, "Data_Structures", "Seymour_Lipschutz");

    cout << "---- Default Book ----" << endl;
    b1.displayBook();

    cout << "---- Book Details ----" << endl;
    b2.displayBook();
    b3.displayBook();

    cout << "---- Issue Book ----" << endl;
    b2.issueBook();
    b2.issueBook();
    b2.displayBook();

    cout << "---- Return Book ----" << endl;
    b2.returnBook();
    b2.returnBook();
    b2.displayBook();

    cout << "---- End of Program ----" << endl;
    return 0;
}