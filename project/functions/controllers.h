#ifndef CONTROLLERS_H
#define CONTROLLERS_H

// STRUCTURES
typedef struct pump {
  double currentValue;  // in ??
  double phThreshold;   // PH from 0 to 14
  double factor;        // no dimension
} PUMP;

typedef struct temperature_controller {
  double currentValue;             // in °C
  double minTemperatureThreshold;  // in °C
  double maxTemperatureThreshold;  // in °C
  double factor;                   // no dimension
} TEMPERATURE_CONTROLLER;

// PUBLIC FUNCTIONS
int temperatureControl(int index);
int phControl(int index);

double getTemperatureControlValue(int index);
double getPhControlValue(int index);

// PUBLIC ONLY FOR TESTING
int temperatureControlModel(double roomTemperature, TEMPERATURE_CONTROLLER* tc);
int phControlModel(double currentPH, PUMP* pump);

#endif
