/*--------------------------------------------------------------------*/
/* str.h                                                              */
/*                                                                    */
/* This header file contains declarations for string                  */
/* manipulation functions that mimic standard C string library        */
/* functions, including getting the length of a string,               */
/* copying one string to another, concatenating two strings,          */
/* comparing two strings, and searching for a substring within        */
/* another string.                                                    */
/*--------------------------------------------------------------------*/

#ifndef STR_H
#define STR_H

#include <stddef.h> 

/*--------------------------------------------------------------------*/
/* Str_getLength                                                      */
/*                                                                    */
/* This function returns the length of the null-terminated string     */
/* pointed to by pcSrc. The length is calculated as the number of     */
/* characters before the null terminator, and this length is returned */
/* as a size_t value. The function does not produce any output to     */
/* stdout or stderr.                                                  */
/*--------------------------------------------------------------------*/
size_t Str_getLength(const char pcSrc[]);

/*--------------------------------------------------------------------*/
/* Str_copy                                                           */
/*                                                                    */
/* This function copies the string pointed to by pcSrc into the       */
/* buffer pointed to by pcDest, including the null terminator. The    */
/* destination buffer must be large enough to hold the source string. */
/* It returns a pointer to the destination string (pcDest) after      */
/* copying. There is no direct interaction with stdout or stderr.     */
/*--------------------------------------------------------------------*/
char* Str_copy(char pcDest[], const char pcSrc[]);

/*--------------------------------------------------------------------*/
/* Str_concat                                                         */
/*                                                                    */
/* This function appends the string pointed to by pcSrc to the end of */
/* the string pointed to by pcDest, ensuring that the final string is */
/* null-terminated. The destination buffer must be large enough to    */
/* hold both the original and appended strings. The function returns  */
/* a pointer to the destination string (pcDest) after concatenation.  */
/* No output is written to stdout or stderr.                          */
/*--------------------------------------------------------------------*/
char* Str_concat(char pcDest[], const char pcSrc[]);

/*--------------------------------------------------------------------*/
/* Str_compare                                                        */
/*                                                                    */
/* This function compares two null-terminated strings, pcStr1 and     */
/* pcStr2, lexicographically. The comparison is case-sensitive. It    */
/* returns 0 if the strings are identical, a negative value if pcStr1 */
/* is less than pcStr2, and a positive value if pcStr1 is greater     */
/* than pcStr2. There is no interaction with stdout or stderr.        */
/*--------------------------------------------------------------------*/
int Str_compare(const char pcStr1[], const char pcStr2[]);

/*--------------------------------------------------------------------*/
/* Str_search                                                         */
/*                                                                    */
/* This function searches for the first occurrence of the substring   */
/* pcNeedle within the string pcHaystack. If the substring is found,  */
/* it returns a pointer to the first occurrence of pcNeedle within    */
/* pcHaystack. If pcNeedle is not found, it returns NULL. The function*/
/* does not produce any output to stdout or stderr.                   */
/*--------------------------------------------------------------------*/
char* Str_search(const char pcHaystack[], const char pcNeedle[]);

#endif 