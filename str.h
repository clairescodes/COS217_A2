#ifndef STR_H
#define STR_H

#include <stddef.h> 

size_t Str_getLength(const char pcSrc[]);
char* Str_copy(char pcDest[], const char pcSrc[]);
char* Str_concat(char pcDest[], const char pcSrc[]);
int Str_compare(const char pcStr1[], const char pcStr2[]);
char* Str_search(const char pcHaystack[], const char pcNeedle[]);

#endif 