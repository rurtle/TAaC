# Makefile for Cradle Compiler Project
# Date: November 13, 2025

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -pedantic
DEBUGFLAGS = -g -O0
RELEASEFLAGS = -O2

# Directories
SRCDIR = .
OBJDIR = obj
BINDIR = bin

# Target executable
TARGET = cradle
DEBUGTARGET = cradle_debug

# Source and object files
SOURCES = cradle.c
OBJECTS = $(SOURCES:.c=.o)
HEADERS = cradle.h

# Default target
all: $(TARGET)

# Build release version
$(TARGET): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(RELEASEFLAGS) -o $(TARGET) $(SOURCES)
	@echo "Build complete: $(TARGET)"

# Build debug version
debug: $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -o $(DEBUGTARGET) $(SOURCES)
	@echo "Debug build complete: $(DEBUGTARGET)"

# Run the program
run: $(TARGET)
	./$(TARGET)

# Run debug version
run-debug: debug
	./$(DEBUGTARGET)

# Clean build artifacts
clean:
	rm -f $(TARGET) $(DEBUGTARGET) $(OBJECTS)
	rm -f *.o
	@echo "Clean complete"

# Clean everything including backup files
distclean: clean
	rm -f *~ *.bak
	@echo "Distribution clean complete"

# Rebuild from scratch
rebuild: clean all

# Check for syntax errors without building
check:
	$(CC) $(CFLAGS) -fsyntax-only $(SOURCES)

# Show help
help:
	@echo "Cradle Compiler Makefile"
	@echo "========================"
	@echo "Available targets:"
	@echo "  make          - Build release version"
	@echo "  make all      - Same as 'make'"
	@echo "  make debug    - Build debug version with symbols"
	@echo "  make run      - Build and run the program"
	@echo "  make run-debug- Build and run debug version"
	@echo "  make clean    - Remove build artifacts"
	@echo "  make distclean- Remove all generated files"
	@echo "  make rebuild  - Clean and rebuild"
	@echo "  make check    - Check syntax without building"
	@echo "  make help     - Show this help message"

# Phony targets (not actual files)
.PHONY: all debug run run-debug clean distclean rebuild check help

