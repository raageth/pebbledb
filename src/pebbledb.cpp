#include "pebbledb.h"
#include <filesystem>

PebbleDB::PebbleDB(const std::string& dbPath) : dbPath(dbPath), wal(dbPath + "/wal.log") {
    std::filesystem::create_directories(dbPath);
    loadSSTables();
}

PebbleDB::~PebbleDB() {
    flushMemTable();
}

void PebbleDB::put(const std::string& key, const std::string& value) {
    wal.logPut(key, value);
    memtable.put(key, value);
    if (memtable.size() >= FLUSH_THRESHOLD) {
        flushMemTable();
    }
}

std::string PebbleDB::get(const std::string& key) const {
    std::string val = memtable.get(key);
    if (!val.empty()) return val;
    // Search SSTables (newest first)
    for (auto it = sstableFiles.rbegin(); it != sstableFiles.rend(); ++it) {
        std::map<std::string, std::string> data;
        SSTable::load(*it, data);
        auto found = data.find(key);
        if (found != data.end()) {
            if (found->second == "__TOMBSTONE__") return "";
            return found->second;
        }
    }
    return "";
}

void PebbleDB::remove(const std::string& key) {
    wal.logDelete(key);
    memtable.remove(key);
    if (memtable.size() >= FLUSH_THRESHOLD) {
        flushMemTable();
    }
}

void PebbleDB::flushMemTable() {
    if (memtable.size() == 0) return;
    std::string sstFile = dbPath + "/sstable_" + std::to_string(sstableFiles.size()) + ".db";
    SSTable::write(sstFile, memtable.getTable());
    sstableFiles.push_back(sstFile);
    memtable = MemTable();
}

void PebbleDB::loadSSTables() {
    for (const auto& entry : std::filesystem::directory_iterator(dbPath)) {
        if (entry.path().filename().string().find("sstable_") == 0) {
            sstableFiles.push_back(entry.path().string());
        }
    }
}