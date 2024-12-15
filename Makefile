# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -I./include -I/usr/include
LDFLAGS = -L/usr/lib -lGL -l:libglfw.so -ldl

# Directories
SRC_DIR = ./src
INC_DIR = ./include

# Files
SRC_FILES = $(SRC_DIR)/application.cpp
GLAD_SRC = $(INC_DIR)/glad/glad.c
OBJ_FILES = $(SRC_FILES:.cpp=.o) $(GLAD_SRC:.c=.o)

# Output binary
TARGET = application

# Targets
all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CXX) $(OBJ_FILES) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: %.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES) $(TARGET)

run:
	./application

.PHONY: all clean run

