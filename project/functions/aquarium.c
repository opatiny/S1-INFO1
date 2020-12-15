#define _USE_MATH_DEFINES

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "aquarium.h"

// PROTOTYPES
int phModel(AQUARIUM* aquarium, double roomLuminosity, double pumpValue);

// STRUCTURES INITIALIZATION
AQUARIUM aquarium = {.currentPH = 7,
                     .luminosityImpact = 0.5,
                     .luminosityThreshold = 10000,
                     .pumpImpact = 0.3};

// FUNCTIONS
int updatePH(void) {
  double roomLuminosity = 20000;
  double pumpValue = 40;
  phModel(&aquarium, roomLuminosity, pumpValue);
  return 0;
}

int phModel(AQUARIUM* aquarium, double roomLuminosity, double pumpValue) {
  aquarium->currentPH = aquarium->luminosityImpact *
                            (roomLuminosity - aquarium->luminosityThreshold) +
                        aquarium->pumpImpact * pumpValue;
  return 0;
}