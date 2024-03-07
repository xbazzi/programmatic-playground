# Define the compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++20

# Define the target executable
TARGET = ./bin/linked_list

# Define the source files
SOURCES = LinkedList.cpp main.cpp

# Define the object files
OBJECTS = $(SOURCES:.cpp=.o)

# Rule to create the target executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Rule to clean the build
clean:
	rm -f $(OBJECTS) $(TARGET)

# Makefile suffix rule
.SUFFIXES: .cpp .o

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@
