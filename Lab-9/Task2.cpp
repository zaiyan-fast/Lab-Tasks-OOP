#include <bits/stdc++.h>
using namespace std;

class Logger {
private:
    vector<string> logs;

    string formatMessage(string severity, string module, string message) {
        return "[" + severity + "] [" + module + "] " + message;
    }

    void storeLog(string msg) {
        logs.push_back(msg);
    }

public:
    void logInfo(string module, string message) {
        storeLog(formatMessage("INFO", module, message));
    }

    void logWarning(string module, string message) {
        storeLog(formatMessage("WARNING", module, message));
    }

    void logError(string module, string message) {
        storeLog(formatMessage("ERROR", module, message));
    }

    friend class LogAuditor;
};

class LogAuditor {
private:
    string password;

public:
    LogAuditor(string pass) : password(pass) {}

    vector<string> getLogs(const Logger& l) const {
        if (password == "admin123") {
            return l.logs;
        } else {
            cout << "Authentication failed" << endl;
            return {};
        }
    }
};

void networkModule(Logger& l) {
    l.logInfo("Network", "Connection established");
    l.logError("Network", "Failed to resolve");
}

void databaseModule(Logger& l) {
    l.logWarning("Database", "Query not solved");
    l.logInfo("Database", "User data inserte");
}

int main() {
    Logger logger;

    networkModule(logger);
    databaseModule(logger);

    LogAuditor auditor("admin123");
    vector<string> auditLogs = auditor.getLogs(logger);

    cout << "\n--- Audit Logs ---\n";
    for (string log : auditLogs) {
        cout << log << endl;
    }
    return 0;
}
