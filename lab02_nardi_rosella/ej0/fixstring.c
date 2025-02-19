#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s) {
    unsigned int i=0;
    unsigned int length = 0;

    while (s[i] != '\0') {
        length++;
        i++;
    }
    
    return length;
}

bool fstring_eq(fixstring s1, fixstring s2) {
    bool iguales = true;
    unsigned int length1 = fstring_length(s1);
    unsigned int length2 = fstring_length(s2);
    
    for(unsigned int i = 0; i < length1; i++) {
        if(s1[i] != s2[i] || length1 != length2) {
            iguales = false;
        }
    }

    return iguales;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    
    bool menor_igual = true;

     for(unsigned int i = 0; s1[i] != '\0' || s2[i] != '\0'; i++) {
        if(s1[i] < s2[i]) {
            return menor_igual;
        } else if(s1[i] > s2[i]){
            menor_igual = false;
            return false;
        } 
    }

    return menor_igual;
}

