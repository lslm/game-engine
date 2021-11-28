CXX = clang++ -std=c++17
LDFLAGS = ../Engine/bin/libengine.dylib -I../Engine/src -I../Engine/lib/spdlog/include
LDFLAGS += -I../Engine/lib/glfw/include -I../Engine/lib/glad/include

SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.c=.o)
BIN = bin

all: dirs libs editor copy

dirs:
	mkdir -p ./$(BIN)

libs:
	cd ../Engine && make

editor: $(OBJ)
	$(CXX) -o $(BIN)/editor $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) -c -o $@ $^

copy:
	cp ../Engine/bin/libengine.dylib bin/libengine.dylib

clean:
	rm -rf $(BIN) $(OBJ)