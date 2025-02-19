#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void absolute(int x, int *y) {
    if (x >= 0) {
    *y = x;
    }
    else {
    *y = -1 * x;
    }
}

int main(void) {
    int a=0, res=0;
    a = -10;
    
    absolute(a,&res);
    
    printf("%d\n", res);
    return EXIT_SUCCESS; // No modificar esta declaración
    // --- No se deben declarar variables nuevas ---

    //
    // Completar aquí
    //
    assert(res >= 0 && (res == a || res == -a));
    return EXIT_SUCCESS;
}

/*Si se muestra el valor correcto*/


/*c) Para pensar:
¿El parámetro int *y de absolute() es de tipo in, de tipo out o de tipo in/out?
-El parametro es de tipo out, ya que se usa para devolver el resultado nomas. Su valor inicial
no se usa para nada.
Qué tipo de parámetros tiene disponibles C para sus funciones?
Parámetros in, Parámetros out, Parametros in/out.*/












