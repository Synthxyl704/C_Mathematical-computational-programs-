/*

INT_MAX: [2147483647]
INT_MIN: [-2147483648]

INT8_MAX: [127]
INT8_MIN: [-128]

INT16_MAX: [32767]
INT16_MIN: [-32768]

INT32_MAX: [2147483647]
INT32_MIN: [-2147483648]

INT64_MAX: [-1]
INT64_MIN: [0]

FLT_DIG: [6]
FLT_MAX: [-536870912]
FLT_MIN: [0]

-- other --

     __INT16_MAX__: [32767]
_INTEGRAL_MAX_BITS: [64]
         __INT32_C: [2147483647]
     __INT32_MAX__: [2147483647]

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>

#define RESET "\x1b[0m"
#define BOLD "\x1b[1m"
#define FG_BLACK "\x1b[30m"
#define FG_RED "\x1b[31m"
#define FG_GREEN "\x1b[32m"
#define FG_YELLOW "\x1b[33m"
#define FG_BLUE "\x1b[34m"
#define FG_MAGENTA "\x1b[35m"
#define FG_CYAN "\x1b[36m"
#define FG_WHITE "\x1b[37m"

#define MAX_STR_INPUT_LEN 100

char inputMainShell[MAX_STR_INPUT_LEN];
int flagVal = 1;
int amount;

uint64_t digitValues[INT16_MAX];

void returnUserInputShell(char *inputMainShell) {
  printf("\n%s%s->%s ", BOLD, FG_GREEN, RESET);
  scanf(" %[^\n]", inputMainShell);       
} 

void myTerminalAppellation() {
  printf("\n%s---------------------------------------------------%s\n", FG_YELLOW, RESET);
  printf("   %s%sIsoAris's arbitrary arithmetic opr^n terminal%s\n", BOLD, FG_YELLOW, RESET);
  printf("%s---------------------------------------------------%s\n\n", FG_YELLOW, RESET);
}

void expository() {
  printf("\n");
  printf("%s%s-> amount%s   - command for prompting the digit amount and its values\n",          BOLD, FG_MAGENTA, RESET);
  printf("%s%s-> add%s      - command for performing addition onto the inputted values\n",       BOLD, FG_MAGENTA, RESET);
  printf("%s%s-> sub%s      - command for performing subtraction onto the inputted values\n",    BOLD, FG_MAGENTA, RESET);
  printf("%s%s-> mul%s      - command for performing multiplication onto the inputted values\n", BOLD, FG_MAGENTA, RESET);
  printf("%s%s-> expo%s     - command for diplaying the terminal operational commands\n",        BOLD, FG_MAGENTA, RESET);
  printf("\n");
}

// ------------- RIZZING THE U_INT64_Ts -------------- //

void forDigitAmount() {
  const int bufferForDigitInput = 20; 
  char inputBuffer[bufferForDigitInput];

  printf("Enter the amount of digits you want to work on: ");
  scanf("%d", &amount);
  getchar(); 

  if (amount <= 0 || amount > INT16_MAX) {
    printf("\n\n%s%s[Error 001]: Invalid input detected%s\n\n", BOLD, FG_RED, RESET);
    return;
  }

  printf("Enter the respective values:\n");
  for (int inc = 0; inc < amount; inc++) {
    printf("Enter value for number[%d]: ", inc + 1);

    fgets(inputBuffer, bufferForDigitInput, stdin);
    inputBuffer[strcspn(inputBuffer, "\n")] = '\0';
    digitValues[inc] = strtoull(inputBuffer, NULL, 10);
    printf("Stored value: %s%s%llu%s\n", BOLD, FG_GREEN, digitValues[inc], RESET);
  }

  printf("\nInputted values: \n");
  for (int inc = 0; inc < amount; inc++) {
    printf("Number[%d] =  %s%s%llu%s\n", inc + 1, BOLD, FG_GREEN, digitValues[inc], RESET);
  }

  printf("\nThe inputs have been stored, please refer the cmd expo (or type [expo]) for further operation\n\n");
}

// ------------- ADDING THE U_INT64_Ts -------------- //

void addOperation() {
  uint64_t sumVal = 0;

  if (amount <= 0) {
    printf("\n%s%s[Error 002]: N/A values detected%s\n\n", BOLD, FG_RED, RESET);
    return;
  }

  for (int inc = 0; inc < amount; inc += 1) {
    sumVal += digitValues[inc];
  }
  printf("\nSum of values: %s%s[%" PRId64 "]%s\n\n", BOLD, FG_GREEN, sumVal, RESET);
}

// ------------- SUBTRACTING THE U_INT64_Ts -------------- //

void subOperation() {
  int64_t subtractionVal;

  if (amount <= 0) {
    printf("\n%s%s[Error 003]: N/A values detected%s\n\n", BOLD, FG_RED, RESET);
    return;
  }

  // first val = important 

  // suppose 2, 100 and 200
  // subVal = 100
  // 100 = 100 - 200
  // = -100

  // oh it didnt work because it was unsigned LOL

  subtractionVal = digitValues[0];  
  for (int inc = 1; inc < amount; inc += 1) {
    subtractionVal -= digitValues[inc];
  }
  printf("\nSubtraction result: %s%s[%" PRId64 "]%s\n\n", BOLD, FG_GREEN, subtractionVal, RESET);
}

// ------------- MULTIPLYING THE U_INT64_Ts -------------- //

void mulOperation() {
  uint64_t multiplicationVal;

  if (amount <= 0) {
    printf("\n%s%s[Error 004]: N/A values detected%s\n\n", BOLD, FG_RED, RESET);
    return;
  }

  // first val = important #2

  // supposed 2, 100 and 200
  // mulVal = 100
  // 100 = 100 * 200
  // = 20000

  // worked with %llu but %" PRId64 " works as well

  multiplicationVal = digitValues[0]; 
  for (int inc = 1; inc < amount; inc += 1) {
    multiplicationVal *= digitValues[inc];

  }
  printf("\nMultiplication result: %s%s[%" PRId64 "]%s\n\n", BOLD, FG_GREEN, multiplicationVal, RESET);
}

int main(void) {

  myTerminalAppellation();

  printf("\n%s%sParse up %s[help]%s%s for starting out\n\n%s", BOLD, FG_BLACK, RESET,
                                                               BOLD, FG_BLACK, RESET);

  while (flagVal == 1) {
    returnUserInputShell(inputMainShell);

    if (strncmp(inputMainShell, "amount", 6) == 0) {
      forDigitAmount(); 
    } else if (strncmp(inputMainShell, "help", 4) == 0) {
      expository();
    } else if (strncmp(inputMainShell, "add", 3) == 0) {
      addOperation();
    } else if (strncmp(inputMainShell, "sub", 3) == 0) {
      subOperation();
    } else if (strncmp(inputMainShell, "mul", 3) == 0) {
      mulOperation();
    } else if (strncmp(inputMainShell, "exit", 4) == 0) {
      flagVal = 0; 
    }  else {
      printf("%s%sInvalid command detected - try again\n%s", BOLD, FG_RED, RESET);
    }
  } // clean :yum:

  return EXIT_SUCCESS;
}
