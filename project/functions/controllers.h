#ifndef CONTROLLERS_H
#define CONTROLLERS_H

// STRUCTURES
typedef struct pump {
  double currentValue;  // in ??
  double phThreshold;   // from 0 to 14
  double factor;        // no dimension
} PUMP;

typedef struct temperature_controller {
  double currentValue;             // in ??
  double minTemperatureThreshold;  // in °C
  double maxTemperatureThreshold;  // in °C
  double factor;                   // no dimension
} TEMPERATURE_CONTROLLER;

// PUBLIC FUNCTIONS
int temperatureControl(int index);
int phControl(int index);

#endif
