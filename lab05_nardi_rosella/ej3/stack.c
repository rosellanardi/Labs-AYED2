#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct _s_stack {
    stack_elem *elems;      // Arreglo de elementos
    unsigned int size;      // Cantidad de elementos en la pila
    unsigned int capacity;  // Capacidad actual del arreglo elems
};

bool invrep (stack s) {
 return (s->capacity >= s->size);
}

stack stack_empty() {
stack s = malloc (sizeof(struct _s_stack));

s->capacity=1;
s->size=0;
s->elems = calloc ((s->capacity), sizeof(stack_elem));
 
return s;
}

stack stack_push(stack s, stack_elem e) {
 
 s->size++;

   if (s->size > s->capacity) {
    s->elems = realloc (s->elems, sizeof(stack_elem)*(s->capacity*2));
    s->capacity = s->capacity*2;
    }

 s->elems[s->size-1] = e;
 assert(invrep(s));
 return s;
}

stack stack_pop(stack s) {

  assert(s != NULL);

  s->size = s->size-1;
 assert(invrep(s));
  return s;

}

unsigned int stack_size(stack s) {
  assert(invrep(s));
return (s->size);
}


stack_elem stack_top(stack s) {
 assert(invrep(s));
 return (s->elems[s->size-1]);
}

bool stack_is_empty(stack s) {
  assert(invrep(s));
 return (s->size == 0);
}

stack_elem *stack_to_array(stack s) {
  stack_elem *arr = calloc (s->size, sizeof(int));
  
  for( unsigned int i = 0; i < s->size ;i++){
        arr[i] = s->elems[i];
    }
     assert(invrep(s));
  return arr;
}

stack stack_destroy(stack s) {
 free(s);
 free (s->elems);
 return s;
}


















