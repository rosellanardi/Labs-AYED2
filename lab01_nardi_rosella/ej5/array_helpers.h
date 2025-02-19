#ifndef ARRAY_HELPERS_H
#define ARRAY_HELPERS_H
#include "mybool.h"

/* Parse the file, fill the array and get the actual length */
unsigned int array_from_file(int array[], unsigned int max_size, const char *filepath);

/*Dump the array*/
void array_dump(int a[], unsigned int length);

/*Is it ordered in ascending order?*/
bool array_is_sorted(int a[], unsigned int length);

#endif
