#include <bits/stdc++.h>
using namespace std;

class Blend {
public:
    void blend() {
        cout << "Blending in process..." << endl;
        this_thread::sleep_for(chrono::seconds(4));
        cout << "Blending complete." << endl;
    }
};

class Grind {
public:
    void grind() {
        cout << "Grinding in process..." << endl;
        this_thread::sleep_for(chrono::seconds(5));
        cout << "Grinding complete." << endl;
    }
};

class JuiceMaker {
private:
    Blend blend;
    Grind grind;

public:
    void blendJuice() {
        blend.blend();
    }

    void grindJuice() {
        grind.grind();
    }
};

int main() {
    JuiceMaker j;

    cout << "Started making juice..." << endl;
    j.blendJuice();
    j.grindJuice();
    cout << "Juice is ready." << endl;

    return 0;
}
