# Makefile for Cradle Compiler Project
# Date: November 13, 2025

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -pedantic -I$(SRCDIR)
DEBUGFLAGS = -g -O0
RELEASEFLAGS = -O2

# Directories
SRCDIR = src
OBJDIR = obj
BINDIR = bin

# Target executable
TARGET = cradle
DEBUGTARGET = cradle_debug

# Automatically find all source files
SOURCES = $(wildcard $(SRCDIR)/*.c)
# Generate object file names from source files
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
# Find all header files
HEADERS = $(wildcard $(SRCDIR)/*.h)

# Default target
all: $(TARGET)

# Build release version
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(RELEASEFLAGS) -o $(TARGET) $(OBJECTS)
	@echo "Build complete: $(TARGET)"

# Build object files (release)
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS) | $(OBJDIR)
	$(CC) $(CFLAGS) $(RELEASEFLAGS) -c $< -o $@

# Create object directory
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Generate debug object file names from source files
DEBUG_OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%_debug.o)

# Build debug object files
$(OBJDIR)/%_debug.o: $(SRCDIR)/%.c $(HEADERS) | $(OBJDIR)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -c $< -o $@

# Build debug version
$(DEBUGTARGET): $(DEBUG_OBJECTS)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -o $(DEBUGTARGET) $(DEBUG_OBJECTS)
	@echo "Debug build complete: $(DEBUGTARGET)"

# Alias for debug target
debug: $(DEBUGTARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Run debug version
run-debug: debug
	./$(DEBUGTARGET)

# Clean build artifacts
clean:
	rm -f $(TARGET) $(DEBUGTARGET)
	rm -rf $(OBJDIR)
	rm -f *.o $(SRCDIR)/*.o
	@echo "Clean complete"

# Clean everything including backup files
distclean: clean
	rm -f *~ *.bak $(SRCDIR)/*~ $(SRCDIR)/*.bak
	@echo "Distribution clean complete"

# Rebuild from scratch
rebuild: clean all

# Check for syntax errors without building
check:
	$(CC) $(CFLAGS) -fsyntax-only $(SOURCES) $(HEADERS)

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

