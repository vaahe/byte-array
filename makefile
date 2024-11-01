CXX = g++

CXXFLAGS = -Wall -Wextra -std=c++17

SOURCES = main.cpp byte_array.cpp
OUTPUT = main

all: $(OUTPUT)

$(OUTPUT): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(OUTPUT)

clean:
	rm -f $(OUTPUT)

.PHONY: all clean