CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iinclude

# List your source files
SRC = src/main.cpp src/trimmer.cpp

# Specify the object files
OBJ = $(patsubst src/%.cpp, build/%.o, $(SRC))

# Specify the target executable
TARGET = FASTATrimmer

all: $(TARGET)

$(TARGET): $(OBJ)
    $(CXX) $(CXXFLAGS) $^ -o $@

build/%.o: src/%.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

clean:
    rm -f $(OBJ) $(TARGET)
