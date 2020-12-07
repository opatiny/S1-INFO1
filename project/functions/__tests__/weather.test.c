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

int test_luminosityModel(void) {
  LUMINOSITY test = {.max = 10,
                     .min = 0,
                     .intervals = {5 * 3600, 10 * 3600, 15 * 3600, 20 * 3600}};

  for (double hour = 0; hour < 24; hour++) {
    luminosityModel(hour * 3600, &test);
    printf("time: %lf, luminosity: %lf \n", hour, test.current);
  }
  return 0;
}

int test_setTwilightLuminosity(void) {
  LUMINOSITY test = {.max = 10,
                     .min = 0,
                     .intervals = {5 * 3600, 10 * 3600, 15 * 3600, 20 * 3600}};

  setTwilightLuminosity();

  return 0;
}

int test_line(void) {
  if (line(0, 1, 0) != 0) {
    return 0;
  }
  if (line(1, 1, 0) != 1) {
    return 0;
  }
  if (line(2, 0.5, 2) != 3) {
    return 0;
  }
  if (line(1, -2, 0) != -2) {
    return 0;
  }
  return 1;
}
