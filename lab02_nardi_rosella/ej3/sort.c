#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    unsigned int piv, i, j;

    piv = izq;
    i = izq + 1;
    j = der;
    
    while (i <= j) {
        if(goes_before(a[i], a[piv])) {
            i++;
        }
        else if(goes_before(a[piv], a[j])) {
            j--;
        }
        else if(a[i] > a[piv] && a[j] < a[piv]){
            swap(a,i,j);
            i++;
            j--;
        }
    }
    swap(a,piv,j);

    piv = j;


   return piv;
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    if(der > izq) {

        unsigned int piv = partition(a,izq,der);
        quick_sort_rec(a, izq, piv == 0 ? piv : piv - 1);
        quick_sort_rec(a, piv == der ? der : piv + 1, der);
        
    }
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}


