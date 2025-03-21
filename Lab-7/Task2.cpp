#include <bits/stdc++.h>
using namespace std;
class PolynomialUtils;
class Polynomial{
    private:
        vector <int> coeff;
    public:
        Polynomial(){}
        Polynomial(vector <int> c) : coeff(c){
            while (!c.empty() && c.back() == 0) {
            c.pop_back();
        }
        coeff = c;
        }
        Polynomial operator+ (Polynomial& p){
            vector <int> other(max(coeff.size(), p.coeff.size()), 0);
            for(int i = 0; i < coeff.size(); i++){
                other[i] += coeff[i];
            }
            for(int i = 0; i < p.coeff.size(); i++){
                other[i] += p.coeff[i];
            }
            return Polynomial(other);
        }
        Polynomial operator- (Polynomial& p){
            vector <int> other(max(coeff.size(), p.coeff.size()), 0);
            for(int i = 0; i < coeff.size(); i++){
                other[i] += coeff[i];
            }
            for(int i = 0; i < p.coeff.size(); i++){
                other[i] -= p.coeff[i];
            }
            return Polynomial(other);
        }
        
        // Logic by GPT
        Polynomial operator*(const Polynomial& p) {
        vector<int> other(coeff.size() + p.coeff.size(), 0);
        for (int i = 0; i < coeff.size(); i++)
            for (int j = 0; j < p.coeff.size(); j++)
                other[i + j] += coeff[i] * p.coeff[j];
        return Polynomial(other);
    }
    friend ostream& operator<<(ostream& os, const Polynomial& p);
    friend class PolynomialUtils;
};

ostream& operator<<(ostream& os, const Polynomial& p){
    if(p.coeff.empty()){
        os << "0";
        return os;
    }
    for(int i = p.coeff.size() - 1; i >= 0; i--){
        if(p.coeff[i] == 0) continue;
        
        if (p.coeff[i] != p.coeff.back()) {
            os << (p.coeff[i] > 0 ? " + " : " - ");
        } else if (p.coeff[i] < 0) {
            os << "-";
        }

        if (abs(p.coeff[i]) != 1 || i == 0) os << abs(p.coeff[i]);
        if (i > 0) os << "x";
        if (i > 1) os << "^" << i;
    }
    return os;
}

class PolynomialUtils{
    public:
        static int evaluate(const Polynomial &p, int x){
            int result = 0, power = 1;
            for(auto c : p.coeff){
                result += c*power;
                power*=x;
            }
            return result;
        }
        // Logic of derivative by GPT
        static Polynomial derivative(const Polynomial &p){
            if (p.coeff.size() <= 1) return Polynomial({0});
            vector<int> derivativeCoeffs(p.coeff.size() - 1);
            for (int i = 1; i < p.coeff.size(); i++)
            {
                derivativeCoeffs[i - 1] = p.coeff[i] * i;
            }
            return Polynomial(derivativeCoeffs);
        }
};

int main() {
 	Polynomial p1({2, -3, 4});
    Polynomial p2({1, 0, -1});

    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;

    cout << "p1 + p2: " << (p1 + p2) << endl;
    cout << "p1 - p2: " << (p1 - p2) << endl;
    cout << "p1 * p2: " << (p1 * p2) << endl;

    cout << "p1 evaluated at x = 2: " << PolynomialUtils::evaluate(p1, 2) << endl;
    cout << "Derivative of p1: " << PolynomialUtils::derivative(p1) << endl;


    return 0;
}
