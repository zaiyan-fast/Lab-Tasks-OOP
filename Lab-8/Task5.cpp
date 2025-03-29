#include <bits/stdc++.h>
using namespace std;

class Media {
protected:
    string title, pubDate, id, publisher;
public:
    Media(string t, string d, string id, string p)
        : title(t), pubDate(d), id(id), publisher(p) {}

    virtual void displayInfo() const {
        cout << "Title: " << title << endl;
        cout << "Publication Date: " << pubDate << endl;
        cout << "Unique ID: " << id << endl;
        cout << "Publisher: " << publisher << endl;
    }
    void checkOut() {
        cout << title << " has been checked out" << endl;
    }
    void returnItem() {
        cout << title << " has been returned" << endl;
    }
    string getTitle() const{
        return title;
    }
    virtual string getAuthor() const{
        return "";
    } 
    virtual ~Media() {}
};

class Book : public Media {
    string author, ISBN;
    int numPages;
public:
    Book(string t, string d, string id, string p, string a, string isbn, int pages)
        : Media(t, d, id, p), author(a), ISBN(isbn), numPages(pages) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Number of Pages: " << numPages << endl;
    }
    string getAuthor() const override{
        return author;
    }
};

class DVD : public Media {
    string director;
    double duration;
    float rating;
public:
    DVD(string t, string d, string id, string p, string dir, double dur, float rate)
        : Media(t, d, id, p), director(dir), duration(dur), rating(rate) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Director: " << director << endl;
        cout << "Duration: " << duration << " hrs" << endl;
        cout << "Rating: " << rating << "/10" << endl;
    }
};

class CD : public Media {
    string artist, genre;
    int numTracks;
public:
    CD(string t, string d, string id, string p, string a, string gen, int tracks)
        : Media(t, d, id, p), artist(a), genre(gen), numTracks(tracks) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Artist: " << artist << endl;
        cout << "Genre: " << genre << endl;
        cout << "Number of Tracks: " << numTracks << endl;
    }
};

class Library {
    vector<Media*> collection;
public:
    void addMedia(Media* media) {
        collection.push_back(media);
    }

    void searchMedia(string title) {
        for (auto& media : collection) {
            if (media->getTitle() == title) {
                media->displayInfo();
                return;
            }
        }
        cout << title << " not found!" << endl;
    }
    void searchMediaByAuthor(string author) {
        for (auto& media : collection) {
            if (media->getAuthor() == author) {
                media->displayInfo();
                return;
            }
        }
        cout << "No books found by " << author << endl;
    }

    void displayAllMedia() {
        for (auto& media : collection) {
            media->displayInfo();
            cout << endl;
        }
    }
};

// Main by GPT
int main() {
    // Creating Library
    Library lib;

    // Adding media items
    Book b1("C++ Programming", "2020", "B001", "Tech Publishers", "Bjarne Stroustrup", "123456789", 400);
    DVD d1("Inception", "2010", "D001", "Warner Bros", "Christopher Nolan", 2.5, 8.8);
    CD c1("Thriller", "1982", "C001", "Epic Records", "Michael Jackson", "Pop", 9);

    // Adding to library
    lib.addMedia(&b1);
    lib.addMedia(&d1);
    lib.addMedia(&c1);

    // Display all media
    cout << "--- Library Collection ---" << endl;
    lib.displayAllMedia();

    // Searching media
    cout << "--- Search by Title ---" << endl;
    lib.searchMedia("Inception");

    cout << "--- Search by Author ---" << endl;
    lib.searchMediaByAuthor("Bjarne Stroustrup");

    return 0;
}
