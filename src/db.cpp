#include "db.h"

DB::DB(const std::string& dir)
    : wal(dir + "/wal.log") {}

DB::~DB() {}

void DB::put(const std::string& key, const std::string& value) {
    wal.logPut(key, value);
    memtable.put(key, value);
}

void DB::remove(const std::string& key) {
    wal.logDelete(key);
    memtable.remove(key);
}

std::string DB::get(const std::string& key) {
    return memtable.get(key);
}