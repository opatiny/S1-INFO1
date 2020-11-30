#include "../probes.h"

int test_roomTemperatureModel(void) {
  double initialTemperature = 25;
  double currentTemperature = 25;
  double weatherTemperature = 30;
  double weatherImpact = 0;
  double controllerTemperature = 20;
  double controllerImpact = 1;

  roomTemperatureModel(&currentTemperature, &weatherTemperature, &weatherImpact,
                       &controllerTemperature, &controllerImpact);

  if (currentTemperature > initialTemperature) {
    return 0;
  }

  currentTemperature = initialTemperature;
  weatherImpact = 1;
  controllerImpact = 0;

  roomTemperatureModel(&currentTemperature, &weatherTemperature, &weatherImpact,
                       &controllerTemperature, &controllerImpact);
  if (currentTemperature < initialTemperature) {
    return 0;
  }

  return 1;
}

int test_updateRoomTemperature(void) {
  double result = updateRoomTemperature(1);
  return result == 0;
}

int test_updateRoomLuminosity(void) {
  int result = updateRoomLuminosity();
  return result == 1;
}