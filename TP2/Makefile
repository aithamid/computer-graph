# Define the compiler
CXX = g++

# Define the flags
CXXFLAGS = -Wall -std=c++17

# Define the libraries to link
LIBS = -lGL -lglfw -lGLEW

# Define the source files
SRCS = vao.cpp ./common/GLShader.cpp

# Define the output executable
TARGET = vao

# Default target
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET) $(LIBS)

# Clean up build files
clean:
	rm -f $(TARGET)

.PHONY: all clean
