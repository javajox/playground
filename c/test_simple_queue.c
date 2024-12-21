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

    int e1 = dequeue(queue);
    int e2 = dequeue(queue);

    TEST_ASSERT_EQUAL_INT(1, e1);
    TEST_ASSERT_EQUAL_INT(2, e2);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_create_destroy);
    RUN_TEST(test_enqueue_dequeue);

    return UNITY_END();
}