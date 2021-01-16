#include <string.h>
#include <stdio.h>

int convertLowerCase (char *line) {

 int lineLength; 
 int character = 0; 
 int total = 0; 
 int i; 

 lineLength = strlen (line); 

 for (i = 0; i < lineLength; i++) {
     character = *(line + i); 
   if (character > 96 && character < 123) { 
          *(line + i) = character; 
   } else {
     if (character >= 65 && character <= 97) 
        *(line + i) = character + 32; 
         total++;
   } 
       
 }
  
 return (total); 

}


