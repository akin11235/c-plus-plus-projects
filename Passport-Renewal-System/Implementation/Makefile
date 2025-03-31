# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -g

# Target executable
TARGET = my_program

# Source file
SRC = main.c

# Object file (derived from source file)
OBJ = $(SRC:.c=.o)

# Default rule to build the target
all: $(TARGET)

# Rule to link the object file into the target executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

# Rule to compile the source file into an object file
$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) -o $(OBJ)

# Rule to clean up generated files
ifeq ($(OS),Windows_NT)
clean:
	del $(subst /,\,$(TARGET) $(OBJ))
else
clean:
    	rm -f $(TARGET) $(OBJ)
endif

# Phony targets
.PHONY: all clean
