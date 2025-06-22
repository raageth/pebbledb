CXX = g++
CXXFLAGS = -std=c++17 -Wall
SRC = src/main.cpp src/db.cpp src/memtable.cpp src/wal.cpp
OUT = pebbledb

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(OUT) $(SRC)

clean:
	rm -f $(OUT)
