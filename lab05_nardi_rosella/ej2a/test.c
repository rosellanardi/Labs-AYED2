#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

int main(void) {
    stack s = stack_empty();

    s = stack_push(s, 10);
    s = stack_pop(s);

    if(stack_is_empty(s)) {
        printf("La pila esta vacia despues de stack_pop\n");
    }
    else {
          printf("Stack pop no funciona con lista size 1\n");
    }

    s = stack_push(s, 40);
    if(!stack_is_empty(s)) {
        printf("Puedo volver a insertar elementos en la pila vacia\n");
    }


    s = stack_push(s, 50);
    
    stack_elem *array = stack_to_array(s);
    if(array == NULL) {
        printf("EL array es NULL para una pila vacia \n");
    } else {
        printf("EL tope de la pila es: %d\n", array[0]);
        free(array);
    }

    s = stack_destroy(s);

    return 0;
}
