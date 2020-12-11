#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int shouldBeEqual_i(int* testState, int value, int expected) {
  if (value != expected) {
    printf("    got: %i, expected: %i \n", value, expected);
    (*testState--);
    return 1;
  }
  return 0;
}

int shouldBeEqual_d(int* testState,
                    double value,
                    double expected,
                    double maxError) {
  if (abs(value - expected) > maxError) {
    printf("    got: %lf, expected: %lf \n", value, expected);
    (*testState)--;
    return 1;
  }
  return 0;
}