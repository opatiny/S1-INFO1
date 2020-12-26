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
    .currentPH = 6.5,  // acidic, because simulation starts at midnight
    .luminosityImpact = 1e-6,
    .luminosityThreshold = 30000,
    .pumpImpact = 2.5,
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
  // adding these conditions to stay in possible range of PH
  if (aquarium->currentPH < 0) {
    aquarium->currentPH = 0;
  } else if (aquarium->currentPH > 14) {
    aquarium->currentPH = 14;
  }
  return 0;
}

int setPumpValue(int index, double value) {
  aquariums[index].pumpValue = value;
  return 0;
}

double getPH(int index) {
  return aquariums[index].currentPH;
}
