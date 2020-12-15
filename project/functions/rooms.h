#ifndef ROOMS_H
#define ROOMS_H

// STRUCTURES
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

typedef struct aquarium {
  double currentPH;            // in °C
  double luminosityImpact;     // from 0 to 1
  double luminosityThreshold;  // in lux
  double pumpImpact;           // from 0 to 1
} AQUARIUM;

// PUBLIC FUNCTIONS

int updateRoomTemperature(int roomNumber);
int updateRoomLuminosity(int roomNumber);

double getRoomTemperature(int roomNumber);
double getRoomLuminosity(int roomNumber);

// PUBLIC ONLY FOR TESTING
int roomTemperatureModel(
    double* currentTemperature,
    double* weatherTemperature,
    double* weatherImpact,
    double* controllerTemperature,
    double* controllerImpact);  // public only for testing!!

#endif
