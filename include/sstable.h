#include <string>
#include <map>

class SSTable {
public:
    static void write(const std::string& filepath, const std::map<std::string, std::string>& data);
    static void load(const std::string& filepath, std::map<std::string, std::string>& data);
};