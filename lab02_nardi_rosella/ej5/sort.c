#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"
#include "fixstring.h"


static unsigned int partition(fixstring a[], unsigned int izq, unsigned int der) {

    unsigned int pivote = izq;
    unsigned int i = izq + 1;
    unsigned int j = der;
    
    while (i <= j) {
        if(goes_before(a[i], a[pivote])) {
            i += 1u;
        }
        else if(goes_before(a[pivote], a[j])) {
            j -= 1u;
        }
        else if(goes_before(a[pivote], a[i]) && goes_before(a[j], a[pivote])){
            swap(a, i, j);
            i += 1u;
            j -= 1u;
        }
    }
    swap(a,pivote,j);

    pivote = j;


   return pivote;
}

static void quick_sort_rec(fixstring a[], unsigned int izq, unsigned int der) {
    if(der > izq) {
        unsigned int pivote = partition(a,izq,der);
        quick_sort_rec(a, izq, pivote == 0 ? pivote : pivote - 1);
        quick_sort_rec(a, pivote == 0 ? der : pivote + 1, der);
    }
}

void quick_sort(fixstring a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}


