#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"


unsigned int fstring_length(fixstring s) {

    unsigned int lenght = 0;

    for(unsigned int i = 0; i < FIXSTRING_MAX && s[i] != '\0'; i++) {
        lenght++;
    }

    return lenght;
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
    bool menorIgualQue = true;
    
    for(unsigned int i = 0;s1[i] != '\0' || s2[i] != '\0'; i++) {
        if(s1[i] < s2[i]) {
            return menorIgualQue;
        } else if(s1[i] > s2[i]){
            menorIgualQue = false;
            return false;
        } 
    }

    return menorIgualQue;
}

void fstring_set(fixstring s1, const fixstring s2) {
    int i = 0;
    while (i < FIXSTRING_MAX && s2[i] != '\0') {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

void fstring_swap(fixstring s1,  fixstring s2) {
    fixstring aux;
    
    fstring_set(aux, s1);
    fstring_set(s1, s2);
    fstring_set(aux, s2);
    
}


