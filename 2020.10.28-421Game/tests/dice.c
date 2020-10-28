#define _USE_MATH_DEFINES

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* dice(): returns integer in range [1; 6]
  PARAMETERS:
    -  void
  RETURNS:
    - integer
  Author: Océane Patiny - 2020.10.28
 */
int dice(void) {
  srand(time(0));
  return rand() % 6;
}
