#ifndef PROBES_H
#define PROBES_H

void roomTemperatureModel(
    double* currentTemperature,
    double* weatherTemperature,
    double* weatherImpact,
    double* controllerTemperature,
    double* controllerImpact);  // public only for testing!!

double updateRoomTemperature(int roomNumber);
double updateRoomLuminosity(int roomNumber);

#endif
