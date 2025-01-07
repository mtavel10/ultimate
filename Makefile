.PHONY: all clean

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -gdwarf-4

# Target executable
TARGET = test

# For deleting the target
TARGET_DEL = test.executable

# Source files
SRCS = grid.cpp logic.cpp ultimate_test.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default rule to build and run the executable
all: $(TARGET) run

# Rule to link object files into the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) -lcriterion

# Rule to compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to run the executable
run: $(TARGET)
	$(TARGET)

# Clean rule to remove generated files
clean: 
	del $(TARGET_DEL) $(OBJS)