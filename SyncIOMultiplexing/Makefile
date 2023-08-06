GCC := gcc
C_FLAGS := -Werror
C_FLAGS += -Wall
C_FLAGS += -Wextra
C_FLAGS += -std=c99

BUILD_DIR := debug_server
OUTPUT := server

SERVER := debug-build
INCLUDE := server/include

DEBUG := -DDEBUG

RM := rm -rf
MKDIR := mkdir

FILENAME := server/server.c

server-debug: $(FILENAME)
	$(MKDIR) $(BUILD_DIR)
	$(GCC) -C $(FILENAME) -o $(BUILD_DIR)/$(OUTPUT) $(C_FLAGS) $(DEBUG) -I$(INCLUDE)

make clean:
	$(RM) $(BUILD_DIR)

