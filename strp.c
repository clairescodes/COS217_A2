/*
 * strp.c
 * 
 * This module provides alternative implementations of 
 * string handling functions using pointer-based traversal. 
 * 
 * The functions include:
 * - Str_getLength: Returns the length of a string.
 * - Str_copy: Copies a string from source to destination.
 * - Str_concat: Concatenates two strings.
 * - Str_compare: Compares two strings lexicographically.
 * - Str_search: Searches for a substring within a string.
 */
#include <stddef.h>
#include <assert.h> 
#include "str.h"

/*
 * Str_getLength
 * 
 * Returns the length of the null-terminated string pointed to by 
 * pcSrc. The function uses pointer traversal to count characters 
 * until the null terminator is reached.
 */
size_t Str_getLength(const char *pcSrc) {
   const char *pcEnd;
   assert(pcSrc != NULL);
   pcEnd = pcSrc;
   while (*pcEnd != '\0')
      pcEnd++;
   return (size_t)(pcEnd - pcSrc);
}

/*
 * Str_copy
 * 
 * Copies the string pointed to by pcSrc to the buffer pointed to by 
 * pcDest, including the null terminator. The destination buffer must 
 * be large enough to hold the source string. Returns a pointer to 
 * the destination string, pcDest.
 */
char* Str_copy(char *pcDest, const char *pcSrc) {
    char *pcDestStart; /* save destination string's start */
    assert(pcDest != NULL); 
    assert(pcSrc != NULL);
    pcDestStart = pcDest; 
    
    while (*pcSrc != '\0') {
        *pcDest = *pcSrc;
        pcDest++;
        pcSrc++;
    }
    *pcDest = '\0'; /* add the null terminator */

    return pcDestStart;;
}


/*
 * Str_concat
 * 
 * Appends the string pointed to by pcStr2 to the end of 
 * string pointed to by pcStr1. Final string is null-terminated. 
 * Buffer for pcStr1 must be large enough to hold both strings. 
 * Returns a pointer to pcStr1.
 */
char* Str_concat(char *pcStr1, const char *pcStr2) {
    char *pcStr1Start; 
    assert(pcStr1 != NULL); 
    assert(pcStr2 != NULL);
    pcStr1Start = pcStr1;

    while (*pcStr1 != '\0') {
        *pcStr1 = *pcStr2; 
        pcStr1++; 
        pcStr2++; 
    }

    *pcStr1 = '\0'; /* add the null terminator */

    return pcStr1Start; 
}

/*
 * Str_compare
 * 
 * Compares two null-terminated strings, pcStr1 and pcStr2. 
 * Returns 0 if strings are identical; negative value if 
 * pcStr1 is (lexicographically) less than pcStr2; 
 * positive value if pcStr1 is greater.
 */
int Str_compare(const char *pcStr1, const char *pcStr2) {
    assert(pcStr1 != NULL); 
    assert(pcStr2 != NULL); 
    
    while (*pcStr1 != '\0' && *pcStr2 != '\0' && *pcStr1 == *pcStr2) {
        pcStr1++; 
        pcStr2++; 
    }
    
    /* return difference of the first different character */
    return (int)((unsigned char)*pcStr1 - (unsigned char)*pcStr2); 
}

/*
 * Str_search
 * 
 * Searches for the first occurrence of the string pcNeedle within 
 * string pcHaystack. Returns a pointer to the first occurrence of 
 * pcNeedle. Returns NULL if pcNeedle is not found.
 */
char* Str_search(const char *pcHaystack, const char *pcNeedle) {
    const char *pcH, *pcN;
    assert(pcHaystack != NULL); 
    assert(pcNeedle != NULL); 

    /* handle empty strings*/
    if (*pcNeedle == '\0') {
        return (char*)pcHaystack;
    }

    while (*pcHaystack != '\0') {
        pcH = pcHaystack;
        pcN = pcNeedle;

        while (*pcN != '\0' && *pcH == *pcN) {
            pcH++;
            pcN++;
        }

        if (*pcN == '\0') {
            return (char *)pcHaystack;
        }

        pcHaystack++;
    }

    return NULL; /* when Needle not found, return null */
}