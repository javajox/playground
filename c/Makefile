# Compiler settings
CC = gcc
CFLAGS = -Wall -Wextra -g

# Source files
UNITY_FILES = unity.c
SOURCE_FILES = generic_linked_list.c
TEST_FILES = test_generic_linked_list.c

# Header files directory (if headers are in a different directory)
INCLUDES = -I.

# Target
test: $(UNITY_FILES) $(SOURCE_FILES) $(TEST_FILES)
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o run_tests
	./run_tests

clean:
	rm -f run_tests