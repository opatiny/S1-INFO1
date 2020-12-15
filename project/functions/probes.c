#define _USE_MATH_DEFINES

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "probes.h"

// PROTOTYPES
int roomTemperatureModel(double* currentTemperature,
                         double* weatherTemperature,
                         double* weatherImpact,
                         double* controllerTemperature,
                         double* controllerImpact);

// STRUCTURES INITIALIZATION
// defining all parameters for rooms 1 and 2
ROOM rooms[2] = {{.temperature = {.current = 15,
                                  .weatherImpact = 0.2,
                                  .controllerImpact = 0.5},
                  .luminosity = {.current = 10000,
                                 .weatherImpact = 0.9,
                                 .controllerImpact = 0.8}},
                 {.temperature = {.current = 20,
                                  .weatherImpact = 0.2,
                                  .controllerImpact = 0.5},
                  .luminosity = {.current = 11000,
                                 .weatherImpact = 0.9,
                                 .controllerImpact = 0.8}}};

// FUNCTIONS
// in our case, "roomNumber" can be 1 or 2
int updateRoomTemperature(int roomNumber) {
  double weatherTemperature = 10;     // in °C
  double controllerTemperature = 15;  // in °C

  roomTemperatureModel(
      &rooms[roomNumber - 1].temperature.current, &weatherTemperature,
      &rooms[roomNumber - 1].temperature.weatherImpact, &controllerTemperature,
      &rooms[roomNumber - 1].temperature.controllerImpact);

  return 0;
}

int updateRoomLuminosity(int roomNumber) {
  double weatherLuminosity = 20000;  // temporary value

  rooms[roomNumber - 1].luminosity.current =
      weatherLuminosity * rooms[roomNumber - 1].luminosity.weatherImpact;

  return 0;
}

double getRoomTemperature(int roomNumber) {
  return rooms[roomNumber - 1].temperature.current;
}

double getRoomLuminosity(int roomNumber) {
  return rooms[roomNumber - 1].luminosity.current;
}

// PRIVATE FUNCTIONS

/* roomTemperatureModel(): updates a room's temperature depending on various
  parameters

  PARAMETERS:
    -  currentTemperature (double*): initial room temperature in °C
    -  weatherTemperature (double*): weather temperature in °C
    -  weatherImpact (double*): impact of weather temperature on room
  temperature [0,1]
    -  controllerTemperature (double*): initial room temperature in °C
    -  controllerImpact (double*): impact of controller temperature on room
  temperature [0,1]

  RETURNS:
    - int (possible error message)
  Author: Océane Patiny
 */
int roomTemperatureModel(double* currentTemperature,
                         double* weatherTemperature,
                         double* weatherImpact,
                         double* controllerTemperature,
                         double* controllerImpact) {
  *currentTemperature =
      *currentTemperature +
      *weatherImpact * (*weatherTemperature - *currentTemperature) +
      *controllerImpact * (*controllerTemperature - *currentTemperature);
  return 0;
}