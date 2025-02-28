#include <stdio.h>
#include <stdlib.h>
#include <string.h>                                            // strcpy = stringCopy
#define MAX_STR_LEN 25                                         // strcmp = stringCompare                 
                                                               // strrev = stringReverse[al]
int main() {

   char* userInputStr;
   char* userInputStrRev;  
   
   userInputStr = (char*) malloc(1 * sizeof(userInputStr));
   userInputStrRev = (char*) malloc(1 * sizeof(userInputStrRev));

   int len = strlen(userInputStr);

   puts("Enter a string: ");                   
   fgets(userInputStr, MAX_STR_LEN, stdin);                    // exg

   userInputStr[strlen(userInputStr) - 1] = 0;

   if (userInputStr == NULL) {
      printf("\nERROR: STRING = NOTFOUND\n");
      exit(EXIT_FAILURE);
   }

   if (len > MAX_STR_LEN) {
      printf("\nERROR: STR_LEN_BUFFER_OVERFLOW\n");
      exit(EXIT_FAILURE);
   }

   strcpy(userInputStrRev, userInputStr);                      // userInputStr --> userInputStrRev = "exg"
   strrev(userInputStrRev);                                    // reverses uISR  -->  gxa  (within itself)

   strcmp(userInputStr, userInputStrRev);                      // exg <--> gxa [comparison]
                                                               // 0 == comparison = <same>                                                        
   if ((strcmp(userInputStr, userInputStrRev)) == 0) {
      printf("\n[%s] is a palindrome\n", userInputStr);
   } else {
      printf("\n[%s] is NOT a palindrome\n", userInputStr);
   }

   return EXIT_SUCCESS;
}
