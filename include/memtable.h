#pragma once
#include <map>
#include <string>

class MemTable {
public:
    void put(const std::string& key, const std::string& value);
    void remove(const std::string& key);
    std::string get(const std::string& key) const;
    bool contains(const std::string& key) const;
    size_t size() const;
    const std::map<std::string, std::string>& getTable() const;

private:
    std::map<std::string, std::string> table;
};