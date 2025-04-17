#include <bits/stdc++.h>
using namespace std;

class Rec {
private:
    string name;
    int id;
    string dob;
    string history;
    string treatment;
    double due;

public:
    Rec(string n, int id, string d)
        : name(n), id(id), dob(d), history(""), treatment(""), due(0) {}

    string getBasic() const {
        return "Name: " + name + ", ID: " + to_string(id) + ", DOB: " + dob;
    }

private:
    void setHistory(string h) { history = h; }
    void setTreatment(string t) { treatment = t; }
    string getMedical() const { return "History: " + history + ", Treatment: " + treatment; }

    void addDue(double amt) { due += amt; }
    string getDue() const { return "Total Due: " + to_string(due); }

    friend class Doc;
    friend class Bill;
};

class Doc {
public:
    void update(Rec& r, string h, string t) {
        r.setHistory(h);
        r.setTreatment(t);
    }

    void view(const Rec& r) {
        cout << "Doctor Access:\n" << r.getMedical() << endl;
    }
};

class Bill {
public:
    void charge(Rec& r, double amt) {
        r.addDue(amt);
    }

    void view(const Rec& r) {
        cout << "Billing Access:\n" << r.getDue() << endl;
    }
};

class Front {
public:
    void view(const Rec& r) {
        cout << "Reception Access:\n" << r.getBasic() << endl;
    }
};

int main() {
    Rec p("Ali", 101, "1998-08-10");

    Doc d;
    d.update(p, "Flu", "Rest + Fluids");
    d.view(p);

    Bill b;
    b.charge(p, 1200);
    b.view(p);

    Front f;
    f.view(p);

    return 0;
}
