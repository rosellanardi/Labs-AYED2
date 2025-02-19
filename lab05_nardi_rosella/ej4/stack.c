#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "stack.h"
 
 struct _s_stack {
 stack_elem elem;
 struct _s_stack *next;
 };
 
 
stack stack_empty() {
 stack s = NULL;
 return s;
 }

stack stack_push(stack s, stack_elem e) {
  stack p = malloc (sizeof(struct _s_stack));
  p->elem=e;
  p->next=s;
  return p;
  }
 
stack stack_pop (stack s) {
 if(!stack_is_empty(s)) {
 stack p;
 p=s;
 s=s->next;
 free(p);
 }
 return s;
 }
 
unsigned int stack_size(stack s) {
stack p;
p=s;
unsigned int length = 0;

 while (p!=NULL) {
 length = length+1;
 p=p->next;
 }
 
return length;
}

stack_elem stack_top(stack s) {
 assert (!stack_is_empty(s));
return s->elem;
}
 
bool stack_is_empty(stack s) {
return (s==NULL);
}

stack_elem *stack_to_array(stack s) {
stack_elem *arr;
stack p = s;

 if (stack_is_empty(s)) {
 arr=NULL;
 }
 else {
 arr = calloc (stack_size(s), sizeof (stack_elem));
 for (int i=(stack_size(s))-1; i>=0; --i) {
 arr[i] = stack_top(p);
 p = p->next;
 }
 }

return arr;
}

stack stack_destroy(stack s){
    stack p;
    while (s != NULL){
        p = s;
        s = s->next;
        free(p);
    }
    return s;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
