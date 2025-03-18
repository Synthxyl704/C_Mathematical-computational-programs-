#include <stdio.h>
#include <stdlib.h>

void expositoryFunc(char introMessage[]) {  // why would anyone do this sort of func parameter stuff lmao
  printf("%s", introMessage);               // OOP stuff???
} 

                                                                      /*  lmao this works

 | == TERMINAL ENCLOSURE

 Output should be this thing {
-------------------------------
 | >-----<----->-----<-----> |
   ^     ^     ^     ^     ^
   V     W     X     Y     Z
-------------------------------
}                                                                     */

int main(void) {
  expositoryFunc(
      "\nAsk user for [X] collinear parallel forces in upward/downward direction.\nPrint the linear apparatus with marked force + direction onto the terminal with printf dynamically.\n");
  printf("Example input for integral values (in newtons): 40\n\n");

  int parallelForcesNum;

  printf("Enter the amount of parallel forces [<10]: ");
  scanf("%d", &parallelForcesNum);


  if (parallelForcesNum > 10) {
    printf("[Error]: Force integer limit exceeds maximum set/imposed threshold.");
  }

  int *forcesArray = (int*) malloc(parallelForcesNum * sizeof(int));
  int *dirForcesArray = (int*) malloc(parallelForcesNum * sizeof(int));

  if (forcesArray == NULL || dirForcesArray == NULL) {
    printf("\n\n[Error 001]: Memory allocation failure.\n\n");
    return EXIT_FAILURE;
  }

  for (int inc = 0; inc < parallelForcesNum; inc += 1) {
    printf("Enter force (in newtons) [%d]: ", inc + 1);
    scanf("%d", &forcesArray[inc]);

    printf("Enter direction [1 = Right || 2 == Left] for force [%d]: ", inc + 1);
    scanf("%d", &dirForcesArray[inc]);

    printf("\n");
  }

  printf("\n");
  puts("VISUALIZATION: ");
  printf("\n");

  // add force directional symbols
  // [--<--] = force travelling in left direction
  // [-->--] = force travelling in right direction

  // add penta hyphens [> || <] symbols
  for (int inc = 0; inc < parallelForcesNum; inc += 1) {
    if (dirForcesArray[inc] == 1) {
      printf(">");
    } else if (dirForcesArray[inc] == 2) {
      printf("<");
    } else {
      printf("?");
    } 

    while (inc < parallelForcesNum - 1) {
      if (forcesArray[inc] > 9 && forcesArray[inc] < 99) {
        printf("------"); 
        break;
      } else if (forcesArray[inc] > 99) {
        printf("-------");
        break;
      } else {
        printf("-----");
        break;
      }
    }
  }

  printf("\n");

  //print arrow symbol below the forces [> || <] symbol PLEASE
  for (int inc = 0; inc < parallelForcesNum; inc++) { 
    if (forcesArray[inc] > 9 && forcesArray[inc] < 99) {
      printf("^      ");                       // add by 1
    } else if (forcesArray[inc] > 99) {        // -%6d
      printf("^       ");                      // add by 2
    } else {                                   // -%7d
      printf("^     ");                        // -%5d
    }
  }
   printf("\n");
  
  // print the original entered forces under the [^] symbol 
  for (int inc = 0; inc < parallelForcesNum; inc++) {
    printf("%d     ", forcesArray[inc]);   
  }
  

  printf("\n");

  // free the souls

  free(forcesArray);
  free(dirForcesArray);

  /*
  Whats the error? 
  Ans: duo digit int keeps getting farted away by 1 hyhen/space due to it being fat as fuck
  Solution?
  
  Notation: S-int = Single int | Eg: 4, 7 ,9
            D-int = Duo int    | Eg: 47, 67, 69
            T-int = Tri int    | Eg: 477, 672, 699
            H     - Hyphen     | Eg: -
            

  Given {
    hyphen number value = 5
    EXG: [-----]

    IN/O visualization:
    CASE I = Success on last digit = D-int/T-int
    user = 2 5 10 
    >----->----->
    ^     ^     ^
    2     5     10

    CASE II = FAILURE 
    user = 2 10 5
    >----->-----<
    ^     ^     ^
    2     10     5
    ^--5--^--6?--^      

    if [Xint] > 9  = +6!
    if [Xint] > 99 = +7!

    solution?

    add 5H + 5invchar if S-int
        6H + 6invchar if D-int
        7H + 7invchar if T-int
        ^^^^^^^^^^^^^^^^^^^^^^
        Finally debugged :pray:
  }
  
  */

  printf("\n");

  float resultantVal, directionalDegVal;

  // Resultant = R = Sum[Fx] due to horizontally conductive forces absent
  // Directional degree = always 90/0
  // [--<--] = NEG   |   [-->--] = POS

  return EXIT_SUCCESS;
}
