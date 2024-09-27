#include <stddef.h>
#include <assert.h> 

size_t Str_getLength(const char *pcSrc) {
   const char *pcEnd;
   assert(pcSrc != NULL);
   pcEnd = pcSrc;
   while (*pcEnd != '\0')
      pcEnd++;
   return (size_t)(pcEnd - pcSrc);
}

char* Str_copy(char *pcDest, const char *pcSrc) {
    assert(pcDest != NULL); 
    assert(pcSrc != NULL); 
    char *pcDestStart = pcDest; /* save destination string's start */
    
    while (*pcSrc != '\0') {
        *pcDest = *pcSrc;
        pcDest++;
        pcSrc++;
    }
    *pcDest = '\0'; /* add the null terminator */

    return pcDestStart;;
}

char* Str_concat(char *pcStr1, const char *pcStr2) {
    assert(pcStr1 != NULL); 
    assert(pcStr2 != NULL);

    char *pcStr1Start = pcStr1;

    while (*pcStr1 != '\0') {
        *pcStr1 = *pcStr2; 
        pcStr1++; 
        pcStr2++; 
    }

    *pcStr1 = '\0'; /* add the null terminator */

    return pcStr1Start; 
}

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

char* Str_search(const char *pcHaystack, const char *pcNeedle) {
    assert(pcHaystack != NULL); 
    assert(pcNeedle != NULL); 

    /* handle empty strings*/
    if (*pcNeedle == '\0') {
        return (char*)pcHaystack;
    }

    return NULL; /* when Needle not found, return null */
}