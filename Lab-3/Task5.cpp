#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string name;
    string ISBN;
    string author_name;
    string publisher;

public:
    string getBookName(){
        return name;
    }

    string getISBN(){
        return ISBN;
    }

    string getAuthorName(){
        return author_name;
    }

    string getPublisher(){
        return publisher;
    }
    
    void setBookName(string book) {
        name = book;
    }

    void setISBN(string isbn) {
        ISBN = isbn;
    }

    void setAuthorName(string author) {
        author_name = author;
    }

    void setPublisher(string pub) {
        publisher = pub;
    }

    string getBookInfo() {
        return "Book Name: " + name +
               "\nISBN: " + ISBN +
               "\nAuthor: " + author_name +
               "\nPublisher: " + publisher;
    }
};


int main(int argc, char* argv[]) {
    Book books[5];
    
    int j = 1;
    for(int i = 0; i < 5; i++){
        books[i].setBookName(argv[j++]);
        books[i].setISBN(argv[j++]); 
        books[i].setAuthorName(argv[j++]); 
        books[i].setPublisher(argv[j++]); 
    }

    for (int i = 0; i < 5; i++) {
        cout << "Information of book " << i + 1 << ":\n";
        cout << books[i].getBookInfo() << endl;
    }

    return 0;
}
