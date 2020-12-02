#define _USE_MATH_DEFINES

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// PROTOTYPES
void roomTemperatureModel(double* currentTemperature,
                          double* weatherTemperature,
                          double* weatherImpact,
                          double* controllerTemperature,
                          double* controllerImpact);

// STRUCTURES DEFINITION
typedef struct temperature {
  double current;           // in °C
  double weatherImpact;     // from 0 to 1
  double controllerImpact;  // from 0 to 1
} TEMPERATURE;

typedef struct luminosity {
  double current;           // in lux
  double weatherImpact;     // from 0 to 1
  double controllerImpact;  // from 0 to 1 -> will not be implemented
} LUMINOSITY;

typedef struct room {
  TEMPERATURE temperature;
  LUMINOSITY luminosity;
} ROOM;

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
double updateRoomTemperature(int roomNumber) {
  double weatherTemperature = 10;     // in °C
  double controllerTemperature = 15;  // in °C

  roomTemperatureModel(
      &rooms[roomNumber - 1].temperature.current, &weatherTemperature,
      &rooms[roomNumber - 1].temperature.weatherImpact, &controllerTemperature,
      &rooms[roomNumber - 1].temperature.controllerImpact);

  return rooms[roomNumber - 1].temperature.current;
}

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
    - void (modifies the value in currentTemperature)
  Author: Océane Patiny
 */
void roomTemperatureModel(double* currentTemperature,
                          double* weatherTemperature,
                          double* weatherImpact,
                          double* controllerTemperature,
                          double* controllerImpact) {
  *currentTemperature =
      *currentTemperature +
      *weatherImpact * (*weatherTemperature - *currentTemperature) +
      *controllerImpact * (*controllerTemperature - *currentTemperature);
}

double updateRoomLuminosity(int roomNumber) {
  double weatherLuminosity = 20000;  // temporary value

  rooms[roomNumber - 1].luminosity.current =
      weatherLuminosity * rooms[roomNumber - 1].luminosity.weatherImpact;

  return rooms[roomNumber - 1].luminosity.current;
}
