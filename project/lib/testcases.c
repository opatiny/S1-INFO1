#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int shouldBeEqual_i(int* testState, int value, int expected) {
  if (value != expected) {
    printf("expected: %i, got: %i \n", expected, value);
    *testState--;
  }
  return 1;
}

int shouldBeEqual_d(int* testState,
                    double value,
                    double expected,
                    double maxError) {
  if (abs(value - expected) > maxError) {
    printf("expected: %lf, got: %lf \n", expected, value);
    *testState--;
    return 0;
  }
  return 1;
}