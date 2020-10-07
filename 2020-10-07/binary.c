// RUN: cd "/home/opatiny/git/opatiny/S1-INFO1/2020-10-07/" && gcc binary.c -lm
// -o binary && "/home/opatiny/git/opatiny/S1-INFO1/2020-10-07/"binary

#define _USE_MATH_DEFINES

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int operator;
  printf(
      "Enter number of desired binary operator: 1) +, 2) -, 3) *, "
      "4) /, 5) ^\n");
  scanf("%i", &operator);

  double number1;
  printf("Enter first number: \n");
  scanf("%lf", &number1);

  double number2;
  printf("Enter second number: \n");
  scanf("%lf", &number2);

  switch (operator) {
    case 1:
      printf("The value of %lf+%lf is %lf", number1, number2,
             number1 + number2);
      break;
    case 2:
      printf("The value of %lf-%lf is %lf", number1, number2,
             number1 - number2);
      break;
    case 3:
      printf("The value of %lf*%lf is %lf", number1, number2,
             number1 * number2);
      break;
    case 4:
      printf("The value of %lf/%lf is %lf", number1, number2,
             number1 / number2);
      break;
    case 5:
      printf("The value of %lf^%lf is %lf", number1, number2,
             pow(number1, number2));
      break;
    default:
      break;
  }
  printf("\n");

  return EXIT_SUCCESS;
}
