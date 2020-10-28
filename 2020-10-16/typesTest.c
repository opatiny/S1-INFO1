#define _USE_MATH_DEFINES

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char c;
  short sh;
  int i;
  long int li;
  float f;
  double d;
  long double ld;

  int size = sizeof(12.34);
  printf("%ld \n", sizeof('G'));
  return EXIT_SUCCESS;
}
