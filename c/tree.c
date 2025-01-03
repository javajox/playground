#include "tree.h"
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

struct Node *create_node(int root_data) {
    struct Node *node = malloc(sizeof(struct Node));
    assert(node != NULL);
    node->data = root_data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

static struct Node *find_node_by_loc(struct Node *root, char *loc_address) {
    struct Node *c = root;
    char *l = loc_address;
    while (*l != '\0') {
        if (*l == 'L') {
            c = c->left;
        } else if (*l == 'R') {
            c = c->right;
        }
        if (c == NULL) {
            // path not found
            return NULL;
        }
        ++l;
    }
    return c;
}

static bool location_not_valid(char *loc_address) {
    for (char *c = loc_address; *c != '\0'; c++) {
        if (*c != 'R' && *c != 'L') {
            return true;
        }
    }
    return false;
}

int insert(struct Node *root, char *loc_address, char direction, int node_data) {
    if (root == NULL) {
        return -4;
    }
    if (direction != 'L' && direction != 'R') {
        // unknown direction
        return -3;
    }
    if (location_not_valid(loc_address)) {
        return -2;
    }
    struct Node *c = find_node_by_loc(root, loc_address);
    if (c == NULL) {
        return -1;
    }
    struct Node *n = create_node(node_data);
    // left direction
    if (direction == 'L') {
        if (c->left == NULL) {
            c->left = n;
        } else {
            n->left = c->left;
            c->left = n;
        }
        return 0;
    }
    // right direction
    if (c->right == NULL) {
        c->right = n;
    } else {
        n->right = c->right;
        c->right = n;
    }
    return 0;
}

int delete_leaf(struct Node *root, char *loc_address) {
    if (location_not_valid(loc_address)) {
        return -2;
    }
    // node which will be removed
    struct Node *c = root;
    char *l = loc_address;
    // keep the pointer to the previous node
    struct Node *p = NULL;
    while (*l != '\0') {
        if (*l == 'L') {
            p = c;
            c = c->left;
        } else if (*l == 'R') {
            p = c;
            c = c->right;
        }
        if (c == NULL) {
            // path not found
            return -1;
        }
        ++l;
    }
    if (c->left != NULL || c->right != NULL) {
        return -5;
    }
    // here we know that our node is a leaf
    if (p->left == c) {
        p->left = NULL;
    } else {
        p->right = NULL;
    }
    free(c);
    return 0;
}

void in_order_traverse(struct Node *root) {
    if (root->left != NULL) {
        in_order_traverse(root->left);
    }
    printf("%d\n", root->data);
    if (root->right != NULL) {
        in_order_traverse(root->right);
    }
}

void pre_order_traverse(struct Node *root) {
    printf("%d\n", root->data);
    if (root->left != NULL) {
        pre_order_traverse(root->left);
    }
    if (root->right != NULL) {
        pre_order_traverse(root->right);
    }
}

void post_order_traverse(struct Node *root) {
    if (root->left != NULL) {
        pre_order_traverse(root->left);
    }
    if (root->right != NULL) {
        pre_order_traverse(root->right);
    }
    printf("%d\n", root->data);
}