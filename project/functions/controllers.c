#define _USE_MATH_DEFINES

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "aquarium.h"
#include "controllers.h"

// there could be many pumps in case they are many aquariums
PUMP pumps[2] = {{.currentValue = 100, .phThreshold = 6.5, .factor = 10}};

int temperatureControl(void) {
  // printf("room temperature controlled\n");
  return 0;
}

int phControl(int index) {
  double currentPH = getPH(index);
  pumps[index].currentValue =
      pumps[index].factor * (currentPH - pumps[index].phThreshold);
  setPumpValue(index, pumps[index].currentValue);
  return 0;
}

double getPumpValue(int index) {
  return pumps[index].currentValue;
}