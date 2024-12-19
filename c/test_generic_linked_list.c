#include "unity.h"
#include "generic_linked_list.h"
#include "string.h"

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

void test_empty_list_should_have_null_first(void) {

    TEST_ASSERT_NULL(first);
}

void test_adding_to_non_empty_list(void) {
    // Given a list with one node
    int first_value = 42;
    add_node(1, &first_value, sizeof(int));

    // When we add another node
    int second_value = 84;
    add_node(2, &second_value, sizeof(int));

    // Then it should be added at the end
    TEST_ASSERT_NOT_NULL(first->next);
    TEST_ASSERT_EQUAL_INT(84, *(int*)first->next->data);
    TEST_ASSERT_NULL(first->next->next);
}

// Custom structure for testing
struct Point {
    int x;
    int y;
};

void test_custom_struct_node(void) {
    // Given a custom structure
    struct Point point = {10, 20};

    // When we add it to the list
    add_node(1, &point, sizeof(struct Point));

    // Then we should be able to retrieve it correctly
    struct Point *stored = (struct Point*)first->data;
    TEST_ASSERT_EQUAL_INT(10, stored->x);
    TEST_ASSERT_EQUAL_INT(20, stored->y);
}

void add_remove_node(void) {
    int first_value = 42;
    add_node(1, &first_value, sizeof(int));

    int second_value = 84;
    add_node(2, &second_value, sizeof(int));

    remove_node(444);

    TEST_ASSERT_NOT_NULL(first);
    TEST_ASSERT_NOT_NULL(first->next);
    TEST_ASSERT_NULL(first->next->next);

    remove_node(2);

    TEST_ASSERT_NOT_NULL(first);
    TEST_ASSERT_NULL(first->next);

    remove_node(1);

    TEST_ASSERT_NULL(first);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_empty_list_should_have_null_first);
    RUN_TEST(test_add_integer_node);
    RUN_TEST(test_adding_to_non_empty_list);
    RUN_TEST(test_custom_struct_node);
    RUN_TEST(add_remove_node);

    return UNITY_END();
}