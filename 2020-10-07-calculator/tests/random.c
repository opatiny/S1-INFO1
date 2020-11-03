#define _USE_MATH_DEFINES

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  srand(time(0));  // to do once, we "seed" the rand function
  printf("Random values smaller than RAND_MAX:\n");
  for (size_t i = 0; i < 10; i++) {
    printf("%i ", rand());
  }

  printf("\nRandom values between 0 and 1:\n");
  for (size_t i = 0; i < 10; i++) {
    printf("%lf ", (double)rand() / RAND_MAX);
  }

  printf("\nRandom values between -1 and 1:\n");
  for (size_t i = 0; i < 10; i++) {
    printf("%lf ", 2 * (double)rand() / RAND_MAX - 1);
  }

  printf("\nRandom values between 1 and 10:\n");
  for (size_t i = 0; i < 10; i++) {
    printf("%i ", rand() % 10);
  }
  printf("\n");

  return EXIT_SUCCESS;
}
