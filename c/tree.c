#include "tree.h"
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

struct QNode {
    // pointer to tree node
    struct Node *data;
    struct QNode *next;
};

struct Queue {
    struct QNode *head;
};

struct Stack {
    struct QNode *top;
};

static void enqueue(struct Queue *queue, struct Node *tree_node) {
    assert(queue != NULL);
    struct QNode *e = malloc(sizeof (struct QNode));
    assert(e != NULL);
    e->data = tree_node;
    e->next = NULL;
    if (queue->head == NULL) {
        queue->head = e;
    } else {
        e->next = queue->head;
        queue->head = e;
    }
}

static struct Node *dequeue(struct Queue *queue) {
    assert(queue != NULL);
    assert(queue->head != NULL);
    struct Node *data = NULL;
    if (queue->head->next == NULL) {
        data = queue->head->data;
        free(queue->head);
        queue->head = NULL;
    } else {
        struct QNode *e = queue->head->next;
        struct QNode *p = queue->head;
        while (e->next != NULL) {
            p = e;
            e = e->next;
        }
        data = e->data;
        free(e);
        p->next = NULL;
    }
    return data;
}

static bool not_empty(const struct Queue *queue) {
    assert(queue != NULL);
    return queue->head != NULL;
}

static void push(struct Stack *stack, struct Node *tree_node) {
    assert(stack != NULL);
    assert(tree_node != NULL);
    struct QNode *e = malloc(sizeof (struct QNode));
    assert(e != NULL);
    e->data = tree_node;
    e->next = NULL;
    if (stack->top == NULL) {
        stack->top = e;
    } else {
        e->next = stack->top;
        stack->top = e;
    }
}

static struct Node *pop(struct Stack *stack) {
    assert(stack != NULL);
    assert(stack->top != NULL);
    struct QNode *e = stack->top;
    stack->top = stack->top->next;
    struct Node *p = e->data;
    free(e);
    return p;
}

static bool stack_not_empty(const struct Stack *stack) {
    assert(stack != NULL);
    return stack->top != NULL;
}

struct Node *create_node(int node_data) {
    struct Node *node = malloc(sizeof(struct Node));
    assert(node != NULL);
    node->data = node_data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

static struct Node *find_node_by_loc(struct Node *root, const char *loc_address) {
    struct Node *c = root;
    const char *l = loc_address;
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

int insert(struct Node *root, char *loc_address, const char direction, const int node_data) {
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

void in_order_traverse(const struct Node *root) {
    if (root == NULL) {
        return;
    }
    if (root->left != NULL) {
        in_order_traverse(root->left);
    }
    printf("%d\n", root->data);
    if (root->right != NULL) {
        in_order_traverse(root->right);
    }
}

void pre_order_traverse(const struct Node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d\n", root->data);
    if (root->left != NULL) {
        pre_order_traverse(root->left);
    }
    if (root->right != NULL) {
        pre_order_traverse(root->right);
    }
}

void post_order_traverse(const struct Node *root) {
    if (root == NULL) {
        return;
    }
    if (root->left != NULL) {
        post_order_traverse(root->left);
    }
    if (root->right != NULL) {
        post_order_traverse(root->right);
    }
    printf("%d\n", root->data);
}

void level_order_traverse(struct Node *root) {
    struct Queue *queue = malloc(sizeof(struct Queue));
    assert(queue != NULL);

    enqueue(queue, root);
    while (not_empty(queue)) {
        const struct Node *tree_node = dequeue(queue);
        printf("%d\n", tree_node->data);
        if (tree_node->left != NULL) {
            enqueue(queue, tree_node->left);
        }
        if (tree_node->right != NULL) {
            enqueue(queue, tree_node->right);
        }
    }

    free(queue);
}

int node_count(const struct Node *root) {
    if (root == NULL) {
        return 0;
    }
    return node_count(root->left) + node_count(root->right) + 1;
}

int leaf_count(const struct Node *root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return leaf_count(root->left) + leaf_count(root->right);
}

int height(const struct Node *root) {
    if (root == NULL) {
        return 0;
    }
    int height_left = height(root->left);
    int height_right = height(root->right);

    return 1 + (height_left > height_right ? height_left : height_right);
}

bool balanced(const struct Node *root) {
    if (root == NULL) {
        return true;
    }
    if (root->left == NULL && root->right == NULL) {
        return true;
    }
    if (abs(height(root->left) - height(root->right)) > 1) {
        return false;
    }
    return balanced(root->left) && balanced(root->right);
}

// "balanced" function, optimized
int balanced_opt(const struct Node *root) {
    if (root == NULL) {
        return 0;
    }
    int height_left = balanced_opt(root->left);
    if (height_left == -1) {
        return -1;
    }
    int height_right = balanced_opt(root->right);
    if (height_right == -1) {
        return -1;
    }

    if (abs(height_left - height_right) > 1) {
        return -1;
    }
    return 1 + (height_left > height_right ? height_left : height_right);
}

bool balanced2(const struct Node *root) {
    return balanced_opt(root) != -1;
}

void in_order_traverse_non_rec(struct Node *root) {
    struct Stack *stack = malloc(sizeof(struct Stack));
    assert(stack != NULL);
    stack->top = NULL;
    struct Node *c = root;
    while (stack_not_empty(stack) || c != NULL) {
        while (c != NULL) {
            push(stack, c);
            c = c->left;
        }
        c = pop(stack);
        printf("%d\n", c->data);
        c = c->right;
    }
    free(stack);
}

void pre_order_traverse_non_rec(struct Node *root) {
    struct Stack *stack = malloc(sizeof(struct Stack));
    assert(stack != NULL);
    stack->top = NULL;
    push(stack, root);
    struct Node *c;
    while (stack_not_empty(stack)) {
        c = pop(stack);
        printf("%d\n", c->data);
        if (c->right != NULL) {
            push(stack, c->right);
        }
        if (c->left != NULL) {
            push(stack, c->left);
        }
    }
    free(stack);
}