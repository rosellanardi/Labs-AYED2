#ifndef _SRTFUNCS_H
#define _SRTFUNCS_H

#include <stdbool.h>

size_t string_length(const char *str);
/*calculate the length of the string pointed to by str*/

char *string_filter(const char *str, char c);
/*returns a new string in dynamic memory that is obtained by taking the characters from str
which are different from the character c*/

bool string_is_symmetric(const char *str);
/*indicates whether the string pointed to by str is symmetric in that the first character matches the
last, the second with the penultimate, etc; such as the strings "aba", "abcba", "a", "".*/


#endif