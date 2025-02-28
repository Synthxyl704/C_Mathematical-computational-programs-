#include <stdio.h>
#include <math.h>
#define VAL_PI 3.1415926
                                                                                              /* 
    Programmer notes / formulae { 
        Slope of a line = Gradient of a line 
        Slope           = Gradient 
        Gradient        = tan[X] (predef'd tan values) 
        Gradient of a line passing through 2 points = [x2 - y1 / x2 - x1]     // not used 

        Standard form of eqn = Ax + By + C = 0 
        Slope of a line      = -(Coefficient of x) / (Coefficient of y)       // used 
        x - intercept        = -(Const term) / (Coefficient of x)             // used 
        y - intercept        = -(Const term) / (Coefficient of y)             // used 
}                                                                                               */

void commenceMSG() {
  char def[] = "Elementary C program to calculate the gradient and x/y intercepts of (any) given line \n\n";
  printf("%s", def);
}

void userPrompt() {
  char prompt[] = "Gradient of a line passing through 2 points = [y2 - y1 / x2 - x1]\n x - intercept = -(Const term) / (Coefficient of x)\n y - intercept = -(Const term) / (Coefficient of y)      \n";
  printf("%s", prompt);
}

int main(void) {
  commenceMSG();
  userPrompt();

  float A, B, C;                                         // Equation constants
  float x_Intercept, y_Intercept, lineSlope, lineGrad;
  double lineAngleRad, lineAngleDeg;

  printf("Enter the values of your equation (Ax + By + C = 0)\nInput [0] to all values if !EQN\n");
  printf("Enter A: ");                         scanf("%f", &A);
  printf("Enter B: ");                         scanf("%f", &B);
  printf("Enter C: ");                         scanf("%f", &C);
  printf("Enter measured angle value [in degrees]: ");      scanf("%lf", &lineAngleDeg);

  if (A == 0 && B == 0 && C == 0) {
    printf("\nNo equation detected, returning only gradient value.\n");
  }

  lineAngleRad = ((lineAngleDeg) * VAL_PI / 180);
  lineGrad    = tan(lineAngleRad);                       // Calculate line gradient if [A, B, C] !used
  lineSlope   = (float)(A * -1) / B;                            // Calculate gradient value
  x_Intercept = (float)(C * -1) / A;                            // Calculate X-Intercept
  y_Intercept = (float)(C * -1) / B;                            // Calculate Y-Intercept               

  printf("\nGradient value of the line [Tan(%.2f)]:  %6lf \n", lineAngleDeg ,lineGrad);
  printf("Gradient value of the line:  %f \n", lineSlope);
  printf("X-Intercept of the line:  %f \n", x_Intercept);
  printf("Y-Intercept of the line:  %f \n", y_Intercept);

  return 0;
}
