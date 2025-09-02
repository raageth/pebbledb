#include "pebbledb.h"
#include <iostream>

PebbleDB::PebbleDB(const std::string& dbPath) : dbPath(dbPath), wal(dbPath + "/wal.log") {}

PebbleDB::~PebbleDB() {}

void PebbleDB::put(const std::string& key, const std::string& value) {
    wal.logPut(key, value);
    memtable.put(key, value);
}

std::string PebbleDB::get(const std::string& key) const {
    return memtable.get(key);
}

void PebbleDB::remove(const std::string& key) {
    wal.logDelete(key);
    memtable.remove(key);
}