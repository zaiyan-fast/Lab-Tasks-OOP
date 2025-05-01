#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

class Person {
public:
    string id, fname, lname, addr, mail;

    Person(string a, string b, string c, string d, string e) : id(a), fname(b), lname(c), addr(d), mail(e) {}

    string toStr() const {
        return id + "," + fname + "," + lname + "," + addr + "," + mail;
    }

    static Person fromStr(const string& line) {
        stringstream ss(line);
        string a, b, c, d, e;
        getline(ss, a, ',');
        getline(ss, b, ',');
        getline(ss, c, ',');
        getline(ss, d, ',');
        getline(ss, e, ',');
        return Person(a, b, c, d, e);
    }
};

class Item {
public:
    string id, name, desc;
    int price;

    Item(string a, string b, string c, int d) : id(a), name(b), desc(c), price(d) {}

    string toStr() const {
        return id + "," + name + "," + desc + "," + to_string(price);
    }

    static Item fromStr(const string& line) {
        stringstream ss(line);
        string a, b, c, d;
        getline(ss, a, ',');
        getline(ss, b, ',');
        getline(ss, c, ',');
        getline(ss, d, ',');
        return Item(a, b, c, stoi(d));
    }
};

class Buy {
public:
    string id, personId, itemId;
    int paid;

    Buy(string a, string b, string c, int d) : id(a), personId(b), itemId(c), paid(d) {}

    string toStr() const {
        return id + "," + personId + "," + itemId + "," + to_string(paid);
    }

    static Buy fromStr(const string& line) {
        stringstream ss(line);
        string a, b, c, d;
        getline(ss, a, ',');
        getline(ss, b, ',');
        getline(ss, c, ',');
        getline(ss, d, ',');
        return Buy(a, b, c, stoi(d));
    }
};

void saveData() {
    ofstream f1("people.txt");
    f1 << Person("1", "Ali", "Raza", "Lahore", "ali@mail.com").toStr() << endl;
    f1 << Person("2", "Sara", "Khan", "Karachi", "sara@mail.com").toStr() << endl;
    f1.close();

    ofstream f2("items.txt");
    f2 << Item("1", "Book", "C++ Guide", 300).toStr() << endl;
    f2 << Item("2", "Pen", "Gel Pen", 50).toStr() << endl;
    f2.close();

    ofstream f3("buys.txt");
    f3 << Buy("1", "1", "1", 300).toStr() << endl;
    f3 << Buy("2", "2", "2", 50).toStr() << endl;
    f3.close();
}

vector<Person> getPeople() {
    ifstream f("people.txt");
    vector<Person> v;
    string s;
    while (getline(f, s)) v.push_back(Person::fromStr(s));
    return v;
}

vector<Item> getItems() {
    ifstream f("items.txt");
    vector<Item> v;
    string s;
    while (getline(f, s)) v.push_back(Item::fromStr(s));
    return v;
}

vector<Buy> getBuys() {
    ifstream f("buys.txt");
    vector<Buy> v;
    string s;
    while (getline(f, s)) v.push_back(Buy::fromStr(s));
    return v;
}

void findItems(string name) {
    vector<Person> p = getPeople();
    vector<Item> i = getItems();
    vector<Buy> b = getBuys();

    string uid = "";
    for (auto x : p) {
        if (x.fname == name) {
            uid = x.id;
            break;
        }
    }

    if (uid == "") {
        cout << "Not found\n";
        return;
    }

    vector<string> iids;
    for (auto x : b) {
        if (x.personId == uid) iids.push_back(x.itemId);
    }

    cout << "Items bought by " << name << ":\n";
    for (auto id : iids) {
        for (auto x : i) {
            if (x.id == id) cout << "- " << x.name << endl;
        }
    }
}

int main() {
    saveData();
    findItems("Ali");
    return 0;
}
