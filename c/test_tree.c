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

void test_delete_leaf(void) {
    root = create_node(123);
    root->left = create_node(1);
    root->right = create_node(2);
    root->right->left = create_node(3);
    root->right->right = create_node(4);
    root->left->right = create_node(5);
    root->left->right->right = create_node(6);

    TEST_ASSERT_EQUAL_INT(-2, delete_leaf(root, "LRpRRRR"));
    TEST_ASSERT_EQUAL_INT(-1, delete_leaf(root, "LRRRRRRR"));
    TEST_ASSERT_EQUAL_INT(-5, delete_leaf(root, "LR"));

    TEST_ASSERT_EQUAL_INT(0, delete_leaf(root, "LRR"));
    TEST_ASSERT_NULL(root->left->right->right);

    TEST_ASSERT_EQUAL_INT(0, delete_leaf(root, "RR"));
    TEST_ASSERT_NULL(root->right->right);

    TEST_ASSERT_EQUAL_INT(0, delete_leaf(root, "RL"));
    TEST_ASSERT_NULL(root->right->left);

    TEST_ASSERT_EQUAL_INT(0, delete_leaf(root, "R"));
    TEST_ASSERT_NULL(root->right);

    TEST_ASSERT_EQUAL_INT(0, delete_leaf(root, "LR"));
    TEST_ASSERT_NULL(root->left->right);

    TEST_ASSERT_EQUAL_INT(0, delete_leaf(root, "L"));
    TEST_ASSERT_NULL(root->left);
}

struct Node *create_test_tree() {
    root = create_node(123);
    root->left = create_node(1);
    root->right = create_node(2);
    root->right->left = create_node(3);
    root->right->right = create_node(4);
    root->left->right = create_node(5);
    root->left->right->right = create_node(6);
    return root;
}

void test_in_order_traverse(void) {
    in_order_traverse(create_test_tree());
}

void test_pre_order_traverse(void) {
    pre_order_traverse(create_test_tree());
}

void test_post_order_traverse(void) {
    post_order_traverse(create_test_tree());
}

void test_order_traverse_when_root_is_null(void) {
    in_order_traverse(NULL);
    pre_order_traverse(NULL);
    post_order_traverse(NULL);
}

void test_level_order_traverse(void) {
    root = create_node(123);
    root->left = create_node(1);
    root->right = create_node(2);
    root->right->left = create_node(3);
    root->right->right = create_node(4);
    root->left->right = create_node(5);
    root->left->right->right = create_node(6);

    level_order_traverse(root);
}

void test_node_count_when_root_is_null(void) {
    TEST_ASSERT_EQUAL_INT(0, node_count(NULL));
}

void test_node_count_when_3_nodes(void) {
    root = create_node(123);
    root->left = create_node(1);
    root->right = create_node(2);
    TEST_ASSERT_EQUAL_INT(3, node_count(root));
}

void test_node_count(void) {
    TEST_ASSERT_EQUAL_INT(7, node_count(create_test_tree()));
}

void test_leaf_count(void) {
    TEST_ASSERT_EQUAL_INT(3, leaf_count(create_test_tree()));
}

void test_leaf_count_when_root_is_null(void) {
    TEST_ASSERT_EQUAL_INT(0, leaf_count(NULL));
}

void test_leaf_count_when_1_node(void) {
    TEST_ASSERT_EQUAL_INT(1, leaf_count(create_node(123)));
}

void test_height(void) {
    TEST_ASSERT_EQUAL_INT(4, height(create_test_tree()));
}

void test_height_when_1_node(void) {
    TEST_ASSERT_EQUAL_INT(1, height(create_node(123)));
}

void test_height_when_root_is_null(void) {
    TEST_ASSERT_EQUAL_INT(0, height(NULL));
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_create_root);
    RUN_TEST(test_insert);
    RUN_TEST(test_when_wrong_direction);
    RUN_TEST(test_delete_leaf);
    RUN_TEST(test_pre_order_traverse);
    RUN_TEST(test_in_order_traverse);
    RUN_TEST(test_post_order_traverse);
    RUN_TEST(test_order_traverse_when_root_is_null);
    RUN_TEST(test_level_order_traverse);
    RUN_TEST(test_node_count_when_root_is_null);
    RUN_TEST(test_node_count_when_3_nodes);
    RUN_TEST(test_node_count);
    RUN_TEST(test_leaf_count);
    RUN_TEST(test_leaf_count_when_root_is_null);
    RUN_TEST(test_leaf_count_when_1_node);
    RUN_TEST(test_height);
    RUN_TEST(test_height_when_1_node);
    RUN_TEST(test_height_when_root_is_null);

    return UNITY_END();
}