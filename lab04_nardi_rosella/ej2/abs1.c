#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int y) {
    if (x >= 0) {
    y = x;
    }
    else {
    y = -1 * x;
    }
}

int main(void) {
    int a=0, res=0;
    a = -10;
    absolute(a,res);
    
    printf("%d\n", res);
    return EXIT_SUCCESS;
}

/*El valor que se muestra es 0, y tendria que ser 10. 
Yo en realidad tuve que sacar el -Werror y el -Wextra cuando lo ejecute, 
porque te salta que no estas usando la variable 'y' en la funcion absolute. */

