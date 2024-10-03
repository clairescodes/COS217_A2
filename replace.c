/*--------------------------------------------------------------------*/
/* replace.c                                                          */
/* Author: Claire Shin                                                        */
/*--------------------------------------------------------------------*/

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

/*--------------------------------------------------------------------*/

/* If pcFrom is the empty string, then write string pcLine to stdout
   and return 0.  Otherwise write string pcLine to stdout with each
   distinct occurrence of string pcFrom replaced with string pcTo,
   and return a count of how many replacements were made.  Make no
   assumptions about the maximum number of replacements or the
   maximum number of characters in strings pcLine, pcFrom, or pcTo. */

static size_t replaceAndWrite(const char *pcLine,
                              const char *pcFrom, const char *pcTo)
{
   char *pcResult;
   const char *pcCurrent;
   const char *pcNext;
   size_t lenFrom, lenTo;
   size_t uReplaceCount = 0; /* count number of replaced */
   size_t bufferSize;
   size_t occurCount = 0; 

   /* make sure each parameter is not NULL */
   assert(pcLine != NULL); 
   assert(pcFrom != NULL); 
   assert(pcTo != NULL); 

   /* if pcFrom is empty string, then write string pcLine to 
   stdout and return 0 */
   if (strlen(pcFrom) == 0) {
      printf("%s", pcLine);
      return 0;
   }
   
   lenFrom = strlen(pcFrom);
   lenTo = strlen(pcTo);

   pcCurrent = pcLine; 
   while ((pcNext = strstr(pcCurrent, pcFrom)) != NULL) {
      occurCount++;
      pcCurrent = pcNext + lenFrom;
   }

   /* allocate space if lenTo is greater than lenFrom */
   bufferSize = strlen(pcLine) + occurCount * (lenTo - lenFrom) + 1;

   pcResult = malloc(bufferSize);
   if (pcResult == NULL) {
      fprintf(stderr, "Memory allocation failed\n");
      exit(EXIT_FAILURE);
   }

   pcResult[0] = '\0'; /* make sure buffer starts empty */
   pcCurrent = pcLine;
   
   while ((pcNext = strstr(pcCurrent, pcFrom)) != NULL) {
      /* append before match */
      strncat(pcResult, pcCurrent, (size_t)(pcNext - pcCurrent));

      /* append replacement */
      strcat(pcResult, pcTo);
      uReplaceCount++;

      /* move past matched string */
      pcCurrent = pcNext + lenFrom;
   }
   strcat(pcResult, pcCurrent); /* append rest of string */
   printf("%s", pcResult); /* write result to stdout */
   
   free(pcResult); /* clean memory */
   return uReplaceCount;
}

/*--------------------------------------------------------------------*/

/* If argc is unequal to 3, then write an error message to stderr and
   return EXIT_FAILURE.  Otherwise...
   If argv[1] is the empty string, then write each line of stdin to
   stdout, write a message to stderr indicating that 0 replacements
   were made, and return 0.  Otherwise...
   Write each line of stdin to stdout with each distinct occurrence of
   argv[1] replaced with argv[2], write a message to stderr indicating
   how many replacements were made, and return 0.
   Assume that no line of stdin consists of more than MAX_LINE_SIZE-1
   characters. */

int main(int argc, char *argv[])
{
   enum {MAX_LINE_SIZE = 4096};
   enum {PROPER_ARG_COUNT = 3};

   char acLine[MAX_LINE_SIZE];
   char *pcFrom;
   char *pcTo;
   size_t uReplaceCount = 0;

   if (argc != PROPER_ARG_COUNT)
   {
      fprintf(stderr, "usage: %s fromstring tostring\n", argv[0]);
      return EXIT_FAILURE;
   }

   pcFrom = argv[1];
   pcTo = argv[2];

   while (fgets(acLine, MAX_LINE_SIZE, stdin) != NULL) 
   {
      uReplaceCount += replaceAndWrite(acLine, pcFrom, pcTo);
   }

   fprintf(stderr, "%lu replacements\n", (unsigned long)uReplaceCount);
   return 0;
}
