#pragma once
#include "memtable.h"
#include "wal.h"

class DB {
public:
    DB(const std::string& dir);
    ~DB();

    void put(const std::string& key, const std::string& value);
    void remove(const std::string& key);
    std::string get(const std::string& key);

private:
    MemTable memtable;
    WAL wal;
};