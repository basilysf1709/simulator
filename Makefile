# Define compiler
CXX=g++

# Define flags
CXXFLAGS=-Wall -g

# Define the binary program name
TARGET=main

# Define objects
OBJS=main.o ProcessManager.o

# Rule for making the final target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule for making the object files
main.o: main.cpp ProcessManager.h
	$(CXX) $(CXXFLAGS) -c main.cpp

ProcessManager.o: ProcessManager.cpp ProcessManager.h
	$(CXX) $(CXXFLAGS) -c ProcessManager.cpp

# Phony target for cleaning up
.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJS)
