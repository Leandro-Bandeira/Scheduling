# Compiler
CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17 -Iutils

# Directories
SRC_DIR := src
UTILS_DIR := utils
BUILD_DIR := build
BIN_DIR := bin

# Find all source files
SRCS := $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(UTILS_DIR)/*.cpp)

# Generate corresponding object file paths in BUILD_DIR
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))
OBJS := $(patsubst $(UTILS_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(OBJS))

# Target executable
TARGET := $(BIN_DIR)/scheduling

# Default rule
all: $(TARGET)

# Link the final executable
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compilation rule for source files in SRC_DIR
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compilation rule for source files in UTILS_DIR
$(BUILD_DIR)/%.o: $(UTILS_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Ensure required directories exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Clean rule
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

.PHONY: all clean
