#include "unity.h"
#include "simple_queue.h"

struct Queue *queue;

void setUp(void) {

}

void tearDown(void) {
    queue = NULL;
}

void test_create_destroy(void) {
    queue = create_queue();

    TEST_ASSERT_NOT_NULL(queue);
    TEST_ASSERT_NULL(queue->first);

    destroy_queue(queue);
}

void test_enqueue_dequeue(void) {
    queue = create_queue();
    enqueue(queue, 1);
    enqueue(queue, 2);

    TEST_ASSERT_EQUAL_INT(1, dequeue(queue));
    TEST_ASSERT_EQUAL_INT(2, dequeue(queue));
    TEST_ASSERT_EQUAL_INT(-1, dequeue(queue));
    TEST_ASSERT_EQUAL_INT(-1, dequeue(queue));
}

void test_get_size_when_queue_is_empty(void) {
    queue = create_queue();

    TEST_ASSERT_EQUAL_INT(0, get_size(queue));
    TEST_ASSERT_EQUAL_INT(0, get_size(NULL));
}

void test_get_size_when_queue_is_not_empty(void) {
    queue = create_queue();
    enqueue(queue, 1);
    enqueue(queue, 2);

    TEST_ASSERT_EQUAL_INT(2, get_size(queue));

    dequeue(queue);

    TEST_ASSERT_EQUAL_INT(1, get_size(queue));

    dequeue(queue);

    TEST_ASSERT_EQUAL_INT(0, get_size(queue));
}

void test_peek_size_when_queue_is_empty(void) {

    TEST_ASSERT_EQUAL_INT(-1, peek(NULL));

    queue = create_queue();

    TEST_ASSERT_EQUAL_INT(-1, peek(queue));
}

void test_peek_size_when_queue_is_not_empty(void) {
    queue = create_queue();
    enqueue(queue, 1);
    enqueue(queue, 2);

    TEST_ASSERT_EQUAL_INT(1, peek(queue));

    dequeue(queue);

    TEST_ASSERT_EQUAL_INT(2, peek(queue));

    dequeue(queue);

    TEST_ASSERT_EQUAL_INT(-1, peek(queue));
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_create_destroy);
    RUN_TEST(test_enqueue_dequeue);
    RUN_TEST(test_get_size_when_queue_is_empty);
    RUN_TEST(test_get_size_when_queue_is_not_empty);
    RUN_TEST(test_peek_size_when_queue_is_empty);
    RUN_TEST(test_peek_size_when_queue_is_not_empty);

    return UNITY_END();
}