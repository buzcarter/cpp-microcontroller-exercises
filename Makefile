CC=g++
CFLAGS=-Iinclude

DEPS = $(wildcard include/*.h)
SRC = $(wildcard src/*.cpp) $(wildcard src/lib/*.cpp) $(wildcard src/lib/*/*.cpp)
OBJ = $(SRC:.cpp=.o)

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

critter: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f src/*.o critter
