#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

struct _node {
    list_elem elem;
    struct _node *next;
};

/*constructors*/

list list_init(void) {
    list l = NULL;
    return l;    
}


list addl(list l, list_elem e){
    list new_node = malloc(sizeof(struct _node));
    new_node->elem = e;
    new_node->next = l;
    return new_node;
}

/*destroy*/

void list_destroy(list l) {
    list p, q;
    q = NULL;
    p = l;
    while (p != NULL) {
        q=p;
        p = p->next;
        free(q);
    }
    free(l);
    l=NULL;
}


/*operations*/

bool list_is_empty(list l) {
    return (l == list_init());
}

list_elem head (list l) {
    assert(!list_is_empty(l));
    return(l->elem);
}


list tail (list l) {
    assert(!list_is_empty(l));
    list p;
    p = l;
    l = l->next;
    free(p);
    return l;
}


list addr(list l,list_elem e){
    list p;
    list q;

    q = malloc(sizeof(struct _node));

    p=l;

    q->elem = e;
    q->next = NULL;

    if (list_is_empty(l)){
        l = q;
    }
    else {
        while(p->next!=NULL){
            p=p->next;
        }
        p->next = q;
    }

    return l;
}

unsigned int lenght (list l) {
    unsigned int lenght = 0;
    list p;
    p = l;
    while (p != NULL) {
        lenght = lenght + 1;
        p = p->next;
    }
    return lenght;
}


list concat (list l,list l0) {
    list p;
    p = l;
    while (p != NULL) {
        p = p->next;
    }
    p->next = l0;
    free(p);
    return l;
}


list_elem index(list l, unsigned int n) {
    assert(lenght(l) > n);
    list p;
    unsigned int i = 1;
    while (p != NULL && i < n) {
        p = p->next;
        i++;
    }
    return (p->elem);
}

list take(list l, unsigned int n) {
 list p;
 p=l; 
 while (lenght(l)-n > 0)
  {
     while (p->next!= NULL) {
      p=p->next;
      }
    free(p);
  }
 return l;
 }
 
list drop(list l, unsigned int n) {
    list p;
    unsigned int i = 0;
      while (i<n) {
        p=l; 
        l=l->next;
        free(p);
        i++;
      }
    return l;
}

list copy_list(list l) {
    list copy_l = list_init();
    list p = l;
    unsigned int i = 0;

    while (i<lenght(l) && p != NULL) {
        copy_l = addr(copy_l,p->elem);
        p = p->next;
    }

    return copy_l;
}
