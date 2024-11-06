#include <stdio.h>

void print_menu(void) {
    printf("The following operations are available:\n");
    printf("'a' - add two integers\n");
    printf("'d' - subtract one integer from another\n");
    printf("'m' - multiply two integers\n");
    printf("'x' - exit the system\n");
}

int add_integers(int a, int b) {
    return a + b;
}

int subtract_integers(int a, int b) {
    return a - b;
}

int multiply_integers(int a, int b) {
    return a * b;
}

int main(void) {

    printf("Welcome to console calculator!\n");
    printf("Version: 0.0.1\n");

    char op;
    while (1) {
        print_menu();
        printf("> ");
        scanf(" %c", &op);

        int a;
        int b;

        if (op == 'x') {
            break;
        }

        printf("op1 = ");
        scanf("%d", &a);
        printf("op2 = ");
        scanf("%d", &b);

        switch (op) {
            case 'a':
                printf("Result: %d\n", add_integers(a, b));
                break;
            case 'd':
                printf("Result: %d\n", subtract_integers(a, b));
                break;
            case 'm':
                printf("Result: %d\n", multiply_integers(a, b));
                break;
            default:
                printf("Unknown operation!");
        }

        op = '\000';
    }

    printf("Exiting...");
}
