#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class MenuItem {
public:
    string name;
    string type;
    double price;
    MenuItem(string n, string t, double p) : name(n), type(t), price(p) {}
};

class CoffeeShop{
private:
    string name;
    vector <MenuItem> items;
    vector <string> orders;
    
public:
CoffeeShop(string name, vector<MenuItem> menu) : name(name), items(menu){}

string addOrder(string order){
    for(auto &item : items){
        if(item.name == order){
            orders.push_back(order);
            return "Order Pushed: " + order;
        }
    }
    return "This item is currently unavailable";
}

string fulfillOrder(){
    if(orders.size() == 0)  return "All orders have been fulfilled";
    string item = orders.front();
    orders.erase(orders.begin());
    return "The " + item + " is ready";
}

vector<string> listOrders()  {
    return orders;
}

double dueAmount(){
    double amount = 0;
    for(auto &item : items){
        for(auto &order : orders){
            if(item.name == order){
                amount += item.price;
                break;
            }
        }
    }
    return amount;
}

string cheapestItem(){
    if(items.size() == 0)   return "No items available";
    double price =  INT_MAX;
    
    for(auto &item : items){
        if(item.price < price)
            price = item.price;
    }
    
    for(auto &item : items){
        if(item.price == price)
            return item.name;
    }
}

vector<string> drinksOnly(){
    vector<string> drinks;
    for(auto &item : items){
        if(item.type == "drink"){
            drinks.push_back(item.name);
        }
    }
    return drinks;
}

vector<string> foodOnly(){
    vector<string> foods;
    for(auto &item : items){
        if(item.type == "food"){
            foods.push_back(item.name);
        }
    }
    return foods;
}
};

// Test Function by GPT
void testFunction(){
        vector<MenuItem> items = {
        MenuItem("Coffee", "drink", 2.5),
        MenuItem("Tea", "drink", 1.5),
        MenuItem("Sandwich", "food", 5.0),
        MenuItem("Cake", "food", 3.5)
    };

    CoffeeShop shop("My Coffee Shop", items);

    // Test methods
    cout << shop.addOrder("Coffee") << endl;
    cout << shop.addOrder("Sandwich") << endl;
    cout << shop.addOrder("Juice") << endl; // Unavailable item

    cout << "Orders: ";
    for (auto& order : shop.listOrders()) {
        cout << order << " ";
    }
    cout << endl;

    cout << "Total due amount: $" << shop.dueAmount() << endl;

    cout << "Cheapest item: " << shop.cheapestItem() << endl;

    cout << "Drinks: ";
    for (auto& drink : shop.drinksOnly()) {
        cout << drink << " ";
    }
    cout << endl;

    cout << "Foods: ";
    for (auto& food : shop.foodOnly()) {
        cout << food << " ";
    }
    cout << endl;

    cout << shop.fulfillOrder() << endl;
    cout << shop.fulfillOrder() << endl;
    cout << shop.fulfillOrder() << endl;
}


int main() {
    testFunction();
    return 0;
}