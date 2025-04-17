#include <bits/stdc++.h>
using namespace std;

class Student {
public:
    virtual float getTuition(string status, int credits) = 0;
};

class GraduateStudent : public Student {
    string topic;
public:
    void setTopic(string t) { topic = t; }
    string getTopic() { return topic; }

    float getTuition(string status, int credits) override {
        if (status == "undergraduate") return credits * 200;
        if (status == "graduate") return credits * 300;
        if (status == "doctoral") return credits * 400;
        return 0;
    }
};

int main() {
    GraduateStudent g;
    g.setTopic("Machine Learning");

    cout << "Topic: " << g.getTopic() << endl;
    cout << "Graduate Tuition: " << g.getTuition("graduate", 3) << endl;
    cout << "Undergrad Tuition: " << g.getTuition("undergraduate", 3) << endl;
    return 0;
}
