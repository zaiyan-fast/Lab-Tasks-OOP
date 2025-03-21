#include <bits/stdc++.h>
using namespace std;

class BigInteger {
private:
    vector<int> digits;
    bool isNegative;

    void trim() {
        while (digits.size() > 1 && digits.back() == 0) {
            digits.pop_back();
        }
    }

public:
    BigInteger() : isNegative(false) {
        digits.push_back(0);
    }

    BigInteger(string s) {
        isNegative = false;
        if (s[0] == '-') {
            isNegative = true;
            s = s.substr(1);
        }
        for (int i = s.size() - 1; i >= 0; i--) {
            // I was trying this but it won't work
            // digits.push_back((int) s[i]);
            digits.push_back(s[i] - '0');
        }
        trim();
    }
    // Most of it is GPT
    BigInteger operator+(const BigInteger& other) const{
        if (isNegative == other.isNegative) {
            BigInteger result;
            result.isNegative = isNegative;

            int carry = 0, sum;
            int maxSize = max(digits.size(), other.digits.size());

            for (int i = 0; i < maxSize; i++) {
                sum = carry;
                if (i < digits.size()) sum += digits[i];
                if (i < other.digits.size()) sum += other.digits[i];

                result.digits.push_back(sum % 10);
                carry = sum / 10;
            }
            result.trim();
            return result;
        }

        if (isNegative) {
            return other - (-(*this));
        } else {
            return *this - (-other);
        }
    }
    // GPT
BigInteger operator-(const BigInteger& other) const {
        if (isNegative != other.isNegative) {
            return *this + (-other);
        }

        if (*this == other) return BigInteger("0");

        bool resultNegative = false;
        const BigInteger *larger, *smaller;
        
        if (absCompare(*this, other) >= 0) {
            larger = this;
            smaller = &other;
        } else {
            larger = &other;
            smaller = this;
            resultNegative = !isNegative;
        }

        BigInteger result;
        result.isNegative = resultNegative;

        int borrow = 0, diff;
        for (size_t i = 0; i < larger->digits.size(); i++) {
            diff = larger->digits[i] - borrow - (i < smaller->digits.size() ? smaller->digits[i] : 0);
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            result.digits.push_back(diff);
        }

        result.trim();
        return result;
    }

    BigInteger operator-() const {
        BigInteger result = *this;
        if (*this != BigInteger("0")) {
            result.isNegative = !isNegative;
        }
        return result;
    }

        // GPT
    static int absCompare(const BigInteger &a, const BigInteger &b) {
        if (a.digits.size() > b.digits.size()) return 1;
        if (a.digits.size() < b.digits.size()) return -1;
        for (int i = a.digits.size() - 1; i >= 0; i--) {
            if (a.digits[i] > b.digits[i]) return 1;
            if (a.digits[i] < b.digits[i]) return -1;
        }
        return 0;
    }

    bool operator==(const BigInteger& other) const {
        return isNegative == other.isNegative && digits == other.digits;
    }

    bool operator!=(const BigInteger& other) const {
        return !(*this == other);
    }

    bool operator<(const BigInteger& other) const {
        if (isNegative != other.isNegative) return isNegative;
        int cmp = absCompare(*this, other);
        return isNegative ? cmp > 0 : cmp < 0;
    }

    bool operator>(const BigInteger& other) const {
        return other < *this;
    }

    bool operator<=(const BigInteger& other) const {
        return !(*this > other);
    }

    bool operator>=(const BigInteger& other) const {
        return !(*this < other);
    }

    friend istream& operator>>(istream& in, BigInteger& num) {
        string input;
        in >> input;
        num = BigInteger(input);
        return in;
    }

    friend ostream& operator<<(ostream& out, const BigInteger& num) {
        if (num.isNegative) out << "-";
        for (int i = num.digits.size() - 1; i >= 0; i--) {
            out << num.digits[i];
        }
        return out;
    }
};

int main() {
    // Test function by GPT
    BigInteger num1, num2;
    
    cout << "Enter first big integer: ";
    cin >> num1;
    
    cout << "Enter second big integer: ";
    cin >> num2;

    cout << "\nResults:\n";
    cout << "num1: " << num1 << endl;
    cout << "num2: " << num2 << endl;
    cout << "num1 + num2 = " << (num1 + num2) << endl;
    cout << "num1 - num2 = " << (num1 - num2) << endl;
    cout << "num1 == num2? " << (num1 == num2 ? "Yes" : "No") << endl;
    cout << "num1 < num2? " << (num1 < num2 ? "Yes" : "No") << endl;
    
    return 0;
}
