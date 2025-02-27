#include <bits/stdc++.h>
using namespace std;

struct MenuItem {
    string name;
    string type;
    double price;
};

class CoffeeShop {
private:
    string name;
    vector<MenuItem> menu;
    vector<string> orders;

public:
    CoffeeShop(string name, vector<MenuItem> m) : name(name), menu(m) {}
    
    string addOrder(string item){
        for(auto& i : menu){
            if(i.name == item){
                orders.push_back(item);
                return "Order Added!";
            }
        }
        return item + " is currently unavailable!";
    }
    string fulfillOrder(){
        if(!orders.empty()){
            string str = "The " + orders.front() + " is ready";
            orders.erase(orders.begin());
            return str;
        }
        else
            return "All orders have been fulfilled!";
    }
    
    vector<string> listOrders(){
        return orders;
    }
    
    double dueAmount(){
        double amount = 0;
        for(auto& i : orders){
            for(auto& item : menu){
                if(i == item.name)
                    amount += item.price;
            }
        }
        return amount;
    }
    
    string cheapestItem(){
        if(orders.empty())
            return "Menu is empty!";
        
        double min = INT_MAX;
        string cheap_itm;
        for(auto& item : menu){
            if(item.price < min){
                min = item.price;
                cheap_itm = item.name;
            }
        }
        return cheap_itm;
    }
    
    vector<string> drinksOnly(){
        vector <string> drinks;
        for(auto& item : menu){
            if(item.type == "drink"){
                drinks.push_back(item.name);
            }
        }
        return drinks;
    }
    
    vector<string> foodsOnly(){
        vector <string> foods;
        for(auto& item : menu){
            if(item.type == "food"){
                foods.push_back(item.name);
            }
        }
        return foods;
    }
    string getShopName(){
        return name;
    }
};

// Test Function by GPT
void testFunction(){
     // Create a few items for the menu
    vector<MenuItem> menu = {
        {"Coffee", "drink", 2.5},
        {"Tea", "drink", 1.8},
        {"Sandwich", "food", 4.0},
        {"Cake", "food", 3.5},
        {"Juice", "drink", 3.0}
    };

    // Create a CoffeeShop object
    CoffeeShop myCoffeeShop("Java Delight", menu);

    // Display shop name
    cout << "Welcome to " << myCoffeeShop.getShopName() << "!" << endl;

    // Add some orders
    cout << myCoffeeShop.addOrder("Coffee") << endl;
    cout << myCoffeeShop.addOrder("Juice") << endl;
    cout << myCoffeeShop.addOrder("Sandwich") << endl;
    cout << myCoffeeShop.addOrder("Pizza") << endl; // This should give "unavailable"

    cout << "Orders list: ";
    for (const auto& order : myCoffeeShop.listOrders()) {
        cout << order << " ";
    }
    cout << endl;

    cout << myCoffeeShop.fulfillOrder() << endl;

    cout << "Total amount due: $" << myCoffeeShop.dueAmount() << endl;

    cout << "Cheapest item: " << myCoffeeShop.cheapestItem() << endl;

    cout << "Drinks menu: ";
    for (const auto& drink : myCoffeeShop.drinksOnly()) {
        cout << drink << " ";
    }
    cout << endl;

    cout << "Food menu: ";
    for (const auto& food : myCoffeeShop.foodsOnly()) {
        cout << food << " ";
    }
    cout << endl;

}

int main() {
    testFunction();
    return 0;
}

