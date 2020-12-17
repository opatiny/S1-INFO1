#ifndef ROOMS_H
#define ROOMS_H

// STRUCTURES
typedef struct room_temperature {
  double current;           // in °C
  double weatherImpact;     // from 0 to 1
  double controllerImpact;  // from 0 to 1
} ROOM_TEMPERATURE;

typedef struct room_luminosity {
  double current;           // in lux
  double weatherImpact;     // from 0 to 1
  double controllerImpact;  // from 0 to 1 -> will not be implemented
} ROOM_LUMINOSITY;

typedef struct room {
  ROOM_TEMPERATURE temperature;
  ROOM_LUMINOSITY luminosity;
} ROOM;

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