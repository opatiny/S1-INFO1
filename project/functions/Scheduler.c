#define _USE_MATH_DEFINES

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "Scheduler.h"

// DEFINES
// our basic time unit is the second
#define SIMULATION_LENGTH   // length of the simulaton => in seconds
#define TIC_LENGTH 60 * 60  // in seconds (one hour)
#define NUMBER_TICS 24      // will depend on SIMULATION_LENGTH

// defining the number of tics to wait between each cal of every function
#define WEATHER_LIGHT_SAMPLING 1
#define WEATHER_TEMP_SAMPLING 1
#define PROBE_TEMP_SAMPLING 1
#define PROBE_LIGHT_SAMPLING 4
#define CONTROLLER_LIGHT_SAMPLING 5
#define CONTROLLER_PH_SAMPLING 6
#define DATA_HANDLER_SAMPLING 7

#define ROOM_1 1
#define ROOM_2 2
#define LAUSANNE_SUMMER 0
#define LAUSANNE_WINTER 1

int Scheduler(void) {
  printf("inside scheduler\n");

  for (int currentTIC = 1; currentTIC < NUMBER_TICS + 1; currentTIC++) {
    printf("\nTIC %i\n", currentTIC);

    int currentTime = currentTIC * TIC_LENGTH;  // current time in seconds

    if (!(currentTIC % WEATHER_LIGHT_SAMPLING)) {
      updateWeatherLuminosity(currentTime, 0);
    }
    if (!(currentTIC % WEATHER_TEMP_SAMPLING)) {
      double weatherTemperature;
      weatherTemperature = updateWeatherTemperature(currentTime, 0);
      printf("weather temperature updated: %lf \n", weatherTemperature);
    }
    if (!(currentTIC % PROBE_TEMP_SAMPLING)) {
      double roomTemperature;

      roomTemperature = updateRoomTemperature(1);
      printf("room temperature updated: %lf \n", roomTemperature);
    }
    if (!(currentTIC % PROBE_LIGHT_SAMPLING)) {
      updateRoomLuminosity(1);
    }
    if (!(currentTIC % CONTROLLER_LIGHT_SAMPLING)) {
      temperatureControl();
    }
    if (!(currentTIC % CONTROLLER_PH_SAMPLING)) {
      phControl();
    }
    if (!(currentTIC % DATA_HANDLER_SAMPLING)) {
      dataHandler();
    }
  }

  return 0;
}
