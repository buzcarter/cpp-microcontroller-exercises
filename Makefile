CC=g++
CFLAGS=-Iinclude
BIN_DIR=bin

DEPS = $(wildcard include/*.h)
SRC = $(wildcard src/*.cpp) $(wildcard src/lib/*.cpp) $(wildcard src/lib/*/*.cpp)
OBJ = $(addprefix $(BIN_DIR)/, $(notdir $(SRC:.cpp=.o)))

vpath %.cpp $(sort $(dir $(SRC)))

$(BIN_DIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

demo: $(OBJ)
	$(CC) -o $(BIN_DIR)/$@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(BIN_DIR)/*.o $(BIN_DIR)/demo
