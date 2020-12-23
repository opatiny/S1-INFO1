#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int shouldBeEqual_i(int* nbCasesFailing, int value, int expected) {
  if (value != expected) {
    printf("    got: %i, expected: %i \n", value, expected);
    (*nbCasesFailing)++;
    return 1;
  }
  return 0;
}

int shouldBeEqual_d(int* nbCasesFailing,
                    double value,
                    double expected,
                    double maxError) {
  if (abs(value - expected) > maxError) {
    printf("    got: %lf, expected: %lf \n", value, expected);
    (*nbCasesFailing)++;
    return 1;
  }
  return 0;
}

int shouldBeGreaterThan_d(int* nbCasesFailing, double value, double expected) {
  if (!(value > expected)) {
    printf("    got: %lf, expected greater than: %lf \n", value, expected);
    (*nbCasesFailing)++;
    return 1;
  }
  return 0;
}

int shouldBeSmallerThan_d(int* nbCasesFailing, double value, double expected) {
  if (!(value < expected)) {
    printf("    got: %lf, expected smaller than: %lf \n", value, expected);
    (*nbCasesFailing)++;
    return 1;
  }
  return 0;
}
