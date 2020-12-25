#include "../../lib/testcases.h"
#include "../rooms.h"

int test_roomTemperatureModel(void) {
  int NB_CASES_FAILING = 0;

  double initialTemperature = 25;
  double currentTemperature = 25;
  double weatherTemperature = 30;
  double weatherImpact = 0;
  double controllerValue = -5;
  double controllerImpact = 1;

  roomTemperatureModel(&currentTemperature, weatherTemperature, weatherImpact,
                       controllerValue, controllerImpact);

  shouldBeSmallerThan_d(&NB_CASES_FAILING, currentTemperature,
                        initialTemperature);

  currentTemperature = initialTemperature;
  weatherImpact = 1;
  controllerImpact = 0;

  roomTemperatureModel(&currentTemperature, weatherTemperature, weatherImpact,
                       controllerValue, controllerImpact);

  shouldBeGreaterThan_d(&NB_CASES_FAILING, currentTemperature,
                        initialTemperature);

  if (NB_CASES_FAILING) {
    return TEST_FAILING;
  }

  return TEST_PASSING;
}

int test_roomLuminosityModel(void) {
  int NB_CASES_FAILING = 0;

  double currentLuminosity = 0;
  roomLuminosityModel(currentLuminosity, 20000, 1);
  shouldBeEqual_d(NB_CASES_FAILING, currentLuminosity, 20000, 0);

  roomLuminosityModel(currentLuminosity, 100000, 0.5);
  shouldBeEqual_d(NB_CASES_FAILING, currentLuminosity, 50000, 0);

  if (NB_CASES_FAILING) {
    return TEST_FAILING;
  }

  return TEST_PASSING;
}