#include <stdio.h>
#include <stdlib.h>

#include "../weather.h"

double zeroNoise(double amplitude);

int test_updateWeatherTemperature(void) {
  double temperatureMidnight;
  double temperatureTenAM;
  double temperatureFourPM;

  temperatureMidnight = updateWeatherTemperature(0 * 60 * 60, 0);
  temperatureTenAM = updateWeatherTemperature(10 * 60 * 60, 0);
  temperatureFourPM = updateWeatherTemperature(16 * 60 * 60, 0);
  if (temperatureMidnight > temperatureTenAM) {
    return 0;
  }
  if (temperatureTenAM > temperatureFourPM) {
    return 0;
  }
  if (temperatureFourPM < temperatureMidnight) {
    return 0;
  }

  return 1;
}

int test_noisySinusoid(void) {
  double result;

  double phase = -150;
  double timeInHours = -phase / 360 * 24;
  double offset = 20;
  double amplitude = 10;

  // with these parameters, the sinusoid value must be the offset (20) at 10 am
  result = noisySinusoid(offset, amplitude, 60 * 60 * 24, 60 * 60 * timeInHours,
                         phase, zeroNoise);
  // printf("sinusoid value: %lf \n", result);

  return result == offset;
}

double zeroNoise(double amplitude) {
  return 0;
}