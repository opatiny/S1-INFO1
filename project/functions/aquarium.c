#define _USE_MATH_DEFINES

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "aquarium.h"
#include "rooms.h"

// PROTOTYPES
int phModel(AQUARIUM* aquarium, double roomLuminosity);

// STRUCTURES INITIALIZATION
// we consider that there could be many aquariums, hence the array
AQUARIUM aquariums[2] = {{
    .currentPH = 7,
    .luminosityImpact = 0.5,
    .luminosityThreshold = 10000,
    .pumpImpact = 0.3,
}};

// FUNCTIONS
int updatePH(int index) {
  double roomLuminosity = getRoomLuminosity(index);
  phModel(&aquariums[index], roomLuminosity);
  return 0;
}

int phModel(AQUARIUM* aquarium, double roomLuminosity) {
  aquarium->currentPH = aquarium->currentPH +
                        aquarium->luminosityImpact *
                            (roomLuminosity - aquarium->luminosityThreshold) +
                        aquarium->pumpImpact * aquarium->pumpValue;
  return 0;
}

int setPumpValue(int index, double value) {
  aquariums[index].pumpValue = value;
  return 0;
}

double getPH(int index) {
  return aquariums[index].currentPH;
}
