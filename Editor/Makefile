CC = clang++ -std=c++17
CFLAGS = -I../Engine/src -I../Engine/lib/spdlog/include
LDFLAGS = ../Engine/bin/libengine.dylib

SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.c=.o)
BIN = bin

all: dirs libs editor copy

dirs:
	mkdir -p ./$(BIN)

libs:
	cd ../Engine && make

editor: $(OBJ)
	$(CC) -o $(BIN)/editor $(CFLAGS) $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -c -o $@ $^

copy:
	cp ../Engine/bin/libengine.dylib bin/libengine.dylib

clean:
	rm -rf $(BIN) $(OBJ)