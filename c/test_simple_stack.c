#include "unity.h"
#include "simple_stack.h"

struct Stack *stack;

void setUp(void) {

}

void tearDown(void) {
    stack = NULL;
}

void test_flow(void) {
    stack = create_stack();

    TEST_ASSERT_TRUE(is_empty(stack));

    push(stack, 1);

    TEST_ASSERT_FALSE(is_empty(stack));
    TEST_ASSERT_EQUAL_INT(1, peek(stack));

    push(stack, 2);

    TEST_ASSERT_EQUAL_INT(2, peek(stack));

    TEST_ASSERT_EQUAL_INT(2, pop(stack));
    TEST_ASSERT_EQUAL_INT(1, pop(stack));

    TEST_ASSERT_TRUE(is_empty(stack));

    destroy_stack(stack);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_flow);

    return UNITY_END();
}