#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "counter.h"

struct _counter {
    unsigned int count;
};

counter counter_init(void) {

 counter res = malloc (sizeof (struct _counter));
 res->count = 0;
 assert (counter_is_init(res));
 return res;
}

void counter_inc(counter c) {
 c->count= (c->count)+1;

}

bool counter_is_init(counter c) {
 return (c->count == 0u);
}

void counter_dec(counter c) {
    assert (!counter_is_init(c));
    c->count = (c->count)-1;
}

counter counter_copy(counter c) {
  counter res = malloc (sizeof (struct _counter));
  res->count = c->count;
  return res;
}


void counter_destroy(counter c) {
 free(c);
}
