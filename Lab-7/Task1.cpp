#include <bits/stdc++.h>
using namespace std;

class Fraction {
private:
    int num, denom;

public:
    Fraction(int n, int d) : num(n), denom(d) {
        if (denom == 0) {
            throw invalid_argument("Denominator cannot be 0");
        }
        if (denom < 0) {
            denom = abs(denom);
            num = -num;
        }
        num /= __gcd(abs(num), abs(denom));
        denom /= __gcd(abs(num), abs(denom));
    }
    
    // I calculated all of this on my own (no GPT)
    Fraction operator+(const Fraction& f) const {
        return Fraction(num * f.denom + f.num * denom, denom * f.denom);
    }

    Fraction operator-(const Fraction& f) const {
        return Fraction(num * f.denom - f.num * denom, denom * f.denom);
    }

    Fraction operator*(const Fraction& f) const {
        return Fraction(num * f.num, denom * f.denom);
    }

    Fraction operator/(const Fraction& f) const {
        if (f.num == 0) throw invalid_argument("Division by zero");
        return Fraction(num * f.denom, denom * f.num);
    }

    bool operator==(const Fraction& f) const {
        return num == f.num && denom == f.denom;
    }

    bool operator!=(const Fraction& f) const {
        return num != f.num || denom != f.denom;
    }

    bool operator>(const Fraction& f) const {
        return num * f.denom > f.num * denom;
    }

    bool operator<(const Fraction& f) const {
        return num * f.denom < f.num * denom;
    }

    bool operator>=(const Fraction& f) const {
        return num * f.denom >= f.num * denom;
    }

    bool operator<=(const Fraction& f) const {
        return num * f.denom <= f.num * denom;
    }

    friend ostream& operator<<(ostream& os, const Fraction& f) {
        os << f.num << "/" << f.denom;
        return os;
    }

    friend istream& operator>>(istream& is, Fraction& f) {
        is >> f.num >> f.denom;
        if (f.denom == 0) {
            throw invalid_argument("Denominator cannot be 0");
        }
        return is;
    }
};

int main() {
        Fraction f1(2, 4), f2(3, 6);
        cout << "f1: " << f1 << endl;
        cout << "f2: " << f2 << endl;

        cout << "f1 + f2 = " << (f1 + f2) << endl;
        cout << "f1 - f2 = " << (f1 - f2) << endl;
        cout << "f1 * f2 = " << (f1 * f2) << endl;
        cout << "f1 / f2 = " << (f1 / f2) << endl;

        cout << "f1 == f2: " << (f1 == f2) << endl;
        cout << "f1 > f2: " << (f1 > f2) << endl;
        cout << "f1 < f2: " << (f1 < f2) << endl;

        Fraction f3(0, 1);
        cout << "Enter a fraction (numerator denominator): ";
        cin >> f3;
        cout << "You entered: " << f3 << endl;

    return 0;
}
