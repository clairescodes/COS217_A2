/* 
 * str.h                                                            
 *                                                                  
 * Contains declarations for functions that mimic standard 
 * C string library functions like getting the length, copying
 * one string to another, concatenating, comparing, and searching 
 * for a substring.                                           
 */

#ifndef STR_H
#define STR_H

#include <stddef.h> 


/*
 * Str_getLength                                                      
 *                                                                   
 * Takes a pointer to a null-terminated string, pcSrc, and returns  
 * the length of the string, which is the number of characters before
 * the null terminator. 
 */                                             
size_t Str_getLength(const char pcSrc[]);

/* 
 * Str_copy                                                           
 *                                                                   
 * Copies string pointed to by pcSrc to the buffer pointed to by 
 * pcDest, including null terminator. The destination buffer should 
 * be large enough to contain source string. Returns pointer to  
 * the destination string, pcDest.                                   
*/
char* Str_copy(char pcDest[], const char pcSrc[]);

/* 
 * Str_concat                                                        
 *                                                                    
 * Appends the string pointed to by pcString2 to the end of 
 * the string pointed to by pcString1. Ensures the final string 
 * is null-terminated.
 * String1 buffer must be large enough to hold both the       
 * original and appended strings. Returns a pointer to String1.                                       
*/
char* Str_concat(char pcString1[], const char pcString2[]); 

/* 
 * Str_compare                                                        
 *                                                                    
 * Compares two null-terminated strings pcString1 and pcString2. 
 * Returns 0 if strings are identical; negative value if pcString1 
 * is less than pcString2; positive value if pcString1 is greater 
 * than pcString2.
 */
int Str_compare(const char pcString1[], const char pcString2[]); 

/* 
 * Str_search                                                       
 *                                                                   
 * Searches for the first occurrence of the string pcNeedle within  
 * the string pcHaystack. Returns a pointer to the first occurrence 
 * of pcNeedle in pcHaystack. Returns NULL if not found.  
 */
char* Str_search(const char pcHaystack[], const char pcNeedle[]);

#endif 