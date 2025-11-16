# Detect OS
UNAME_S := $(shell uname -s)

# Source files and target executable
SRCS := main.c
TARGET := main

# Default to Linux settings
RAYLIB_PATH := ./raylib-5.5_linux_amd64
# Specific static link flag for GNU ld
RAYLIB_LIB := -l:libraylib.a 
OS_LIBS := -lm

# Check if OS is Darwin (macOS)
ifeq ($(UNAME_S), Darwin)
    RAYLIB_PATH := ./raylib-5.5_macos
    # Use full path to static library
    RAYLIB_LIB := $(RAYLIB_PATH)/lib/libraylib.a
    # raylib on macOS requires these frameworks
    OS_LIBS := -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL
endif

# Compiler and Linker flags
CFLAGS := -I$(RAYLIB_PATH)/include/
LDFLAGS := -L$(RAYLIB_PATH)/lib/
LIBS := $(RAYLIB_LIB) $(OS_LIBS)

# --- Targets ---

build: $(SRCS)
	gcc $(CFLAGS) -o $(TARGET) $(SRCS) $(LDFLAGS) $(LIBS)

run: build
	./$(TARGET)
