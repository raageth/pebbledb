#include "sstable.h"
#include <fstream>

void SSTable::write(const std::string& filepath, const std::map<std::string, std::string>& data) {
    std::ofstream out(filepath);
    for (const auto& [k, v] : data) {
        out << k << '\t' << v << '\n';
    }
}

void SSTable::load(const std::string& filepath, std::map<std::string, std::string>& data) {
    std::ifstream in(filepath);
    std::string key, value;
    while (in >> key >> value) {
        data[key] = value;
    }
}