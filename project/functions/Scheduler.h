#ifndef SCHEDULER_H
#define SCHEDULER_H

int Scheduler(void);

typedef struct data {
  int TIC;
  double weatherTemperature;
  double weatherLuminosity;
  double roomsTemperature[2];
  double roomsLuminostiy[2];
  double aquariumsPH[1];
} DATA;

#endif
