CC=g++
CFLAGS=-Iincludes

DEPS = $(wildcard includes/*.h)
SRC = $(wildcard *.cpp includes/*.cpp)
OBJ = $(SRC:.cpp=.o)

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

critter: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o includes/*.o critter
