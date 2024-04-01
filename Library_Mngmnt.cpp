#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

// Book class to store book information
class Book {
public:
    string title;
    string author;
    string isbn;
    bool available;

    Book(string t, string a, string i) : title(t), author(a), isbn(i), available(true) {}
};

// Borrower class to store borrower information
class Borrower {
public:
    string name;
    string email;

    Borrower(string n, string e) : name(n), email(e) {}
};

// Transaction class to record book transactions
class Transaction {
public:
    int bookIndex;
    int borrowerIndex;
    time_t checkoutDate;
    time_t returnDate;
    int fine;

    Transaction(int bIndex, int brIndex) : bookIndex(bIndex), borrowerIndex(brIndex) {
        time(&checkoutDate);
        returnDate = checkoutDate + 14 * 24 * 3600; // Assuming 14 days checkout period
        fine = 0;
    }
};

// Library class to manage books, borrowers, and transactions
class Library {
private:
    vector<Book> books;
    vector<Borrower> borrowers;
    vector<Transaction> transactions;

public:
    void addBook(const string& title, const string& author, const string& isbn) {
        books.emplace_back(title, author, isbn);
        cout << "Book added successfully." << endl;
    }

    void searchBook(const string& keyword) {
        bool found = false;
        for (const Book& book : books) {
            if (book.title.find(keyword) != string::npos || book.author.find(keyword) != string::npos || book.isbn.find(keyword) != string::npos) {
                found = true;
                cout << "Title: " << book.title << endl;
                cout << "Author: " << book.author << endl;
                cout << "ISBN: " << book.isbn << endl;
                cout << "Available: " << (book.available ? "Yes" : "No") << endl << endl;
            }
        }
        if (!found)
            cout << "No books found." << endl;
    }

    void checkoutBook(int bookIndex, int borrowerIndex) {
        if (books[bookIndex].available) {
            books[bookIndex].available = false;
            transactions.emplace_back(bookIndex, borrowerIndex);
            cout << "Book checked out successfully." << endl;
        } else {
            cout << "Book is not available for checkout." << endl;
        }
    }

    void returnBook(int bookIndex) {
        books[bookIndex].available = true;
        time_t currentTime;
        time(&currentTime);
        if (currentTime > transactions.back().returnDate) {
            int daysOverdue = (currentTime - transactions.back().returnDate) / (24 * 3600);
            transactions.back().fine = daysOverdue * 2; // Assuming $2 fine per day
            cout << "Book returned successfully. Fine of $" << transactions.back().fine << " incurred for overdue." << endl;
        } else {
            cout << "Book returned successfully." << endl;
        }
        transactions.pop_back();
    }
};

int main() {
    Library library;

    while (true) {
        cout << "Welcome to Library Management System" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Search Book" << endl;
        cout << "3. Check Out Book" << endl;
        cout << "4. Return Book" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string title, author, isbn;
                cout << "Enter book title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter author name: ";
                getline(cin, author);
                cout << "Enter ISBN: ";
                getline(cin, isbn);
                library.addBook(title, author, isbn);
                break;
            }
            case 2: {
                string keyword;
                cout << "Enter title, author, or ISBN to search: ";
                cin.ignore();
                getline(cin, keyword);
                library.searchBook(keyword);
                break;
            }
            case 3: {
                int bookIndex, borrowerIndex;
                cout << "Enter book index to check out: ";
                cin >> bookIndex;
                cout << "Enter borrower index: ";
                cin >> borrowerIndex;
                library.checkoutBook(bookIndex, borrowerIndex);
                break;
            }
            case 4: {
                int bookIndex;
                cout << "Enter book index to return: ";
                cin >> bookIndex;
                library.returnBook(bookIndex);
                break;
            }
            case 5:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
