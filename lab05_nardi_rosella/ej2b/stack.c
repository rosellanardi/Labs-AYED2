#include <stdlib.h>
#include <assert.h>
#include "stack.h"
 
struct _s_stack {
    stack_elem top;
    struct _s_stack *next;
    unsigned int size;
};


bool inv(stack s) {
    bool res = (s->size > 0);
    return res;
}


stack stack_empty() {
    stack s;
    s = NULL;
    return s;
}

/**
* @brief Inserts an element at the top of the stack
* @param s A stack
* @param e An element to push into the stack
* @return The new stack with 'e' at the top
*/
stack stack_push(stack s, stack_elem e) {
    stack new_node = malloc (sizeof (stack_elem));

     if(stack_is_empty((s))) {
        new_node->size = 1;
        }

    new_node->top = e;
    new_node->next = s;
    new_node->size++;
    return new_node;
}

/**
* @brief Removes the element at the top of the stack
* @param s A stack
* @return The new stack with the top element removed
* @note Only applies to non-empty stacks
*/
stack stack_pop(stack s) {
    assert(!(stack_is_empty(s)));
    stack p;
    p = s;
    if (s->next == NULL) {
        s->size = 0;
    }
    else {
        s->size--;
    }
    s = s->next;
    free(p);
    return s;
}

/**
* @brief Returns the size of the stack
* @param s A stack
* @return The size of the stack
*/
unsigned int stack_size(stack s) {
    /*stack p;
    p = s;
    unsigned int size = 0;
    while (p != NULL) {
        size++;
        p = p->next;
    }*/
    return (s->size);
}

/**
* @brief Returns the element at the top of the stacks
* @param s A stacks
* @return The element at the top of the stack
* @note Only applies to non-empty stacks
*/
stack_elem stack_top(stack s) {
    assert (!stack_is_empty(s));
    return s->top;
}
/**
* @brief Check if the given stack is empty
* @param s A stack
* @return true if the stack is empty, false otherwise
*/
bool stack_is_empty(stack s) {
    return (s == NULL);
}

/**
* @brief Creates an array with all the elements of the stack
* @param s A stack
* @return An array containing all the elements of the stack. The stack top element
* becomes the rightmost element of the array. The size of the resulting
* array is determined by 'stack_size(s)'
*/
stack_elem *stack_to_array(stack s) {
    int size = stack_size(s);

    if(size == 0) {
        return NULL;
    }

    stack_elem *array = calloc(size, sizeof(stack_elem));
    for (int i = size - 1; i >= 0; i--)
    {
        array[i] = s->top;
        s = s->next;
    }
    return array;   
}

/**
* @brief Destroys the stack
* @param s A stack
* @note All memory resources are freed
*/
stack stack_destroy(stack s) {
    while (!stack_is_empty(s))
    {
        s = stack_pop(s);
    }
    free(s);
    return s;
}
    