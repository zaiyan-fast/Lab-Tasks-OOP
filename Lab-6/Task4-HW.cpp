#include <bits/stdc++.h>
using namespace std;

class Books {
protected:
    string genre;
public:
    Books(string g) : genre(g) {}
    virtual void displayDetails() const = 0;
    virtual ~Books() {}
};

class Novel : public Books {
private:
    string title;
    string author;
public:
    Novel(string t, string a) : Books("Novel"), title(t), author(a) {}
    void displayDetails() const override {
        cout << "Genre: " << genre << "\nTitle: " << title << "\nAuthor: " << author << "\n\n";
    }
};

class Mystery : public Books {
private:
    string title;
    string author;
public:
    Mystery(string t, string a) : Books("Mystery"), title(t), author(a) {}
    void displayDetails() const override {
        cout << "Genre: " << genre << "\nTitle: " << title << "\nAuthor: " << author << "\n\n";
    }
};

int main() {
    // Test by GPT
    vector<Books*> library;

    library.push_back(new Novel("Pride and Prejudice", "Jane Austen"));
    library.push_back(new Mystery("Sherlock Holmes", "Arthur Conan Doyle"));

    cout << "Library Books:\n";
    for (auto& book : library) {
        book->displayDetails();
    }

    for (auto book : library) {
        delete book;
    }

    return 0;
}
