# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++11

# Target executable, change this to the name of the executable you want to build
TARGET = bankers

# Test executable
TESTS = tests

# Source files for main program (exclude both tests.cpp and main.cpp)
SRCS = $(filter-out tests.cpp main.cpp, $(wildcard *.cpp))

# Object files for the common source files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Rule to build the main executable (using main.cpp)
$(TARGET): $(OBJS) main.o
	$(CXX) $(CXXFLAGS) -o $@ $^
	rm -f $(OBJS) main.o

# Rule to build the test executable (using tests.cpp)
test: $(OBJS) tests.o
	$(CXX) $(CXXFLAGS) -o $(TESTS) $^
	rm -f $(OBJS) tests.o

# Rule to build object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET) $(TESTS) tests.o

# Phony targets
.PHONY: all clean test
