#include <string.h> 
#include <stdio.h>

int replacePunc (char *line) {
  
  int linelength = strlen (line);
  int i;
  int p;
  int total; 
 

  for (i = 0; i < linelength; i++) {
     p = *(line + i); 
     
     if ( (p > 32 && p < 48) || (p > 57 && p < 65) || (p > 90 && p < 97) || (p > 122 && p <= 127) ) {
       *(line + i) = ' '; 
        total++; 
     }
  }

  return(total); 
}

