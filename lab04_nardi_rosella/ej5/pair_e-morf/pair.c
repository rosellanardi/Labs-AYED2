#include <stdlib.h>  
#include <stdio.h>  
#include "pair.h" 

struct s_pair_t {
    elem fst;
    elem snd;
};

pair_t pair_new(elem x, elem y) {
  pair_t res = malloc (sizeof (struct s_pair_t));
  res->fst=x;
  res->snd=y;
  return res;
  }

int pair_first(pair_t p) {
   return p->fst;
}

int pair_second(pair_t p) {
 return p->snd;
}

pair_t pair_swapped(pair_t p) {
 elem first = p->fst;
 elem second = p->snd;
 pair_t swap = pair_new(second,first);
  
  return swap;
}

pair_t pair_destroy(pair_t p) {
 free(p);
 p = NULL;
 return p;
}
