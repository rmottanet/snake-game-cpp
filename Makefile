# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Directories
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
BIN_DIR = bin

# Files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))
EXEC = $(BIN_DIR)/snake_game

# Targets
.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJ_FILES) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@ -I$(INCLUDE_DIR) -lsfml-graphics -lsfml-window -lsfml-system

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@ -I$(INCLUDE_DIR)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)
