#include <bits/stdc++.h>
using namespace std;

class MediaFile {
protected:
    string filepath;
    double size;
public:
    MediaFile(string f, double s) : filepath(f), size(s) {
        cout << "MediaFile Constructor" << endl;
    }
    virtual void play() {
        cout << "File is playing: " << filepath << endl;
    }
    virtual void stop() {
        cout << "File has stopped playing: " << filepath << endl;
    }
    
    // Idk what this is
    virtual ~MediaFile() = default;
};

class VisualMedia : virtual public MediaFile {
private:
    int resX;
    int resY;
public:
    VisualMedia(string f, double s, int x, int y) : MediaFile(f, s), resX(x), resY(y) {
        cout << "VisualMedia Constructor" << endl;
    }
    void play() override {
        cout << "Visual Media is playing" << endl;
    }
    void stop() override {
        cout << "Visual Media has stopped playing" << endl;
    }
    void displayRes() const {
        cout << "Resolution: " << resX << " x " << resY << endl;
    }
};

class AudioMedia : virtual public MediaFile {
private:
    int sampleRate;
public:
    AudioMedia(string f, double s, int r) : MediaFile(f, s), sampleRate(r) {
        cout << "AudioMedia Constructor" << endl;
    }
    void play() override {
        cout << "Audio Media is playing" << endl;
    }
    void stop() override {
        cout << "Audio Media has stopped playing" << endl;
    }
    void displaySampleRate() const {
        cout << "Sample Rate: " << sampleRate << endl;
    }
};

class VideoFile : public VisualMedia, public AudioMedia {
public:
    VideoFile(string f, double s, int x, int y, int r)
        : MediaFile(f, s), VisualMedia(f, s, x, y), AudioMedia(f, s, r) {
        cout << "VideoFile Constructor" << endl;
    }
    void play() override {
        cout << "Playing video file: " << filepath << endl;
        displayRes();
        displaySampleRate();
    }
    void stop() override {
        cout << "Stopped video file: " << filepath << endl;
    }
};

// By GPT
void testFunction(){
    // Create objects
    VideoFile video("video.mp4", 500, 1920, 1080, 48000);
    VisualMedia image("image.jpg", 10, 800, 600);
    AudioMedia audio("audio.mp3", 5, 44100);

    // Store pointers in a base class array
    MediaFile* mediaFiles[] = {&video, &image, &audio};

    // Demonstrate polymorphism
    for (MediaFile* file : mediaFiles) {
        file->play();
        file->stop();
        cout << "-------------------" << endl;
    }
}

int main() {
    testFunction();
    return 0;
}