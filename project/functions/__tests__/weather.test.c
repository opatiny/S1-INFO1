#include <stdio.h>
#include <stdlib.h>

#include "../weather.h"

int test_updateWeatherTemperature(void) {
  double result;
  for (int i = 0; i < 60 * 60 * 24; i = i + 60 * 60) {
    result = updateWeatherTemperature(60 * 60 * 10, 0);
    printf("%lf \n", result);
  }
  return result == 0;
}
