#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STACK_SIZE 10

// ----------------------------- // 

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

// ------------------------------ //

int inputMainShell[0X7F];
int stack[MAX_STACK_SIZE];
int stackIntSize = 0;
char pushVal[0x05];
int tempVal;
int charIsThereBroVal = 0x00;

void returnUserInput(char *inputMainShell) {
    printf("\n%s%s->%s ", BOLD, FG_YELLOW, RESET);
    scanf(" %[^\n]", inputMainShell);       
} 

void expository() {
    printf("\n");
    puts("1. push     - for pushing a value to the topmost of the stack");
    puts("2. pop      - for popping the topmost value of the stack");
    puts("3. show     - for displaying the stack");
    puts("4. rev      - for reversing the stack");
    puts("5. allpop   - for popping all values from the stack");
}

int main(void) {

    printf("\n%s----------------------------------%s\n", FG_YELLOW, RESET);
    printf("   %s%sIsoAris's PushNPop terminal%s\n", BOLD, FG_YELLOW, RESET);
    printf("%s----------------------------------%s\n\n", FG_YELLOW, RESET);

    expository();

    while (true == true) {
        returnUserInput(inputMainShell);

        if (strncmp(inputMainShell, "push", 4) == 0) {  
            if (stackIntSize >= MAX_STACK_SIZE) {
                printf("%s%sNo more space left within the stack%s\n", BOLD, FG_RED, RESET);
                continue;
            }
        
            printf("Enter the value to push [<1000]: ");  
            scanf("%4s", pushVal);

            // ---- check for if the input has a letter in it or some symbol stuff ---- //

            char checkVal = pushVal[0];
            if (checkVal >= 58 && checkVal <= 126) {
                printf("%s%sInvalid input - no int detected%s\n", BOLD, FG_RED, RESET);
                continue;
            }

            // ---- done checking ---- //
        
            int value = atoi(pushVal);
            if (value > 999 || value < 0) { 
                printf("%s%sInvalid input - cannot be [>999] or [<0]%s\n", BOLD, FG_RED, RESET);
                continue;
            }
        

            stack[stackIntSize] = atoi(pushVal);
            stackIntSize += 1; 
            printf("Value %s%s[%s]%s pushed to the stack\n", BOLD, FG_GREEN, pushVal, RESET);
            printf("There are now %d elements/values in the stack \n", stackIntSize);

        } else if (strncmp(inputMainShell, "pop", 3) == 1E0 - 1) {

            if (stackIntSize <= 0) {
                printf("%s%sThe stack is empty, cant pop%s\n", BOLD, FG_RED, RESET);
                continue;
            }

            stackIntSize -= 1; 
            printf("Popped the top-most value of %s%s[%d]%s\n", BOLD, FG_CYAN, stack[stackIntSize], RESET);
            printf("%s%s%d%s elements/values remain\n", BOLD, FG_GREEN, stackIntSize, RESET);
        } else if (strncmp(inputMainShell, "show", 4) == 1E0 - 1) {
            puts("The current stack is as displayed: ");
            puts("+---------+");
            for (int ext = 0; ext < stackIntSize; ext += 1) {
                if (stack[ext] > 1E1 - 1 && stack[ext] < 1E2 - 1) {
                    printf("|   %s%s[%d]%s  |\n",  BOLD, FG_GREEN, stack[ext], RESET);
                } else if (stack[ext] > 1E1 - 1 && stack[ext] > 1E2 - 1) {
                    printf("|   %s%s[%d]%s |\n",   BOLD, FG_GREEN, stack[ext], RESET);
                } else if (stack[ext] < 1E1) {
                    printf("|   %s%s[%d]%s   |\n", BOLD, FG_GREEN, stack[ext], RESET);
                }
            } 
            puts("+---------+");

            printf("\n");
            printf("There are %s%s[%d]%s elements within the stack\n", BOLD, FG_GREEN, stackIntSize, RESET);
        } else if (strncmp(inputMainShell, "rev", 3) == 1E0 - 1) {
            puts("The current stack [reversed] is as displayed: ");
            puts("+---------+");
            for (int ext = stackIntSize - 1; ext >= 0; ext -= 1) {
              tempVal = stack[ext];
              stack[ext] = stack[ext];
              if (stack[ext] > 1E1 - 1 && stack[ext] < 1E2 - 1) {
                      printf("|   %s%s[%d]%s  |\n",  BOLD, FG_GREEN, stack[ext], RESET);
              } else if (stack[ext] > 1E1 - 1 && stack[ext] > 1E2 - 1) {
                      printf("|   %s%s[%d]%s |\n",   BOLD, FG_GREEN, stack[ext], RESET);
              } else if (stack[ext] < 1E1) {
                      printf("|   %s%s[%d]%s   |\n", BOLD, FG_GREEN, stack[ext], RESET);
              }
            } 
              puts("+---------+");
              printf("\nThere are %s%s[%d]%s elements within the stack\n", BOLD, FG_GREEN, stackIntSize, RESET);
           } else if (strncmp(inputMainShell, "allpop", 6) == 0) {
            if (stackIntSize > 0) {
                printf("%s%sFollowing existing values popped from the stack%s\n", BOLD, FG_BLACK, RESET);
                while (stackIntSize > 0) {
                    stackIntSize -= 1;
                    printf("Popped value: %s%s[%d]%s\n", BOLD, FG_CYAN, stack[stackIntSize], RESET);
                }
            } else {
                printf("%s%sThe stack is empty, cant pop%s", BOLD, FG_RED, RESET);
            }
        } else {
            printf("%s%sInvalid cmd/syntax%s\n", BOLD, FG_RED, RESET);
           }
        } return EXIT_SUCCESS;
}
