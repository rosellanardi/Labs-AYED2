#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


#include "stack.h"


int main () {

stack s;

s = stack_empty();

s = stack_push(s,1);

 printf("El elemento de S es %d\n", stack_top(s));
 
stack_pop(s);

  printf("El elemento de S fue eliminado\n");

stack_push(s,3);

 printf("Se agrego el elemento  %d a s\n ", stack_top(s));
 
stack vacia;
vacia = stack_empty();
 
stack_elem *se = stack_to_array(vacia);
 if (se==NULL) 
 {
 printf("La funcion stack to array devuelve null para una pila vacia\n");
 }
 
vacia = stack_push(vacia,1);
vacia = stack_push(vacia,2);
vacia = stack_push(vacia,3);

se = stack_to_array(vacia);

 for (unsigned int i = 0; i < stack_size(vacia); i++) {
      printf("La funcion stack_to_array de un arreglo no vacio devuelve: %d en la posicion %u\n", se[i], i);
    }
    
 return 0;
}






