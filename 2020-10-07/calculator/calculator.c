/*
 ============================================================================
 Name        : calculator.c
 Author      : Océane Patiny
 Version     :
 Copyright   :
 Description :
 ============================================================================
 */

#define _USE_MATH_DEFINES

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "calculator.h"

int main(void) {
  int continueCalculation = 1;

  while (continueCalculation) {
    int operator;
    printf("Specify the type of operator:\n 1) binary\n 2) unary\n");
    scanf("%i", &operator);

    switch (operator) {
      case (1):
        binary();
        break;
      case (2):
        unary();
        break;
      default:
        break;
    }

    printf("Do you want to continue (1 = yes, 0 = no)? ");
    scanf("%i", &continueCalculation);
  }
  return EXIT_SUCCESS;
}