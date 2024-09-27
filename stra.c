#include <stddef.h>
#include <assert.h> 

size_t Str_getLength(const char pcSrc[]) {
   size_t uLength = 0;
   assert(pcSrc != NULL);
   while (pcSrc[uLength] != '\0')
       uLength++;
   return uLength;
}

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

char* Str_concat(char pcString1[], const char pcString2[]) {
    size_t lenString1; /* length of string 1 */
    size_t i = 0; 
    
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

int Str_compare(const char pcString1[], const char pcString2[]) {
    size_t i = 0; 
    assert(pcString1 != NULL); 
    assert(pcString2 != NULL); 
    
    /* find index i where first unmatching character occurs */
    while (pcString1[i] != '\0' && pcString2[i] != '\0' ) {
        i++; 
    }
    
    /* return difference of the first different character */
    return pcString1[i] - pcString2[i]; 
}

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