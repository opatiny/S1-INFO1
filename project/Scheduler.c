#define _USE_MATH_DEFINES

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SIMULATION_SPAN  // length of the simulaton => in what unit?
#define TIC 60           // in seconds
#define NUMBER_TICS 10

// defining the number of tics to wait between each cal of every function
#define WEATHER_LIGHT_SAMPLING 1
#define WEATHER_TEMP_SAMPLING 2
#define PROBE_TEMP_SAMPLING 3
#define PROBE_LIGHT_SAMPLING 4
#define CONTROLLER_LIGHT_SAMPLING 5
#define CONTROLLER_PH_SAMPLING 6
#define DATA_HANDLER_SAMPLING 7

int Scheduler(void) {
  printf("entering scheduler\n");
  for (int currentTIC = 0; currentTIC < NUMBER_TICS; currentTIC++) {
    if (!(currentTIC % WEATHER_LIGHT_SAMPLING)) {
      extLuminosity();
    } else if (!(currentTIC % WEATHER_TEMP_SAMPLING)) {
      extTemperature();
    } else if (!(currentTIC % PROBE_TEMP_SAMPLING)) {
      tempProbe();
    } else if (!(currentTIC % PROBE_LIGHT_SAMPLING)) {
      lightProbe();
    } else if (!(currentTIC % CONTROLLER_LIGHT_SAMPLING)) {
      temperatureControl();
    } else if (!(currentTIC % CONTROLLER_PH_SAMPLING)) {
      phControl();
    } else if (!(currentTIC % DATA_HANDLER_SAMPLING)) {
      dataHandler();
    }
  }

  return 0;
}
