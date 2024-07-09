# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -g -Wall -I. -Isrc/app/encrypt -Isrc/app/fileHandling -Isrc/app/processes

# Targets
MAIN_TARGET = encrypt_decrypt.exe
CRYPTION_TARGET = cryption.exe

# Source files
MAIN_SRC = main.cpp \
           src/app/processes/ProcessManagement.cpp \
           src/app/fileHandling/IO.cpp \
           src/app/fileHandling/ReadEnv.cpp \
           src/app/encrypt/Cryption.cpp

CRYPTION_SRC = src/app/encrypt/CryptionMain.cpp \
               src/app/encrypt/Cryption.cpp \
               src/app/fileHandling/IO.cpp \
               src/app/fileHandling/ReadEnv.cpp

# Object files
MAIN_OBJ = $(MAIN_SRC:.cpp=.o)
CRYPTION_OBJ = $(CRYPTION_SRC:.cpp=.o)

# Default target
all: $(MAIN_TARGET) $(CRYPTION_TARGET)

# Build rules
$(MAIN_TARGET): $(MAIN_OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(CRYPTION_TARGET): $(CRYPTION_OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compilation rule for object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@



.PHONY: clean

clean:
	del /Q main.o
	del /Q src\app\processes\ProcessManagement.o
	del /Q src\app\fileHandling\IO.o
	del /Q src\app\fileHandling\ReadEnv.o
	del /Q src\app\encrypt\Cryption.o
	del /Q src\app\encrypt\CryptionMain.o
	del /Q $(MAIN_TARGET)
	del /Q $(CRYPTION_TARGET)
	del /Q *.o
	del /Q *.exe