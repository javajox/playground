#include "unity.h"
#include "tree.h"

struct Node *root;

void setUp(void) {
    root = NULL;
}

void tearDown(void) {

}

void test_create_root(void) {
    root = create_node(123);

    TEST_ASSERT_NOT_NULL(root);
    TEST_ASSERT_NULL(root->left);
    TEST_ASSERT_NULL(root->right);
    TEST_ASSERT_EQUAL_INT(123, root->data);
}

void test_insert(void) {
    root = create_node(123);

    root->left = create_node(1);
    root->left->left = create_node(3);
    root->left->left->left = create_node(4);
    root->left->left->right = create_node(5);

    root->right = create_node(2);
    root->right->right = create_node(7);
    root->right->right->right = create_node(8);
    root->right->left = create_node(6);

    int r = insert(root, "LL", 'R', 100);

    TEST_ASSERT_EQUAL_INT(0, r);

    int r2 = insert(root, "RRR", 'R', 200);

    TEST_ASSERT_EQUAL_INT(0, r2);

    TEST_ASSERT_EQUAL_INT(123, root->data);
    TEST_ASSERT_EQUAL_INT(1, root->left->data);
    TEST_ASSERT_NULL(root->left->right);
    TEST_ASSERT_EQUAL_INT(3, root->left->left->data);
    TEST_ASSERT_EQUAL_INT(4, root->left->left->left->data);
    TEST_ASSERT_EQUAL_INT(100, root->left->left->right->data);
    TEST_ASSERT_EQUAL_INT(5, root->left->left->right->right->data);
    TEST_ASSERT_NULL(root->left->left->right->right->right);
    TEST_ASSERT_NULL(root->left->left->right->right->left);
    TEST_ASSERT_NULL(root->left->left->right->left);
    TEST_ASSERT_NULL(root->left->left->left->left);
    TEST_ASSERT_NULL(root->left->left->left->right);

    TEST_ASSERT_EQUAL_INT(2, root->right->data);
    TEST_ASSERT_EQUAL_INT(7, root->right->right->data);
    TEST_ASSERT_EQUAL_INT(8, root->right->right->right->data);
    TEST_ASSERT_EQUAL_INT(6, root->right->left->data);
    TEST_ASSERT_NULL(root->right->left->right);
    TEST_ASSERT_NULL(root->right->left->left);
    TEST_ASSERT_NULL(root->right->right->left);
    TEST_ASSERT_EQUAL_INT(200, root->right->right->right->right->data);
    TEST_ASSERT_NULL(root->right->right->right->left);
}

void test_when_wrong_direction(void) {
    root = create_node(123);

    TEST_ASSERT_EQUAL_INT(-3, insert(root, "RR", 'k', 1));
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_create_root);
    RUN_TEST(test_insert);
    RUN_TEST(test_when_wrong_direction);

    return UNITY_END();
}