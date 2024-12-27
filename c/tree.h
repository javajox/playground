// simple binary tree
#ifndef C_TREE_H
#define C_TREE_H

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
 * @return 0 if ok, -1 if error
 */
int delete(struct Node *root, char *loc_address);

struct Node *create_node(int node_data);

#endif //C_TREE_H
