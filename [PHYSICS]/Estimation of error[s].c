#include <math.h>      //supports fabs
#include <stdlib.h>    //supports abs
#include <stdio.h>
#include <string.h>
#define MAX_READING_LIM 75

//  int numVal    = abs(numVal);
//  float numVal2 = fabs(numVal2)

int main(void) {
    printf("C program to calculate the:\n- Mean Average Error\n- Absolute Error\n- Relative Error\n- Percentage Error from the given data inputted\n\n");
    puts("__EXPOSITORY:");
    puts("d(x) where (x) equals to the amount of data sets/readings the user has taken;");
    puts("Example: d(x) = 4; returns d(4) and asks for readings (4) times");

    int totalDataInt, inc;
    float sumErrMean = 0;
    float readingAmount[75], meanErr, absoluteErr = 0, relativeErr, percenErr;

    printf("\nEnter d(x): ");            
    scanf("%d", &totalDataInt);

    if (totalDataInt > MAX_READING_LIM) {
        printf("\nSorry! Too many readings!\n");
        return EXIT_FAILURE;
    }

    for (inc = 0; inc < totalDataInt; inc++) {
        printf("Enter d(%d): ", inc + 1);
        scanf("%f", &readingAmount[inc]);
        sumErrMean += readingAmount[inc];
    }

    // calc them all

    meanErr = sumErrMean / totalDataInt;                     // - [avg mean]

    for (inc = 0; inc < totalDataInt; inc++) {
        absoluteErr += fabs(meanErr - readingAmount[inc]);   // - [avg absolute]
    } absoluteErr /= 4;

    relativeErr = absoluteErr / meanErr;                     // - [relative]
    percenErr = relativeErr * 100;                           // - [%ile]

    printf("\nAverage Mean error: [%.3f]\n", meanErr);       // ---|
    printf("Absolute error: [%f]\n", absoluteErr);           //    |= these are unitless as far as I know
    printf("Relative error: [%f]\n", relativeErr);           // ---|
    printf("Percentile error: [%f%%]", percenErr);

    return EXIT_SUCCESS;
}
