#include "unity.h"
#include "generic_linked_list.h"

void setUp(void) {
    first = NULL;
}

void tearDown(void) {
    struct Node *current = first;
    while (current != NULL) {
        struct Node *next = current->next;
        free_node(current);
        current = next;
    }
    first = NULL;
}

void test_add_integer_node(void) {
    int number = 42;

    add_node(1, &number, sizeof(int));

    TEST_ASSERT_NOT_NULL(first);
    TEST_ASSERT_EQUAL_INT(1, first->id);
    TEST_ASSERT_EQUAL_INT(sizeof(int), first->data_size);
    TEST_ASSERT_EQUAL_INT(42, *(int*)first->data);
    TEST_ASSERT_NULL(first->next);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_add_integer_node);

    return UNITY_END();
}