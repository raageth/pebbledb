#include "pebbledb.h"
#include <iostream>

int main() {
    {
        PebbleDB db("data");
        db.put("a", "apple");
        db.put("b", "banana");
        db.put("c", "carrot");

        std::cout << "a: " << db.get("a") << "\n";
        std::cout << "b: " << db.get("b") << "\n";
        std::cout << "c: " << db.get("c") << "\n";

        db.remove("b");
        std::cout << "b after delete: " << db.get("b") << "\n";
    }

    {
        PebbleDB db("data");
        std::cout << "\nAfter reopening DB:\n";
        std::cout << "a: " << db.get("a") << "\n";
        std::cout << "b: " << db.get("b") << "\n";
        std::cout << "c: " << db.get("c") << "\n";
    }

    return 0;
}
