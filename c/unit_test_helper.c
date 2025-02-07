#include "unit_test_helper.h"
#include <time.h>
#include <string.h>

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

char *concatenate(const char **strings, size_t count) {
    size_t total_length = 0;

    for (size_t i = 0; i < count; i++) {
        total_length += strlen(strings[i]);
    }

    char *result = malloc(total_length + 1);
    if (!result) return NULL;

    result[0] = '\0';

    for (size_t i = 0; i < count; i++) {
        strcat(result, strings[i]);
    }

    return result;
}
