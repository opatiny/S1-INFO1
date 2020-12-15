#ifndef AQUARIUM_H
#define AQUARIUM_H

// STRUCTURES
typedef struct aquarium {
  double currentPH;            // in °C
  double luminosityImpact;     // from 0 to 1
  double luminosityThreshold;  // in lux
  double pumpImpact;           // from 0 to 1
} AQUARIUM;

// PUBLIC FUNCTIONS

// PUBLIC ONLY FOR TESTING

#endif