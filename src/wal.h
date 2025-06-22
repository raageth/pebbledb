#pragma once
#include <fstream>
#include <string>

class WAL {
public:
    WAL(const std::string& filepath);
    ~WAL();
    void logPut(const std::string& key, const std::string& value);
    void logDelete(const std::string& key);

private:
    std::ofstream logFile;
};