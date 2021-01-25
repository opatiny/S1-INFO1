#define _USE_MATH_DEFINES

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aquarium.h"
#include "controllers.h"
#include "messages/dataHandler.h"
#include "rooms.h"

// DEFINES
#define NB_TEMPERATURE_CONTROLLERS 2
#define NB_PUMPS 1

#define TEMPERATURE_EVENT 1  // unique identifier of a temperature event
#define PH_EVENT 2           // unique identifier of a luminosity event

// PROTOTYPES
int temperatureControlModel(double roomTemperature, TEMPERATURE_CONTROLLER* tc);
int phControlModel(double currentPH, PUMP* pump);

// STRUCTURES INITIALIZATION
TEMPERATURE_CONTROLLER temperature_controllers[NB_TEMPERATURE_CONTROLLERS] = {
    {.minTemperatureThreshold = 20, .maxTemperatureThreshold = 25, .factor = 2},
    {.minTemperatureThreshold = 20,
     .maxTemperatureThreshold = 22,
     .factor = 3}};

// there could be many pumps in case they are many aquariums
PUMP pumps[NB_PUMPS] = {{.currentValue = 0, .phThreshold = 6.5, .factor = 1}};

// FUNCTIONS

int announceControllers(void) {
  for (int i = 0; i < NB_TEMPERATURE_CONTROLLERS; i++) {
    char address[] = "temperature control room ";
    char roomNumber[10];
    int id = i;
    sprintf(roomNumber, "%i", i);
    strcat(address, roomNumber);
    write_MSG1(id, address);
    write_MSG2(id, TEMPERATURE_EVENT, "temperature");
  }
  for (int i = 0; i < NB_PUMPS; i++) {
    char address[] = "PH control aquarium ";
    char roomNumber[10];
    int id = i + NB_TEMPERATURE_CONTROLLERS;  // to be sure to have no overlap
                                              // in controllers IDs
    sprintf(roomNumber, "%i", i);
    strcat(address, roomNumber);
    write_MSG1(i, address);
    write_MSG2(id, TEMPERATURE_EVENT, "PH");
  }
}

/* temperatureControl(): update current value of given temperature controller
  PARAMETERS:
    - index (int): index of the temperature controller struct to modify
  RETURNS:
    - (int): possible error message
  Author: Océane Patiny
 */
int temperatureControl(int index) {
  double roomTemperature = getRoomTemperature(index);
  temperatureControlModel(roomTemperature, &temperature_controllers[index]);
  setTemperatureControllerValue(index,
                                temperature_controllers[index].currentValue);
  return 0;
}

/* temperatureControlModel(): sets current value of a temperature controller
  struct instance depending on the current temperature of the corresponding room
  PARAMETERS:
    - roomTemperature (double): current temperature of the room
    - tc (TEMPERATURE_CONTROLLER*): pointer on temperature controller struct
  instance
  RETURNS:
    - (int): possible error message
  Author: Océane Patiny
 */
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

/* phControl(): update current value of given PH controller
  PARAMETERS:
    - index (int): index of the PH controller struct to modify
  RETURNS:
    - (int): possible error message
  Author: Océane Patiny
 */
int phControl(int index) {
  double currentPH = getPH(index);
  phControlModel(currentPH, &pumps[index]);
  setPumpValue(index, pumps[index].currentValue);
  return 0;
}

/* phControlModel(): sets current value of a pump struct instance depending on
  the current PH of the corresponding aquarium PARAMETERS:
    - currentPH (double): current PH of the aquarium
    - pump (PUMP*): pointer on pump struct instance

  RETURNS:
    - (int): possible error message
  Author: Océane Patiny
 */
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