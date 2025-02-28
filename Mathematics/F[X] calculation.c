#include <stdio.h>

void defn() {
  char msg1[] = "\nHeres an example of a function: \n";
  char msg2[] = "y = 5x^2 + 4x + 86\n";
  char msg3[] = "here, [y] is the dependent var and [x] is the independent var";
  char msg4[] = "\nEquation reference: [Zx^5 + Yx^4 + Vx^3 + Ax^2 + Bx + C]";
  printf ("%s", msg1);
  printf ("%s", msg2);
  printf ("%s", msg3);
  printf ("%s", msg4);
}

int main(void) {
  defn();

  int var_Z, var_Y, var_V, var_A, var_B, var_C;
  int var_num;                                            
  int inc, ind_x;                                         // inc = increment for [for] loops, ind_x = independent variable x
  int functionAnswer;
  printf ("\n\nEnter the amount of variables [<= 6] in your equation: ");
  scanf ("%2d", &var_num);

  if (var_num > 6) {
    puts("\nInvalid amount\n");
    return 1;
  }

  switch (var_num) {
    case 5:
    var_Z = 0;
    printf ("Enter var [Y]^4: ");    scanf ("%6d", &var_Y);
    printf ("Enter var [V]^3: ");    scanf ("%6d", &var_V);
    printf ("Enter var [A]^2: ");    scanf ("%6d", &var_A);
    printf ("Enter var [B]^1: ");    scanf ("%6d", &var_B);
    printf ("Enter var [C]: ");      scanf ("%6d", &var_C);
    break;
    case 4: 
     var_Z = 0;
     var_Y - 0;
    printf ("Enter var [V]^3: ");    scanf ("%6d", &var_V);
    printf ("Enter var [A]^2: ");    scanf ("%6d", &var_A);
    printf ("Enter var [B]^1: ");    scanf ("%6d", &var_B);
    printf ("Enter var [C]: ");      scanf ("%6d", &var_C);
    break;
    case 3: 
     var_Z = 0;
     var_Y = 0;
     var_V = 0;
    printf ("Enter var [A]^2: ");    scanf ("%6d", &var_A);
    printf ("Enter var [B]^1: ");    scanf ("%6d", &var_B);
    printf ("Enter var [C]: ");      scanf ("%6d", &var_C);
    break;
    case 2: 
     var_Z = 0;
     var_Y = 0;
     var_V = 0;
     var_A = 0;
    printf ("Enter var [B]^1: ");    scanf ("%6d", &var_B);
    printf ("Enter var [C]: ");      scanf ("%6d", &var_C);
    break;
    case 1: 
     printf ("N/A"); 
     return 1;
    break;
    case 0: 
     printf ("N/A");
     return 1;
    break;
  }

  printf ("Enter your independent variable [x]: ");
  scanf ("%d", &ind_x);

  // solve f(x) = ...;
  functionAnswer =  ((var_Z) * (ind_x * ind_x * ind_x * ind_x * ind_x)) 
                  + ((var_Y) * (ind_x * ind_x * ind_x * ind_x)) 
                  + ((var_V) * (ind_x * ind_x * ind_x)) 
                  + ((var_A) * (ind_x * ind_x)) 
                  + ((var_B) * (ind_x)) 
                  + (var_C);

  printf ("f(%d) = %d", ind_x, functionAnswer);
  return 0;
}
