#include <iostream>
#include <fstream>
#include <string>
// I'm getting error here for some reason
#include <filesystem>
using namespace std;
namespace fs = filesystem;

class Logger {
    string baseFile = "log.txt";
    int maxSize = 1024 * 1024; // 1MB
    int fileIndex = 1;

    string getNewFileName() {
        return "log" + to_string(fileIndex++) + ".txt";
    }

    void rotateLog() {
        if (fs::exists(baseFile) && fs::file_size(baseFile) >= maxSize) {
            string newName = getNewFileName();
            fs::rename(baseFile, newName);
        }
    }

public:
    void log(string msg) {
        rotateLog();
        ofstream out(baseFile, ios::app);
        out << msg << endl;
        out.close();
    }
};

int main() {
    Logger log;
    for (int i = 0; i < 100000; i++) {
        log.log("This is line number " + to_string(i));
    }
    return 0;
}
