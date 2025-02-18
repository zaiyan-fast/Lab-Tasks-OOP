#include <iostream>
#include <cmath>
using namespace std;

class Polynomial {
private:
    int h_power;
    double* coeff;

public:
    Polynomial(){
        h_power = 0;
        coeff = new double[1];
        coeff[0] = 0.0;
    }

    Polynomial(int deg, const double* arr) : h_power(deg) {
        coeff = new double[h_power + 1];
        for (int i = 0; i < h_power + 1; i++) {
            coeff[i] = arr[i];
        }
    }

    Polynomial(const Polynomial& p) : h_power(p.h_power) {
        coeff = new double[h_power + 1];
        for (int i = 0; i < h_power + 1; i++) {
            coeff[i] = p.coeff[i];
        }
    }

    Polynomial(Polynomial&& p) noexcept : h_power(p.h_power), coeff(p.coeff) {
        p.coeff = nullptr;
        p.h_power = 0;
    }

    ~Polynomial() {
        delete[] coeff;
    }

    // Written by GPT as I have no idea how to do this operator stuff :(
    Polynomial& operator=(const Polynomial& p) {
        if (this != &p) {
            delete[] coeff;
            h_power = p.h_power;
            coeff = new double[h_power + 1];
            for (int i = 0; i <= h_power; i++) {
                coeff[i] = p.coeff[i];
            }
        }
        return *this;
    }

    Polynomial& operator=(Polynomial&& p) noexcept {
        if (this != &p) {
            delete[] coeff;
            h_power = p.h_power;
            coeff = p.coeff;
            p.coeff = nullptr;
            p.h_power = 0;
        }
        return *this;
    }

    int getDegree() {
        return h_power;
    }

    double evaluate(double x) const {
        double sum = 0.0;
        for (int i = 0; i <= h_power; i++) {
            sum += coeff[i] * pow(x, i);
        }
        return sum;
    }

    // Also GPT
    Polynomial add(const Polynomial& other) const {
        int max_degree = max(h_power, other.h_power);
        double* new_coeff = new double[max_degree + 1];

        for (int i = 0; i <= max_degree; i++) {
            new_coeff[i] = 0.0;
            if (i <= h_power) new_coeff[i] += coeff[i];
            if (i <= other.h_power) new_coeff[i] += other.coeff[i];
        }

        Polynomial result(max_degree, new_coeff);
        delete[] new_coeff;
        return result;
    }

    // GPT
    Polynomial multiply(const Polynomial& other) const {
        int result_degree = h_power + other.h_power;
        double* new_coeff = new double[result_degree + 1];

        for (int i = 0; i <= result_degree; i++) {
            new_coeff[i] = 0.0;
        }

        for (int i = 0; i <= h_power; i++) {
            for (int j = 0; j <= other.h_power; j++) {
                new_coeff[i + j] += coeff[i] * other.coeff[j];
            }
        }

        Polynomial result(result_degree, new_coeff);
        delete[] new_coeff;
        return result;
    }
};

int main() {
    double coeff1[] = {1, 2, 3};
    double coeff2[] = {4, 5};

    Polynomial p1(2, coeff1);
    Polynomial p2(1, coeff2);

    Polynomial p3 = p1.add(p2);
    Polynomial p4 = p1.multiply(p2);

    cout << "p1(2) = " << p1.evaluate(2) << endl;
    cout << "p2(2) = " << p2.evaluate(2) << endl;
    cout << "p3(2) = " << p3.evaluate(2) << endl;
    cout << "p4(2) = " << p4.evaluate(2) << endl;

    return 0;
}