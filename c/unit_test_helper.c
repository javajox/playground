#include "unit_test_helper.h"
#include <stdio.h>
#include <time.h>

#define ALPHANUM "abcdefghijklmnopqrstuvwxyz0123456789"

char *generate_random_string(size_t length) {
    char *random_string = malloc(length * sizeof(char));
    size_t alphanum_len = sizeof(ALPHANUM) - 1;

    for (size_t i = 0; i < length; i++) {
        random_string[i] = ALPHANUM[rand() % alphanum_len];
    }
    random_string[length] = '\0';

    return random_string;
}
