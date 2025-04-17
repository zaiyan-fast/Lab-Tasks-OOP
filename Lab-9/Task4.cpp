#include <bits/stdc++.h>
using namespace std;

class Flight {
    string flightNum, from, to;
    int cap, booked;

public:
    Flight(string no, string d, string arr, int c)
        : flightNum(no), from(d), to(arr), cap(c), booked(0) {}

    bool book() {
        if (booked < cap) { booked++; return true; }
        return false;
    }

    bool cancel() {
        if (booked > 0) { booked--; return true; }
        return false;
    }

    bool upgrade() {
        if (booked > 0) return true;
        return false;
    }

    void info() const {
        cout << "Flight " << flightNum << ": " << from << " -> " << to
             << ", Seats: " << booked << "/" << cap << "\n";
    }

    friend class Passenger;
};

class Passenger {
    string name;
    int id;

public:
    Passenger(string n, int i) : name(n), id(i) {}

    void bookSeat(Flight &f) {
        if (f.book()) cout << name << " booked successfully" << endl;
        else cout << name << " failed to book" << endl;
    }

    void cancelSeat(Flight &f) {
        if (f.cancel()) cout << name << " canceled seat" << endl;
        else cout << name << " had no seat to cancel" << endl;
    }

    void upgradeSeat(Flight &f) {
        if (f.upgrade()) cout << name << " upgraded seat" << endl;
        else cout << name << " can't upgrade" << endl;
    }
};

int main() {
    Flight f1("PK101", "LHE", "KHI", 2);
    Flight f2("PK202", "ISB", "DXB", 1);

    Passenger p1("Ali", 1);
    Passenger p2("Sara", 2);
    Passenger p3("Zain", 3);

    p1.bookSeat(f1);
    p2.bookSeat(f1);
    p3.bookSeat(f1);

    p1.upgradeSeat(f1);
    p3.upgradeSeat(f1);

    p2.cancelSeat(f1);
    p2.cancelSeat(f1);

    cout << "\nFlight Status:\n";
    f1.info();
    f2.info();

    return 0;
}
