#define _USE_MATH_DEFINES

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "aquarium.h"
#include "controllers.h"
#include "rooms.h"

// PROTOTYPES
int temperatureControlModel(double roomTemperature, TEMPERATURE_CONTROLLER* tc);
int phControlModel(double currentPH, PUMP* pump);

// STRUCTURES INITIALIZATION
TEMPERATURE_CONTROLLER temperature_controllers[2] = {
    {.minTemperatureThreshold = 20, .maxTemperatureThreshold = 25, .factor = 2},
    {.minTemperatureThreshold = 20,
     .maxTemperatureThreshold = 22,
     .factor = 3}};

// there could be many pumps in case they are many aquariums
PUMP pumps[2] = {{.currentValue = 0, .phThreshold = 6.5, .factor = 1}};

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
    tc->currentValue =
        tc->factor * (tc->minTemperatureThreshold - roomTemperature);
  } else if (roomTemperature > tc->maxTemperatureThreshold) {
    tc->currentValue =
        tc->factor * (tc->maxTemperatureThreshold - roomTemperature);
  } else {
    tc->currentValue = 0;
  }
  return 0;
}

int phControl(int index) {
  double currentPH = getPH(index);
  phControlModel(currentPH, &pumps[index]);
  setPumpValue(index, pumps[index].currentValue);
  return 0;
}

int phControlModel(double currentPH, PUMP* pump) {
  if (currentPH < pump->phThreshold) {
    pump->currentValue = pump->factor * (pump->phThreshold - currentPH);
  } else {
    pump->currentValue = 0;
  }
  return 0;
}

double getTemperatureControlValue(int index) {
  return temperature_controllers[index].currentValue;
}

double getPhControlValue(int index) {
  return pumps[index].currentValue;
}