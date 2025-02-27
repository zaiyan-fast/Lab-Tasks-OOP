#include <iostream>
#include <vector>
using namespace std;

class Book {
public:
    string title;
    string author;
    string isbn;

    Book(string title, string author, string isbn)
        : title(title), author(author), isbn(isbn) {}

    void displayInfo() {
        cout << "Title: " << title << ", Author: " << author << ", ISBN: " << isbn << endl;
    }

    ~Book() {
        cout << "Book Destroyed: " << title << endl;
    }
};

class Catalog {
private:
    vector<Book*> books;

public:
    void addBook(Book* book) {
        books.push_back(book);
    }

    Book* findBook(string isbn) {
        for (Book* book : books) {
            if (book->isbn == isbn) {
                return book;
            }
        }
        return nullptr;
    }

    ~Catalog() {
        cout << "Catalog Destroyed" << endl;
        for (Book* book : books) {
            delete book;
        }
    }
};

class Library {
private:
    string name;
    string address;
    Catalog catalog;
    vector<Book*> books;

public:
    Library(string name, string address)
        : name(name), address(address) {}

    void addBook(Book* book) {
        books.push_back(book);
        catalog.addBook(book);
    }

    void removeBook(Book* delBook) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (*it == delBook) {
                books.erase(it);
                break;
            }
        }
    }

    Book* findBookInCatalog(string isbn) {
        return catalog.findBook(isbn);
    }

    ~Library() {
        cout << "Library Destroyed" << endl;
    }
};

// Test Function by GPT
void testFunction() {
    Library library("City Library", "123 Main St.");

    // Create some Book objects on the heap
    Book* book1 = new Book("1984", "George Orwell", "9780451524935");
    Book* book2 = new Book("To Kill a Mockingbird", "Harper Lee", "9780061120084");
    Book* book3 = new Book("Brave New World", "Aldous Huxley", "9780060850524");

    // Add books to the library
    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);

    cout << "Searching for '1984' in the catalog:" << endl;
    Book* foundBook = library.findBookInCatalog("9780451524935");
    if (foundBook) {
        foundBook->displayInfo();
    } else {
        cout << "Book not found." << endl;
    }

    // Try to find a book that doesn't exist in the catalog
    cout << "Searching for a non-existing book:" << endl;
    foundBook = library.findBookInCatalog("1234567890");
    if (foundBook) {
        foundBook->displayInfo();
    } else {
        cout << "Book not found." << endl;
    }

    // Remove a book from the library
    library.removeBook(book2);

    // Demonstrate that the book is removed from the library
    cout << "Searching for 'To Kill a Mockingbird' after removal:" << endl;
    foundBook = library.findBookInCatalog("9780061120084");
    if (foundBook) {
        foundBook->displayInfo();
    } else {
        cout << "Book not found." << endl;
    }
}

int main() {
    testFunction();
    return 0;
}

