#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 75
#define MAX_ITR_VAL 40

typedef enum {
    THRESHOLD_C = 8600000,
    THRESHOLD_B = 8900000,
    THRESHOLD_A = 9200000,
    THRESHOLD_AA = 9500000,
    THRESHOLD_EX = 9800000,
    THRESHOLD_EX_PLUS = 9900000,
    THRESHOLD_PURE_MEMORY = 10000000
} scoreThreshold;

void clearInputBuff() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}   // no idea how this works but it works lmao;

int main(void) {
    int iterateValNum, inc;
    
    printf("\nEnter the amount of scores you want to input: ");
    scanf("%d", &iterateValNum);

    // Error notation: [Error - 00X]: <description>            
    //                            ^ --> [X] = Error code
    
    if (iterateValNum > MAX_ITR_VAL || iterateValNum <= 0) {
        printf("\n[Error - 001]: Invalid arguemnt for iteration conduction | MAX = [%d]  |\n\n", MAX_ITR_VAL);
        return EXIT_FAILURE;
    } clearInputBuff();

    // <data_type> *[var] = calloc(amount, sizeof(<data_type>));
    // <data_type> **[var] | points towards (individual) strings inputted instead of characters/chars
    //             ^^
    //  (took time to understand)

    float *chartValCC = calloc(iterateValNum, sizeof(float));
    int *scoreVal = calloc(iterateValNum, sizeof(int));
    char **chartName = calloc(iterateValNum, sizeof(char*));
    float *playRatingVal = calloc(iterateValNum, sizeof(float));

    for (inc = 0; inc < iterateValNum; inc++) {
        chartName[inc] = malloc(MAX_STR_LEN * sizeof(char));
        if (chartName[inc] == NULL) {
            printf("\n[Error - 002]: Memory allocation failure\n");
            return EXIT_FAILURE;
        }

        printf("\nEnter chart[%d] Name: ", inc);
        fgets(chartName[inc], MAX_STR_LEN, stdin);
        chartName[inc][strcspn(chartName[inc], "\n")] = '\0';

        printf("\nEnter Chart [CC]: ");
        scanf("%f", &chartValCC[inc]);
        if (chartValCC[inc] < 0 || chartValCC[inc] > 14) {
            printf("\n[Error - 003]: Invalid CC/Chart constant argument\n\n");
        } clearInputBuff();

        printf("\nEnter your play score [eg: 9970000]: ");
        scanf("%d", &scoreVal[inc]);
        clearInputBuff();
    }

    // apparently this wont work if not iterating on every itrArr[inc] so ig let this be
    for (inc = 0; inc < iterateValNum; inc++) {
        if (scoreVal[inc] > THRESHOLD_PURE_MEMORY + 3000) {
            printf("\n[Error - 004]: Invalid score argument input\n\n");
            playRatingVal[inc] = -4 + chartValCC[inc];
        } else if (scoreVal[inc] > THRESHOLD_PURE_MEMORY) {
            playRatingVal[inc] = 2 + chartValCC[inc];
        } else if (scoreVal[inc] > THRESHOLD_EX_PLUS && scoreVal[inc] <= THRESHOLD_PURE_MEMORY) {
            playRatingVal[inc] = 1.5 + chartValCC[inc];
        } else if (scoreVal[inc] > THRESHOLD_EX && scoreVal[inc] <= THRESHOLD_EX_PLUS) {
            playRatingVal[inc] = 1 + chartValCC[inc];
        } else if (scoreVal[inc] > THRESHOLD_AA && scoreVal[inc] <= THRESHOLD_EX) {
            playRatingVal[inc] = 0 + chartValCC[inc];
        } else if (scoreVal[inc] > THRESHOLD_A && scoreVal[inc] <= THRESHOLD_AA) {
            playRatingVal[inc] = -1 + chartValCC[inc];
        } else if (scoreVal[inc] > THRESHOLD_B && scoreVal[inc] <= THRESHOLD_A) {
            playRatingVal[inc] = -2 + chartValCC[inc];
        } else if (scoreVal[inc] > THRESHOLD_C && scoreVal[inc] <= THRESHOLD_B) {
            playRatingVal[inc] = -3 + chartValCC[inc];
        } else {
            printf("Grade D - no play potential/play rating evaluated\n");
            playRatingVal[inc] = -4 + chartValCC[inc];
        }
    } // looks clean lmao im proud
      // [-X] <--> -X      ...      Removed brackets
 
    printf("\n");

    // print shit
    for (inc = 0; inc < iterateValNum; inc++) {
        printf("\nChart name: [%s]\n", chartName[inc]);
        printf("Play rating is: [%.2f]\n", playRatingVal[inc]);
        printf("\n");
    }

    // free section (do not forget)
    free(chartName); 
    free(chartValCC);
    free(scoreVal);
    free(playRatingVal);
  
    return EXIT_SUCCESS;
}
