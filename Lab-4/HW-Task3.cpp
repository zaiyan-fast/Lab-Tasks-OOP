#include <iostream>
using namespace std;

class Invoice {
private:
    string partNumber;
    string partDescription;
    int quantity;
    double pricePerItem;

public:
    Invoice(string num, string desc, int q, double price) {
        this->partNumber = num;
        this->partDescription = desc;
        setQuantity(q);
        setPrice(price);
    }

    void setPartNumber(string num) {
        this->partNumber = num;
    }

    string getPartNumber() {
        return this->partNumber;
    }

    void setDescription(string description) {
        this->partDescription = description;
    }

    string getDescription() const {
        return partDescription;
    }

    void setQuantity(int q) {
        if (q > 0) {
            quantity = q;
        } else {
            quantity = 0;
        }
    }

    int getQuantity() {
        return quantity;
    }
    
    void setPrice(double price) {
        if (price > 0) 
            this->pricePerItem = price;
        else
            this->pricePerItem = 0;
    }

    double getPrice()  {
        return pricePerItem;
    }

    double getInvoice()  {
        return quantity * pricePerItem;
    }
};

int main() {
    Invoice invoice("1234", "Hammer", 5, 9.99);

    cout << "Part Number: " << invoice.getPartNumber() << endl;
    cout << "Part Description: " << invoice.getDescription() << endl;
    cout << "Quantity: " << invoice.getQuantity() << endl;
    cout << "Price Per Item: Rs." << invoice.getPrice() << endl;
    cout << "Invoice Amount: Rs." << invoice.getInvoice() << endl;

    // Invalid values
    Invoice invalidInvoice("5678", "Screwdriver", -3, -4.99);
    cout << "\nPart Number: " << invalidInvoice.getPartNumber() << endl;
    cout << "Part Description: " << invalidInvoice.getDescription() << endl;
    cout << "Quantity: " << invalidInvoice.getQuantity() << endl;
    cout << "Price Per Item: Rs." << invalidInvoice.getPrice() << endl;
    cout << "Invoice Amount: Rs." << invalidInvoice.getInvoice() << endl;

    return 0;
}