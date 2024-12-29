#include "tree.h"
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

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
