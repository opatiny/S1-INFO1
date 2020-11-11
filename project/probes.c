#define _USE_MATH_DEFINES

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int tempProbe(void) {
  printf("room temperature updated\n");
  return 0;
}

int lightProbe(void) {
  printf("room luminosity updated\n");
  return 0;
}
