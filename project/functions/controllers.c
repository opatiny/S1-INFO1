#define _USE_MATH_DEFINES

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "aquarium.h"
#include "controllers.h"
#include "rooms.h"

// PROTOTYPES
int temperatureControlModel(double roomTemperature, TEMPERATURE_CONTROLLER* tc);

// STRUCTURES INITIALIZATION
TEMPERATURE_CONTROLLER temperature_controllers[2] = {
    {.minTemperatureThreshold = 18, .maxTemperatureThreshold = 23, .factor = 1},
    {.minTemperatureThreshold = 16,
     .maxTemperatureThreshold = 25,
     .factor = 1}};

// there could be many pumps in case they are many aquariums
PUMP pumps[2] = {{.currentValue = 100, .phThreshold = 6.5, .factor = 10}};

// FUNCTIONS
int temperatureControl(int index) {
  double roomTemperature = getRoomTemperature(index);
  temperatureControlModel(roomTemperature, &temperature_controllers[index]);
  setTemperatureControllerValue(index,
                                temperature_controllers[index].currentValue);
  return 0;
}

int temperatureControlModel(double roomTemperature,
                            TEMPERATURE_CONTROLLER* tc) {
  if (roomTemperature < tc->minTemperatureThreshold) {
    tc->currentValue = tc->factor * (tc->minTemperatureThreshold -
                                     tc->minTemperatureThreshold);
  } else if (roomTemperature > tc->maxTemperatureThreshold) {
    tc->currentValue =
        tc->factor * (roomTemperature - tc->maxTemperatureThreshold);
  } else {
    tc->currentValue = 0;
  }
  return 0;
}

int phControl(int index) {
  double currentPH = getPH(index);
  pumps[index].currentValue =
      pumps[index].factor * (currentPH - pumps[index].phThreshold);
  setPumpValue(index, pumps[index].currentValue);
  return 0;
}

int phControlModel(double currentPH, PUMP* pump) {
  pump->currentValue = pump->factor * (currentPH - pump->phThreshold);
  return 0;
}

double getPumpValue(int index) {
  return pumps[index].currentValue;
}