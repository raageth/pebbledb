#include "db.h"
#include <iostream>

int main() {
    DB db("data");

    db.put("a", "apple");
    db.put("b", "banana");

    std::cout << "a: " << db.get("a") << "\n";
    std::cout << "b: " << db.get("b") << "\n";

    db.remove("a");
    std::cout << "a after delete: " << db.get("a") << "\n";

    return 0;
}
