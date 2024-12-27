# Compiler settings
CC = gcc
CFLAGS = -Wall -Wextra -g

# Source files
UNITY_FILES = unity.c
SOURCE_FILES = generic_linked_list.c simple_queue.c simple_stack.c tree.c

# Header files directory
INCLUDES = -I.

# Test targets
test_generic_linked_list: $(UNITY_FILES) generic_linked_list.c test_generic_linked_list.c
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o test_generic_linked_list
	./test_generic_linked_list

test_simple_queue: $(UNITY_FILES) simple_queue.c test_simple_queue.c
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o test_simple_queue
	./test_simple_queue

test_simple_stack: $(UNITY_FILES) simple_stack.c test_simple_stack.c
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o test_simple_stack
	./test_simple_stack

test_tree: $(UNITY_FILES) tree.c test_tree.c
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o test_tree
	./test_tree

# Run all tests
test: test_generic_linked_list test_simple_queue test_simple_stack test_tree

clean:
	rm -f test_generic_linked_list test_simple_queue test_simple_stack test_tree