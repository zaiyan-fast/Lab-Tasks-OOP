#include <iostream>
using namespace std;

class Book{
  private:
    string title;
    string author;
    double price;
    string publisher;
    int stock;
public:

    Book(string auth, string title, double price, string pub, int stock) : title(title), author(auth), price(price), publisher(pub), stock(stock) {}
    
    void displayDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Price: " << price << endl;
        cout << "Stock: " << stock << " copies" << endl;
    }
    
    int isFound(string title, string auth){
        return (this->title == title && this->author == auth) ? 1 : 0;
    }
    
    int copy_check(int num_copy){
        return (this->stock >= num_copy) ? 1 : 0;
    }
    
    double getPrice() {
        return this->price;
    }
};

int main() {
    // Array by GPT
    Book books[] = {
        Book("J.K. Rowling", "Harry Potter and the Sorcerer's Stone", 15.99, "Bloomsbury", 10),
        Book("George Orwell", "1984", 12.99, "Secker & Warburg", 5),
        Book("J.R.R. Tolkien", "The Hobbit", 14.99, "Allen & Unwin", 8),
        Book("Harper Lee", "To Kill a Mockingbird", 10.99, "J.B. Lippincott & Co.", 3)
    };
    
    int num = sizeof(books) / sizeof(books[0]);
    string title, auth;
    cout << "Enter the title: ";
    getline(cin, title);
    cout << "Enter the author: ";
    getline(cin, auth);
    
    for(int i = 0; i < num; i++){
        if(books[i].isFound(title, auth)){
            books[i].displayDetails();
            
            int num_copies;
            cout << "Enter the number of copies: ";
            cin >> num_copies;
            
            if(books[i].copy_check(num_copies)){
                double tot_price = books[i].getPrice() * num_copies;
                cout << "Total Price is: " << tot_price << endl;
            }else{
                cout << "Sorry we don't have that many copies" << endl;
            }
            return 0;
        }
    }
    cout << "The book is not available rn." << endl;

    return 0;
}