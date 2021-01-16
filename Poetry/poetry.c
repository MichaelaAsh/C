#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chop.h"

#define TRUE 1
#define FALSE 0
#define SPACE 32
#define MAX 5

 int main ( int argc, char *argv[]) {

  char poem[200];
  int wordCount = 0;
  int wordCheck = 0;

  int lineCheck = 0;
  int lineCount = 0;
  int lineWordCount[MAX];

  printf ("Enter the poem: \n");

/*============================================================================*/
  /* Outer Loop to check the num of lines and inner check for num of words */

   for (lineCheck = 0; lineCheck < MAX; lineCheck++) {

        int wordPerLine = 0;
        int wordExist = FALSE;

        fgets(poem, 200, stdin);
        chop (poem);

        if (strcmp(poem, ".") == 0 ) {;
          lineCheck = MAX;
          wordCount = wordCount - 1;
        } else {
          lineCount++;
        }

           for ( wordCheck = 0; wordCheck < strlen (poem); wordCheck++) {

               if (wordExist == FALSE) {
                    wordPerLine++; /* This variable is reset to 0 each time it goes into the outer loop again */
                    wordCount++;
                    wordExist = TRUE;
               }
               if (poem[wordCheck] == SPACE && poem[wordCheck+1] != SPACE) {
                  wordExist = FALSE;
               } else {
                 wordExist = TRUE;
               }

          } /* end of for loop for wordCheck */

        lineWordCount[lineCheck] = wordPerLine;

    } /* end of loop for lineCheck */
/*=============================================================================*/
  printf("%d words on %d lines\n", wordCount, lineCount);

  int i, total = 0;
/* =============================================================================*/
                      /* Prints out the wordPerLine */
  for ( i = 0; i < lineCount; i++) {
    total = lineWordCount[i];
    printf ("%d ", total);

  }
  printf ("\n");


 return(0);
 } /* end of main */
