#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>

using namespace std;

// Define a Book structure
struct Book
{
    string title;
    string author;
    string isbn;
    bool available;
};

// Define a Borrower structure
struct Borrower
{
    string name;
    int borrowerID;
};

// Define a Transaction structure
struct Transaction
{
    int transactionID;
    int borrowerID;
    string isbn;
    time_t dueDate;
    bool returned;
};

class Library
{
private:
    vector<Book> books;
    vector<Borrower> borrowers;
    vector<Transaction> transactions;
    int nextBorrowerID;
    int nextTransactionID;

public:
    Library() : nextBorrowerID(1), nextTransactionID(1) {}

    // Function to add a book to the library
    void addBook(const string &title, const string &author, const string &isbn)
    {
        Book book;
        book.title = title;
        book.author = author;
        book.isbn = isbn;
        book.available = true;
        books.push_back(book);
        cout << "Book added to the library." << endl;
    }

    // Function to search for a book by title, author, or ISBN
    void searchBooks(const string &query)
    {
        cout << "Search Results:" << endl;
        for (const Book &book : books)
        {
            if (book.title.find(query) != string::npos ||
                book.author.find(query) != string::npos ||
                book.isbn.find(query) != string::npos)
            {
                cout << "Title: " << book.title << ", Author: " << book.author << ", ISBN: " << book.isbn;
                if (book.available)
                    cout << " (Available)" << endl;
                else
                    cout << " (Not Available)" << endl;
            }
        }
    }

    // Function to check out a book to a borrower
    void checkoutBook(int borrowerID, const string &isbn, int daysToReturn)
    {
        for (Book &book : books)
        {
            if (book.isbn == isbn && book.available)
            {
                Transaction transaction;
                transaction.transactionID = nextTransactionID++;
                transaction.borrowerID = borrowerID;
                transaction.isbn = isbn;
                transaction.dueDate = time(nullptr) + daysToReturn * 24 * 60 * 60; // Convert days to seconds
                transaction.returned = false;
                transactions.push_back(transaction);
                book.available = false;
                cout << "Book checked out successfully." << endl;
                return;
            }
        }
        cout << "Book not found or already checked out." << endl;
    }

    // Function to record book return
    void returnBook(int transactionID)
    {
        for (Transaction &transaction : transactions)
        {
            if (transaction.transactionID == transactionID && !transaction.returned)
            {
                transaction.returned = true;
                for (Book &book : books)
                {
                    if (book.isbn == transaction.isbn)
                    {
                        book.available = true;
                        cout << "Book returned successfully." << endl;
                        return;
                    }
                }
            }
        }
        cout << "Transaction not found or book already returned." << endl;
    }

    // Function to calculate fine for overdue books
    void calculateFine()
    {
        time_t currentTime = time(nullptr);
        double totalFine = 0.0;
        for (const Transaction &transaction : transactions)
        {
            if (!transaction.returned && transaction.dueDate < currentTime)
            {
                double daysLate = difftime(currentTime, transaction.dueDate) / (24 * 60 * 60); // Calculate days late
                double fine = daysLate * 1.0;                                                  // Fine of 1 rupee(s) per day late (you can adjust this)
                totalFine += fine;
            }
        }
        cout << "Total fine for overdue books: " << totalFine << " rupee(s)" << endl;
    }
};

int main()
{
    Library library;

    while (true)
    {
        cout << "Library Management System" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Search Books" << endl;
        cout << "3. Checkout Book" << endl;
        cout << "4. Return Book" << endl;
        cout << "5. Calculate Fine" << endl;
        cout << "6. Quit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;
        cin.ignore(); // Clear the newline character from the input buffer

        switch (choice)
        {
        case 1:
        {
            string title, author, isbn;
            cout << "Enter book title: ";
            getline(cin, title);
            cout << "Enter book author: ";
            getline(cin, author);
            cout << "Enter book ISBN: ";
            getline(cin, isbn);
            library.addBook(title, author, isbn);
            break;
        }
        case 2:
        {
            string query;
            cout << "Enter search query (title, author, or ISBN): ";
            getline(cin, query);
            library.searchBooks(query);
            break;
        }
        case 3:
        {
            int borrowerID;
            std::string isbn;
            int daysToReturn;
            std::cout << "Enter borrower ID: ";
            std::cin >> borrowerID;
            std::cout << "Enter book ISBN: ";
            std::cin.ignore();
            std::getline(std::cin, isbn);
            std::cout << "Enter number of days to return: ";
            cin >> daysToReturn;
            library.checkoutBook(borrowerID, isbn, daysToReturn);
            break;
        }
        case 4:
        {
            int transactionID;
            std::cout << "Enter transaction ID: ";
            std::cin >> transactionID;
            library.returnBook(transactionID);
            break;
        }
        case 5:
        {
            library.calculateFine();
            break;
        }
        case 6:
        {
            std::cout << "Goodbye!" << std::endl;
            return 0;
        }
        default:
        {
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
        }
    }

    return 0;
}
