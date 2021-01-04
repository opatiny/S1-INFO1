#define _USE_MATH_DEFINES

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* main(): prints "hello world"
  PARAMETERS:
    -  void
  RETURNS:
    - STATUS (integer)
  Author: Océane Patiny - 2020.10.28
 */

int main(void) {
  // tilde operator
  char n = 0b00001111;
  char q = ~n;
  printf("%i\n", q);

  // .f
  float f = 42.f;
  printf("%f\n", f);

  // cast float to int
  float f2 = 2.9;
  printf("%i\n", (int)f2);
  return EXIT_SUCCESS;

  // it seems that type of logical operators is short??
  double i = 2;
  char s = 5;
  printf("%lu", sizeof(i || s));
}
