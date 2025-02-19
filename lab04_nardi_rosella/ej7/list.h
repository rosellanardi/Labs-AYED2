#ifndef _LIST_H
#define _LIST_H


typedef int list_elem;
typedef struct _node *list; /* list as a pointer to structs to guarantee encapsulation */


/*constructors*/

list list_init(void);
/* 
Create a new list. Allocates new memory.
 list_is_init(l) should be true. 
*/

list addl(list l, list_elem e);
/*
Adds an element to the left of the list.
*/


/*destroy*/

void list_destroy(list l);
 /* Frees memory for l.*/


/*operations*/

bool list_is_empty(list);
/*
Return true if l is empty
*/

list_elem head (list l);
/*
    Return the first element of the list.
    PRECONDITION: !list_is_empty(l)
*/

list tail (list l);
/*
    Delete the first element of the list.
    PRECONDITION: !list_is_empty(l)
*/

list addr(list l,list_elem e);
/*
    Adds an element to the right of the list l.
*/

unsigned int lenght (list l);
/* 
   Return the number of elements of the list l.
*/

list concat (list l,list l0);
/*
 Add all the elements of l0 to the end of l in the same order.
*/

list_elem index(list l, unsigned int n);
/*
    Return rhe nth element of the list l.
 PRECONDITION: length(l) > n 
*/

list take(list l, unsigned int n);
/*
 Leave in l, only the first n elements, eliminating the rest
*/

list drop(list l, unsigned int n);
/*
  Remove the first n elements from l
*/

list copy_list(list l);
/* Copy all elements from l1 to the new list l2.*/

#endif
