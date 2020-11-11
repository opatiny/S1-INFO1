#define _USE_MATH_DEFINES

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// prototypes
int Scheduler(void);

int main(void) {
  printf("inside main\n");
  Scheduler();
  return EXIT_SUCCESS;
}
