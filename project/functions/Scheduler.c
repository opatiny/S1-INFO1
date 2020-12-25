#define _USE_MATH_DEFINES

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "Scheduler.h"
#include "aquarium.h"
#include "controllers.h"
#include "dataHandler.h"
#include "rooms.h"
#include "weather.h"

// DEFINES
// our basic time unit is the second
#define TIC_LENGTH \
  60 * 60              // in seconds (one hour) -> accuracy of the simulation
#define NUMBER_TICS 2  // defines the simulation length

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
#define NB_ROOMS 2
#define NB_AQUARIUMS 1

// PROTOTYPES
void printHeader(void);
void printDataLine(DATA* data);

// STRUCTURES INITIALIZATION
DATA data;

// FUNCTIONS
int Scheduler(void) {
  printf("Welcome to this basic domotics simulator.\n");

  printf("The TIC length is %i seconds.\n\n", TIC_LENGTH);

  printHeader();

  for (int currentTIC = 1; currentTIC < NUMBER_TICS + 1; currentTIC++) {
    data.TIC = currentTIC;

    u_int32_t currentTimeOfDay =
        currentTIC * TIC_LENGTH %
        (24 * 3600);  // current time of day in seconds
                      // has to be on 32 bites because 24*3600 = 84'600 > 65'535

    if (!(currentTIC % WEATHER_LIGHT_SAMPLING)) {
      updateWeatherLuminosity(currentTimeOfDay, LAUSANNE_SUMMER);
      double weatherLuminosity = getWeatherLuminosity(LAUSANNE_SUMMER);
      data.weatherLuminosity = weatherLuminosity;
    }
    if (!(currentTIC % WEATHER_TEMP_SAMPLING)) {
      updateWeatherTemperature(currentTimeOfDay, LAUSANNE_SUMMER);
      double weatherTemperature = getWeatherTemperature(LAUSANNE_SUMMER);
      data.weatherTemperature = weatherTemperature;
    }
    if (!(currentTIC % PROBE_TEMP_SAMPLING)) {
      for (int i = 0; i < NB_ROOMS; i++) {
        updateRoomTemperature(i);
        double roomTemperature = getRoomTemperature(i);
        // printf("temperature of room %i updated: %.2lf \n", i +
        // 1, roomTemperature);
      }
    }
    if (!(currentTIC % PROBE_LIGHT_SAMPLING)) {
      for (int i = 0; i < NB_ROOMS; i++) {
        updateRoomLuminosity(i);
        double roomLuminostiy = getRoomLuminosity(i);
        // printf("luminosity of room %i updated: %.2lf \n", i + 1,
        //       roomLuminostiy);
      }
    }
    if (!(currentTIC % CONTROLLER_LIGHT_SAMPLING)) {
      // no controller implemented
    }
    if (!(currentTIC % CONTROLLER_PH_SAMPLING)) {
      for (int i = 0; i < NB_AQUARIUMS; i++) {
        phControl(i);
        double aquariumPH = getPH(i);
        // printf("PH of aquarium %i updated: %.2lf \n", i + 1, aquariumPH);
      }
    }
    if (!(currentTIC % DATA_HANDLER_SAMPLING)) {
      dataHandler();
    }
    printDataLine(&data);
  }

  return 0;
}

void printHeader(void) {
  printf("%5s %15s %15s %15s %15s %15s %15s %15s \n", "TIC", "weather temp.",
         "weather lum.", "room 1 temp.", "room 1 lum.", "room 2 temp.",
         "room2 lum.", "aquarium 1 PH");
}

void printDataLine(DATA* data) {
  printf("%5i %15d %15d %15d %15d %15d %15d %15d \n", data->TIC,
         data->weatherTemperature, data->weatherLuminosity,
         data->temperatureRoom1, data->luminosityRoom1, data->temperatureRoom1,
         data->luminosityRoom1, data->aquariumPH);
}