#include <string.h>
#include <stdio.h>

int replaceDigits (char *line) {
  
  int linelength = strlen (line);
  int i; 
  int number;
  int total; 
 

  for (i = 0; i < linelength; i++) {
     number = *(line + i); 
     
     if (number >= 48 && number <= 57) {
       *(line + i) = ' '; 
        total++; 
     }
  }
  return(total); 
}


