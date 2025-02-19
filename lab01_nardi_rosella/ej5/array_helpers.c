#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "array_helpers.h"
#include "mybool.h"

unsigned int array_from_file(int array[], unsigned int max_size, const char *filepath) {

    FILE *file = fopen(filepath,"r");
    fscanf(file, "%u", &max_size);
    fgetc(file);
    
    for (unsigned int i=0; i < max_size; i++) {
        fscanf(file, "%d", &array[i]);
    }
    
    fclose(file);
    return max_size;
}

void array_dump(int a[], unsigned int length) {

    printf ("[");
    for (unsigned int i = 0; i < length ; i++) {
          printf("%d", a[i]);
          if(i < length - 1) {
            printf(",");
        }
    }
    printf("]\n");

}

bool array_is_sorted(int a[], unsigned int length) {

    bool res = true;
    for (unsigned int i = 0; i < length - 1 ; i++)  {
        if (a[i]<a[i+1]) {
            res = res && true;
        }
        else {
            res = res && false;
        }
    }
    return res;
}
