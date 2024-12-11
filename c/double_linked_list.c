#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

struct Node {
    int id;
    char data[256];
    struct Node *next;
    struct Node *prev;
};

struct Node *first;

void print_menu() {
    puts("============================");
    puts("Available operations:");
    puts("============================");

    puts("'a' - add a new node");
    puts("'r' - remove a node");
    puts("'i' - insert a new node");
    puts("'u' - update a node");
    puts("'c' - count how many nodes are present");
    puts("'e' - erase the list");
    puts("'s' - show a specific node (string field)");
    puts("'v' - view all list");
    puts("'d' - print list debug");
    puts("'x' - exit the system");
}

bool id_already_present(int id) {
    if (first == NULL) {
        return false;
    }
    struct Node *c = first;
    while (c != NULL) {
        if ( c->id == id) {
            return true;
        }
        c = c->next;
    }
    return false;
}

void add_node() {
    struct Node *node;
    node = malloc(sizeof (struct Node));

    puts("Enter node data:");
    puts("id = ");
    scanf("%d", &node->id);
    assert(node->id > 0);
    if (id_already_present(node->id)) {
        puts("This id already exits!");
        free(node);
        return;
    }
    puts("data = ");
    scanf("%s", node->data);

    node->next = NULL;
    node->prev = NULL;

    puts("You have entered:");
    printf("id = %d\n", node->id);
    printf("data = %s\n", node->data);

    if (first == NULL) {
        first = node;
    } else {
        struct Node *c = first;
        while (c->next != NULL) c = c->next;
        c->next = node;
        node->prev = c;
    }
}

void view_all_list() {
    if (first == NULL) {
        puts("The list is empty.");
        return;
    }
    struct Node *c = first;
    while (c != NULL) {
        printf("id = %d\n", c->id);
        printf("data = %s\n", c->data);
        puts("-----------------------");
        c = c->next;
    }
}

void count() {
    if (first == NULL) {
        puts("The list is empty.");
        return;
    }
    int n = 1;
    struct Node *c = first;
    while (c->next != NULL) {
        ++n;
        c = c->next;
    }
    printf("Total number of elements is : %d\n", n);
}

void erase_all_list() {
    if (first == NULL) {
        puts("The list is empty. Nothing to erase.");
        return;
    }
    struct Node *c = first;
    struct Node *n = first->next;
    while (c != NULL) {
        free(c);
        c = n;
        if (n != NULL) {
            n = n->next;
        }
    }
    first = NULL;
}

void show_node() {
    if (first == NULL) {
        puts("The list is empty, nothing to show.");
        return;
    }
    puts("Show data for node");
    puts("id = ");
    int id;
    scanf("%d", &id);
    assert(id > 0);
    struct Node *c = first;
    while (c != NULL) {
        if (id == c->id) {
            printf("The node info is : %s\n", c->data);
            return;
        }
        c = c->next;
    }
    printf("There is no node with id %d\n", id);
}

void remove_node() {
    puts("Node id to be erased>");
    int id;
    scanf("%id", &id);
    assert(id > 0);
    struct Node *c = first;
    while (c != NULL) {
        if (id == c->id) {
            if (c->next != NULL) {
                c->next->prev = c->prev;
            }
            if (c->prev != NULL) {
                c->prev->next = c->next;
            }
            free(c);
            printf("Node with id %d, has been erased!\n", id);
            return;
        }
        c = c->next;
    }
    printf("Couldn't find node with id = %d\n", id);
}

void update_node() {
    puts("Node id which will be updated>");
    int id;
    scanf("%d", &id);
    assert(id > 0);
    struct Node *c = first;
    while (c != NULL) {
        if (id == c->id) {
            // we found our node
            puts("Provide new data string = ");
            scanf("%s", c->data);
            puts("The node has been update successfully.");
            return;
        }
        c = c->next;
    }
    printf("Couldn't find node with id = %d\n", id);
}

void insert() {
    puts("Give me the node id after which this one will be inserted>");
    int id_after;
    scanf("%d", &id_after);
    assert(id_after > 0);

    struct Node *node;
    node = malloc(sizeof(struct Node));
    puts("Enter node data:");
    puts("id = ");
    scanf("%d", &node->id);
    assert(node->id > 0);
    if (id_already_present(node->id)) {
        puts("This id already exits!");
        free(node);
        return;
    }
    puts("data = ");
    scanf("%s", node->data);
    node->next = NULL;

    struct Node *c = first;
    while (c != NULL) {
        if (c->id == id_after) {
            // we find our node, so next we neet to insert the new node after this one
            node->next = c->next;
            node->prev = c;
            c->next = node;
        }
        c = c->next;
    }
    printf("There is no node with id = %d\n", id_after);
    free(node);
}

void print_list_debug(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("Node at address: %p\n", (void*)current);
        printf("├── id: %d\n", current->id);
        printf("├── data: %s\n", current->data);
        printf("├── next: %p\n", (void*)current->next);
        printf("└── prev: %p\n", (void*)current->prev);
        current = current->next;
    }
}

int main(void) {
    char op = '\0';

    while (1) {
        print_menu();
        puts("Your input>");
        // Skip any newline characters
        while ((op = getchar()) == '\n');

        // Clear the rest of the input buffer
        while (getchar() != '\n');
        // clear new line

        if (op == 'x') {
            puts("Exiting...");
            break;
        }

        switch (op) {
            case 'a':
                add_node();
                break;
            case 'r':
                remove_node();
                break;
            case 'i' :
                insert();
                break;
            case 'u':
                update_node();
                break;
            case 'c':
                count();
                break;
            case 'e':
                erase_all_list();
                break;
            case 's':
                show_node();
                break;
            case 'v':
                view_all_list();
                break;
            case 'd':
                print_list_debug(first);
            default:
                puts("Unknown operations!");
        }
    }
}
