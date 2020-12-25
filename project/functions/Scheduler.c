#define _USE_MATH_DEFINES

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "Scheduler.h"
#include "aquarium.h"
#include "controllers.h"
#include "dataHandler.h"
#include "outputFormatting.h"
#include "rooms.h"
#include "weather.h"

// DEFINES
// simulation length parameters (the basic time unit is one second)
#define TIC_LENGTH \
  60 * 60               // in seconds (one hour) -> accuracy of the simulation
#define NUMBER_TICS 24  // defines the simulation length

// defining the number of tics to wait between each call of the functions
#define WEATHER_LIGHT_SAMPLING 1
#define WEATHER_TEMPERATURE_SAMPLING 1
#define ROOMS_TEMPERATURE_SAMPLING 1
#define ROOMS_LIGHT_SAMPLING 4
#define AQUARIUM_PH_SAMPLING 4
#define TEMPERATURE_CONTROL_SAMPLING 5
#define LIGHT_CONTROL_SAMPLING 5
#define PH_CONTROL_SAMPLING 6
#define DATA_HANDLER_SAMPLING 7

// indexes in weather structures array
#define LAUSANNE_SUMMER 0
#define LAUSANNE_WINTER 1

// number of instances of different structures
#define NB_ROOMS 2
#define NB_AQUARIUMS 1

// STRUCTURES INITIALIZATION
DATA data = {.showControlValues = 1,
             .exportData = 0};  // setting options for output data

// FUNCTIONS
int Scheduler(void) {
  printf("Welcome to this basic domotics simulator.\n\n");

  printf("The TIC length is %i seconds.\n\n", TIC_LENGTH);

  printHeader(&data);

  for (int currentTIC = 1; currentTIC < NUMBER_TICS + 1; currentTIC++) {
    data.TIC = currentTIC;

    u_int32_t currentTimeOfDay =
        currentTIC * TIC_LENGTH %
        (24 * 3600);  // current time of day in seconds
                      // has to be on 32 bites because 24*3600 = 84'600 > 65'535

    if (currentTIC == 1 | !(currentTIC % WEATHER_LIGHT_SAMPLING)) {
      updateWeatherLuminosity(currentTimeOfDay, LAUSANNE_SUMMER);
      double weatherLuminosity = getWeatherLuminosity(LAUSANNE_SUMMER);
      data.weatherLuminosity = weatherLuminosity;
    }
    if (!(currentTIC % WEATHER_TEMPERATURE_SAMPLING)) {
      updateWeatherTemperature(currentTimeOfDay, LAUSANNE_SUMMER);
      double weatherTemperature = getWeatherTemperature(LAUSANNE_SUMMER);
      data.weatherTemperature = weatherTemperature;
    }
    if (!(currentTIC % ROOMS_TEMPERATURE_SAMPLING)) {
      for (int i = 0; i < NB_ROOMS; i++) {
        updateRoomTemperature(i);
        double roomTemperature = getRoomTemperature(i);
        if (i < NB_ROOMS_OUTPUT) {
          data.roomsTemperature[i] = roomTemperature;
        }
      }
    }
    if (!(currentTIC % ROOMS_LIGHT_SAMPLING)) {
      for (int i = 0; i < NB_ROOMS; i++) {
        updateRoomLuminosity(i);
        double roomLuminostiy = getRoomLuminosity(i);
        if (i < NB_ROOMS_OUTPUT) {
          data.roomsLuminostiy[i] = roomLuminostiy;
        }
      }
    }
    if (!(currentTIC % AQUARIUM_PH_SAMPLING)) {
      for (int i = 0; i < NB_AQUARIUMS; i++) {
        updatePH(i);
        double aquariumPH = getPH(i);
        if (i < NB_AQUARIUMS_OUTPUT) {
          data.aquariumsPH[i] = aquariumPH;
        }
      }
    }
    if (!(currentTIC % TEMPERATURE_CONTROL_SAMPLING)) {
      for (int i = 0; i < NB_ROOMS; i++) {
        temperatureControl(i);
        double temperatureControlValue = getTemperatureControlValue(i);
        if (i < NB_ROOMS_OUTPUT) {
          data.temperatureControllers[i] = temperatureControlValue;
        }
      }
    }
    if (!(currentTIC % LIGHT_CONTROL_SAMPLING)) {
      // no controller implemented
    }
    if (!(currentTIC % PH_CONTROL_SAMPLING)) {
      for (int i = 0; i < NB_AQUARIUMS; i++) {
        phControl(i);
        double phControlValue = getPhControlValue(i);
        if (i < NB_AQUARIUMS_OUTPUT) {
          data.phControllers[i] = phControlValue;
        }
      }
    }
    if (!(currentTIC % DATA_HANDLER_SAMPLING)) {
      dataHandler();
    }
    printDataLine(&data);
  }

  return 0;
}
