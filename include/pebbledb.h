#include "memtable.h"
#include "wal.h"
#include <string>

class PebbleDB {
public:
    explicit PebbleDB(const std::string& dbPath);
    ~PebbleDB();

    void put(const std::string& key, const std::string& value);
    std::string get(const std::string& key) const;
    void remove(const std::string& key);

private:
    std::string dbPath;
    MemTable memtable;
    WAL wal;
};