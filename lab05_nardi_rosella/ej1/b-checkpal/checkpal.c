#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "strfuncs.h"

#define MAX_LENGTH 20

#define SIZEOF_ARRAY(s) (sizeof(s) / sizeof(*s))

int main(void) {
    char user_input[MAX_LENGTH];
    char ignore_chars[] = {' ', '?', '!', ',', '-', '.'};
    char *filtered=NULL;

    printf("Ingrese un texto (no más de %d símbolos) para verificar palíndromo: ", MAX_LENGTH);
    filtered = fgets (user_input, MAX_LENGTH, stdin);
    //scanf("%s", user_input);
      
    size_t length = string_length(user_input);

    for (unsigned int i=0; i < length; i++) {
        if (user_input[i] == '\n') {
            user_input[i] = '\0';    
        }
    }

   filtered = string_filter(user_input, ignore_chars[0]);  
     for (unsigned int i = 1; i < SIZEOF_ARRAY(ignore_chars); i++) {
        char *temp = string_filter(filtered, ignore_chars[i]);  
        free(filtered);                                       
        filtered = temp;                                    
        }

    printf("El texto:\n\n"
            "\"%s\" \n\n"
            "%s un palíndromo.\n\n", user_input, string_is_symmetric(filtered) ? "Es": "NO es");
    free(filtered);

    return EXIT_SUCCESS;
}

