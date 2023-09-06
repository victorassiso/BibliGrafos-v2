# Compiler to use
CXX=g++

# Flags for the compiler
CXXFLAGS=-Wall -I./list

# Output binary name
OUTPUT=my_program

# Source files
SOURCES=main.cpp list/list.cpp list/neighbor.cpp list/vertex.cpp
OBJECTS=$(SOURCES:.cpp=.o)

all: $(OUTPUT)

$(OUTPUT): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(OUTPUT)

clean:
	rm -f $(OBJECTS) $(OUTPUT)

# This is an optional part:
# It adds a rule to compile .cpp files to .o files.
# The default rule in make might suffice, but including this ensures clarity.
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
