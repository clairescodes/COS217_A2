/*
 * stra.c
 * 
 * Provides implementations of common string handling functions 
 * using array-based indexing. 
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
 * Returns the length of the string pcSrc, excluding the 
 * null terminator. The parameter pcSrc is a pointer to a 
 * null-terminated string. The function returns the 
 * length of the string as a size_t value.
 */
size_t Str_getLength(const char pcSrc[]) {
   size_t uLength = 0;
   assert(pcSrc != NULL);
   while (pcSrc[uLength] != '\0')
       uLength++;
   return uLength;
}


/*
 * Str_copy
 * Copies the string pcSrc to pcDest, including the null terminator.
 * pcDest is a pointer to a buffer where the copied string 
 * is stored and pcSrc is a pointer to the null-terminated string 
 * to be copied. The function returns a pointer to the destination 
 * string which is pcDest.
 */
char* Str_copy(char pcDest[], const char pcSrc[]) {
    size_t i = 0; 
    assert(pcDest != NULL); 
    assert(pcSrc != NULL); 
    while (pcSrc[i] != '\0') {
        pcDest[i] = pcSrc[i]; 
        i++; 
    }
    pcDest[i] = '\0'; /* add the null terminator */
    return pcDest;
}

/*
 * Str_concat
 * 
 * Appends the string pointed to by pcString2 to the end of the string 
 * pointed to by pcString1. The final string is null-terminated, and 
 * the buffer for pcString1 must be large enough to hold both the 
 * original and appended strings. Returns a pointer to pcString1.
 */
char* Str_concat(char pcString1[], const char pcString2[]) {
    size_t lenString1 = 0; /* length of string 1 */
    size_t i = 0; 
    assert(pcString1 != NULL); 
    assert(pcString2 != NULL); 
    
    /* measure length of string 1 */
    while (pcString1[lenString1] != '\0') {
        lenString1++; 
    }

    while (pcString2[i] != '\0') {
        pcString1[lenString1 + i] = pcString2[i]; 
        i++; 
    }
    pcString1[lenString1 + i] = '\0'; /* add the null terminator */

    return pcString1; 
}

/*
 * Str_compare
 * 
 * Compares two null-terminated strings, pcString1 and pcString2. 
 * Returns 0 if the strings are identical, a negative value if 
 * pcString1 is lexicographically less than pcString2, and a positive 
 * value if pcString1 is greater.
 */
int Str_compare(const char pcString1[], const char pcString2[]) {
    size_t i = 0; 
    assert(pcString1 != NULL); 
    assert(pcString2 != NULL); 
    
    /* find index i where first unmatching character occurs */
    while (pcString1[i] != '\0' && pcString2[i] != '\0') {
        if (pcString1[i] != pcString2[i]) {
            return (int)((unsigned char)pcString1[i] 
            - (unsigned char)pcString2[i]);
        }
        i++;
    }
    
    /* return difference of the first different character */
    return (int)((unsigned char)pcString1[i] 
    - (unsigned char)pcString2[i]); 
}

/*
 * Str_search
 * 
 * Searches for the first occurrence of the string pcNeedle within the 
 * string pcHaystack. Returns a pointer to the first occurrence of 
 * pcNeedle, or NULL if pcNeedle is not found.
 */
char* Str_search(const char pcHaystack[], const char pcNeedle[]) {
    size_t i, j; 
    assert(pcHaystack != NULL); 
    assert(pcNeedle != NULL); 

    /* handle empty strings*/
    if (pcNeedle[0] == '\0') {
        return (char*)pcHaystack;
    }

    for (i = 0; pcHaystack[i] != '\0'; i++) {
        for (j = 0; pcNeedle[j] != '\0'; j++) {
            if (pcHaystack[i + j] != pcNeedle[j]) {
                break; /* exit once mismatch is found */
            }
        }
        /* case when full needle found */
        if (pcNeedle[j] == '\0') {
            return (char*)&pcHaystack[i];
        }
    }

    return NULL; /* when Needle not found, return null */
}