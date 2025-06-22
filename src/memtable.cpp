#include "memtable.h"

void MemTable::put(const std::string& key, const std::string& value) {
    table[key] = value;
}

void MemTable::remove(const std::string& key) {
    table[key] = "__TOMBSTONE__";;
}

std::string MemTable::get(const std::string& key) const {
    auto it = table.find(key);
    if (it == table.end() || it->second == "__TOMBSTONE__") {
        return "";
    }
    return it->second;
}

bool MemTable::contains(const std::string& key) const {
    auto it = table.find(key);
    return it != table.end();
}