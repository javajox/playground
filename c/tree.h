// simple binary tree
#ifndef C_TREE_H
#define C_TREE_H
#include <stdbool.h>

// loc_address is given as a string, only "R" (from Right) and "L" (from Left) letters are allowed, examples LLRLRR

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

int destroy_tree(struct Node *root);

/**
 *
 * @param root - the root of the tree
 * @param loc_address - location in the tree
 * @param position - the direction (L - left or R - right)
 * @param node_data
 * @return 0 if ok, -1 if path not found, -2 unknown character in path, -3 direction not known, -4 root is null
 */
int insert(struct Node *root, char *loc_address, char direction, int node_data);

/**
 *
 * @param root - the root of the tree
 * @param loc_address - location in the tree
 * @return 0 if ok, -1 if error, -5 not a leaf, -2 unknown character in path (location is not valid)
 */
int delete_leaf(struct Node *root, char *loc_address);

struct Node *create_node(int node_data);

//traversal operations

/**
 * Visit recursively the tree nodes in the following order : left subtree --> root node --> right subtree
 * @param root
 */
void in_order_traverse(const struct Node *root);

/**
 * Visit recursively the tree nodes in the following order : root node --> left subtree --> right subtree
 * @param root
 */
void pre_order_traverse(const struct Node *root);

/**
 * Visit recursively the tree nodes in the following order : left subtree --> right subtree --> root node
 * @param root
 */
void post_order_traverse(const struct Node *root);

/**
 * Level-order traversal is a breadth-first traversal technique for binary trees.
 * In this method, nodes are visited level by level from top to bottom and from left to right within each level
 * @param root
 */
void level_order_traverse(struct Node *root);

int node_count(const struct Node *root);
int leaf_count(const struct Node *root);

int height(const struct Node *root);

bool balanced(const struct Node *root);

/**
 * Optimised version of "balanced" method
 * @param root
 * @return if the tree is balanced or not
 */
bool balanced2(const struct Node *root);

void in_order_traverse_non_rec(struct Node *root);
void pre_order_traverse_non_rec(struct Node *root);

#endif //C_TREE_H
