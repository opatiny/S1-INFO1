#define _USE_MATH_DEFINES

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "Scheduler.h"

// DEFINES
// our basic time unit is the second
#define TIC_LENGTH \
  60 * 60               // in seconds (one hour) -> accuracy of the simulation
#define NUMBER_TICS 24  // defines the simulation length

// defining the number of tics to wait between each cal of every function
#define WEATHER_LIGHT_SAMPLING 1
#define WEATHER_TEMP_SAMPLING 1
#define PROBE_TEMP_SAMPLING 1
#define PROBE_LIGHT_SAMPLING 4
#define CONTROLLER_LIGHT_SAMPLING 5
#define CONTROLLER_PH_SAMPLING 6
#define DATA_HANDLER_SAMPLING 7

#define LAUSANNE_SUMMER 0
#define LAUSANNE_WINTER 1
#define ROOM_1 0
#define ROOM_2 1
#define AQUARIUM_1 0

int Scheduler(void) {
  printf("inside scheduler\n");

  for (int currentTIC = 1; currentTIC < NUMBER_TICS + 1; currentTIC++) {
    printf("\nTIC %i\n", currentTIC);

    u_int32_t currentTimeOfDay =
        currentTIC * TIC_LENGTH %
        (24 * 3600);  // current time of day in seconds
                      // has to be on 32 bites because 24*3600 = 84'600 > 65'535

    if (!(currentTIC % WEATHER_LIGHT_SAMPLING)) {
      updateWeatherLuminosity(currentTimeOfDay, LAUSANNE_SUMMER);
      double weatherLuminosity = getWeatherLuminosity(LAUSANNE_SUMMER);
      printf("weather luminosity updated: %.2lf \n", weatherLuminosity);
    }
    if (!(currentTIC % WEATHER_TEMP_SAMPLING)) {
      updateWeatherTemperature(currentTimeOfDay, LAUSANNE_SUMMER);
      double weatherTemperature = getWeatherTemperature(LAUSANNE_SUMMER);
      printf("weather temperature updated: %.2lf \n", weatherTemperature);
    }
    if (!(currentTIC % PROBE_TEMP_SAMPLING)) {
      updateRoomTemperature(ROOM_1);
      double temperatureRoom1 = getRoomTemperature(ROOM_1);
      printf("temperature of room 1 updated: %.2lf \n", temperatureRoom1);
      updateRoomTemperature(ROOM_2);
      double temperatureRoom2 = getRoomTemperature(ROOM_2);
      printf("temperature of room 2 updated: %.2lf \n", temperatureRoom2);
    }
    if (!(currentTIC % PROBE_LIGHT_SAMPLING)) {
      updateRoomLuminosity(1);
    }
    if (!(currentTIC % CONTROLLER_LIGHT_SAMPLING)) {
      temperatureControl();
    }
    if (!(currentTIC % CONTROLLER_PH_SAMPLING)) {
      phControl(AQUARIUM_1);
    }
    if (!(currentTIC % DATA_HANDLER_SAMPLING)) {
      dataHandler();
    }
  }

  return 0;
}
