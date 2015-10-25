/* C6_P1.c
    Author: Billy Hart    Last Modified by: Billy Hart
    Assignment: Chapter 6 Project #1
    Date Last Modified: October 20, 2015
    Program Description:
    Calculates an exponent expression repeatedly until user enters a negative number to quit.
*/

#include <stdio.h>
#include <stdlib.h> // For rand()

// Function Declaration
int calculateExponent(int baseNum, int exponentNum);

int main() {
  // Local Variables
  int baseNum, exponentNum, exponentSolution;

  // Prompt the user
  printf("This program computes x to the power n. ");
  printf("Enter in both values to calculate the result. \n");
  printf("Use a negative number for x to exit.\n");

  // Loop until the user enters a negative number
  do {
    // Ask for both integers
    printf("X: ");
    scanf("%d", &baseNum);

    printf("N: ");
    scanf("%d", &exponentNum);

    // Check to see if we should calculate
    if (baseNum > 0) {
      // Calculate the exponent
      exponentSolution = calculateExponent(baseNum, exponentNum);

      // Display the results of raising the base to the given power
      printf("%d raised to the power %d is %d.\n\n", baseNum, exponentNum, exponentSolution);
    }
  } while (baseNum > 0);

  // Release memory
  printf("\n");
  system("pause");
  return (0);
}

/* Function to calculate x raised to the power n */
int calculateExponent(int baseNum, int exponentNum) {
  // Local Variable
  int sizeOfExponentNumHalved;

  // If the value entered by the user is 0, just return 1
  // Exponent Law: Zero Rules b^0 = 1
    if (exponentNum == 0) {
        return 1;
    }

    // Store the size of exponentNum halved as a recursive function call
    sizeOfExponentNumHalved = calculateExponent(baseNum, exponentNum / 2);

    // If exponent is even...
    if (exponentNum % 2 == 0) {
        // Multiply itself by itself
        return sizeOfExponentNumHalved*sizeOfExponentNumHalved;
    }
    else {
        // Multiply one copy of itself by itself times itself
        return baseNum * sizeOfExponentNumHalved * sizeOfExponentNumHalved;
    }
}
