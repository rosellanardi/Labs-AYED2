#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "strfuncs.h"

size_t string_length(const char *str) {
    unsigned int i=0;
    unsigned int length = 0;

     while (str[i] != '\0') {
        length++;
        i++;
     }
    
    return length;
}

char *string_filter(const char *str, char c) {
    char *res = malloc (sizeof (char)*string_length(str) + 1);
    unsigned int j = 0;
    
     for (unsigned int i = 0; i < string_length(str); i++) {
        if (str[i] != c) {
            res[j] = str[i];
            j++;
        }
    }

    return res;
}

bool string_is_symmetric(const char *str) {
    bool res = true;
    unsigned int i = 0;
    unsigned int j = string_length(str) - 1;

      while (i<=j && res) {
        if (str[i] == str[j]) {
            res = res && true;
            i++;
            j--;
            }
    else {
        res = false;
    }
 }
    return res;
}