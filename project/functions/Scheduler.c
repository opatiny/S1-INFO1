#define _USE_MATH_DEFINES

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// our basic time unit is the second

#define SIMULATION_LENGTH   // length of the simulaton => in seconds
#define TIC_LENGTH 60 * 60  // in seconds
#define NUMBER_TICS 10      // will depend on SIMULATION_LENGTH

// defining the number of tics to wait between each cal of every function
#define WEATHER_LIGHT_SAMPLING 1
#define WEATHER_TEMP_SAMPLING 2
#define PROBE_TEMP_SAMPLING 3
#define PROBE_LIGHT_SAMPLING 4
#define CONTROLLER_LIGHT_SAMPLING 5
#define CONTROLLER_PH_SAMPLING 6
#define DATA_HANDLER_SAMPLING 7

// prototypes
int updateExtLuminosity(void);
int updateExtTemperature(int currentTime, int index);
int tempProbe(void);
int lightProbe(void);
int temperatureControl(void);
int phControl(void);
int dataHandler(void);

int Scheduler(void) {
  printf("inside scheduler\n");

  for (int currentTIC = 1; currentTIC < NUMBER_TICS + 1; currentTIC++) {
    printf("\nTIC %i\n", currentTIC);

    int currentTime = currentTIC * TIC_LENGTH;  // current time in seconds

    if (!(currentTIC % WEATHER_LIGHT_SAMPLING)) {
      updateExtLuminosity();
    }
    if (!(currentTIC % WEATHER_TEMP_SAMPLING)) {
      updateExtTemperature(currentTime, 0);
    }
    if (!(currentTIC % PROBE_TEMP_SAMPLING)) {
      tempProbe();
    }
    if (!(currentTIC % PROBE_LIGHT_SAMPLING)) {
      lightProbe();
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
