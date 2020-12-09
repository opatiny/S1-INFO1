#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../lib/testcases.h"
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
    return TEST_FAILING;
  }
  if (temperatureTenAM > temperatureFourPM) {
    return TEST_FAILING;
  }
  if (temperatureFourPM < temperatureMidnight) {
    return TEST_FAILING;
  }

  return TEST_PASSING;
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
  if (result == offset) {
    return TEST_PASSING;
  } else {
    return TEST_FAILING;
  }
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
    // printf("time: %lf, luminosity: %lf \n", hour, test.current);
  }
  return TEST_FAILING;
}

int test_setTwilightLuminosity(void) {
  int NUMBER_CASES = 4;
  int TEST_STATE = NUMBER_CASES;

  LUMINOSITY test = {.current = 42,
                     .max = 10,
                     .min = 0,
                     .intervals = {5 * 3600, 10 * 3600, 15 * 3600, 20 * 3600}};
  int result;
  double expected;
  double slopeIncreasing = 10.0 / (5 * 3600);
  double slopeDecreasing = -10.0 / (5 * 3600);

  setTwilightLuminosity(7 * 3600, &test, 'r');
  shouldBeEqual_d(&TEST_STATE, test.current, 2 * 3600 * slopeIncreasing, 0);

  result = setTwilightLuminosity(20 * 3600, &test, 'r');
  shouldBeEqual_i(&TEST_STATE, result, 1);

  result = setTwilightLuminosity(1 * 3600, &test, 's');
  shouldBeEqual_i(&TEST_STATE, result, 2);

  result = setTwilightLuminosity(20 * 3600, &test, 't');
  shouldBeEqual_i(&TEST_STATE, result, 3);

  if (TEST_STATE == NUMBER_CASES) {
    return TEST_PASSING;
  } else {
    return TEST_FAILING;
  }
}

int test_line(void) {
  if (line(0, 1, 0) != 0) {
    return TEST_FAILING;
  }
  if (line(1, 1, 0) != 1) {
    return TEST_FAILING;
  }
  if (line(2, 0.5, 2) != 3) {
    return TEST_FAILING;
  }
  if (line(1, -2, 0) != -2) {
    return TEST_FAILING;
  }
  return TEST_PASSING;
}
