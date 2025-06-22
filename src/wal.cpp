#include "wal.h"

WAL::WAL(const std::string& filepath) {
    logFile.open(filepath, std::ios::app);
}

WAL::~WAL() {
    if (logFile.is_open()) logFile.close();
}

void WAL::logPut(const std::string& key, const std::string& value) {
    logFile << "PUT " << key << " " << value << "\n";
}

void WAL::logDelete(const std::string& key) {
    logFile << "DELETE " << key << "\n";
}