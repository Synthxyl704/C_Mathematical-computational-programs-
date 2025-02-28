#include <stdio.h>
#include <math.h>
#define RAD_TO_DEG_VAL 57.2957795131
#define PI 3.14159

/*
Complex num equation template used: [X] + [Y]i
where [X] is the real part & [Y] is the imaginary part

        [i = sqrt(-1)]
Modulus    = |z| = √[X^2 + Y^x]
Amplitude  = [θ] = Determine after conditional verification
Polar form = |z|[cos(θ) + isin(θ)]
*/

int main() {
    float realVal, imaginaryVal, modulusVal, amplitudeVal;
    double alphaVal;

    printf("Enter the real value part: ");            scanf("%f", &realVal); 
    printf("Enter the imaginary value part: ");       scanf("%f", &imaginaryVal);

    printf("You entered: [%f] + [%f]i\n", realVal, imaginaryVal);

    modulusVal = sqrt((pow(realVal, 2)) + (pow(imaginaryVal, 2)));

    alphaVal = atan(imaginaryVal / realVal);
    alphaVal *= RAD_TO_DEG_VAL;

    if (realVal > 0 && imaginaryVal > 0) {
        amplitudeVal = alphaVal;
        printf("\nThe modulus is: [%f]\n", modulusVal);
        printf("The amplitude is: [%f]\n", amplitudeVal);
        printf("The polar form of the complex number is: (%f)[cos(%f°) + isin(%f°)]\n\n", modulusVal, amplitudeVal, amplitudeVal);
    } else if (realVal < 0 && imaginaryVal > 0) {
        amplitudeVal = PI - alphaVal;
        printf("\nThe modulus is: [%f]\n", modulusVal);
        printf("The amplitude is: [%f]\n", amplitudeVal);
        printf("The polar form of the complex number is: (%f)[cos(%f°) + isin(%f°)]\n\n", modulusVal, amplitudeVal, amplitudeVal);
    } else if (realVal < 0 && imaginaryVal < 0) {
        amplitudeVal = PI + alphaVal;
        printf("\nThe modulus is: [%f]\n", modulusVal);
        printf("The amplitude is: [%f]\n", amplitudeVal);
        printf("The polar form of the complex number is: (%f)[cos(%f°) + isin(%f°)]\n\n", modulusVal, amplitudeVal, amplitudeVal);
    } else if (realVal > 0 && imaginaryVal < 0) {
        amplitudeVal = (2 * PI) - alphaVal;
        printf("\nThe modulus is: [%f]\n", modulusVal);
        printf("The amplitude is: [%f]\n", amplitudeVal);
        printf("The polar form of the complex number is: (%f°)[cos(%f°) + isin(%f°)]\n\n", modulusVal, amplitudeVal, amplitudeVal);
    }

    return 0;
}
