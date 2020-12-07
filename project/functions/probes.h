#ifndef PROBES_H
#define PROBES_H

int roomTemperatureModel(
    double* currentTemperature,
    double* weatherTemperature,
    double* weatherImpact,
    double* controllerTemperature,
    double* controllerImpact);  // public only for testing!!

int updateRoomTemperature(int roomNumber);
int updateRoomLuminosity(int roomNumber);

double getRoomTemperature(int roomNumber);
double getRoomLuminosity(int roomNumber);
#endif
