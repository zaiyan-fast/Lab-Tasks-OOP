#include <bits/stdc++.h>
using namespace std;

class Currency {
protected:
    double amount;
    string code;
    string symbol;
    double rate; // Base is USD

public:
    Currency(double a, string c, string s, double r)
        : amount(a), code(c), symbol(s), rate(r) {}

    virtual double convertToBase() const {
        return amount * rate;
    }
    virtual double convertTo(const Currency& c) const {
        return convertToBase() / c.rate;
    }
    virtual void display() const = 0;
    virtual ~Currency() {}
};

class Dollar : public Currency {
public:
    Dollar(double a) : Currency(a, "USD", "$", 1.0) {}

    void display() const override {
        cout << "USD Amount: " << symbol << amount << endl;
    }
};

class Euro : public Currency {
public:
    Euro(double a) : Currency(a, "EUR", "€", 1.08) {}

    void display() const override {
        cout << "Euro Amount: " << symbol << amount << endl;
    }
};

class Rupee : public Currency {
public:
    Rupee(double a) : Currency(a, "PKR", "Rs", 0.0036) {}

    void display() const override {
        cout << "Rupee Amount: " << symbol << amount << endl;
    }
};

int main() {
    Dollar usd(100);
    Euro eur(50);
    Rupee pkr(5000);

    cout << "--- Currency Details ---" << endl;
    usd.display();
    eur.display();
    pkr.display();

    cout << "\nConverting 100 USD to EUR: " << usd.convertTo(eur) << " EUR" << endl;
    cout << "Converting 50 EUR to PKR: " << eur.convertTo(pkr) << " PKR" << endl;
    cout << "Converting 5000 PKR to USD: " << pkr.convertTo(usd) << " USD" << endl;

    return 0;
}
