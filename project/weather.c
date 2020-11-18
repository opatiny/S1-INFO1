#define _USE_MATH_DEFINES

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct temperature {
  double amplitude;
  double period;
  double phase;
  double offset;
  double currentTemperature;
} TEMPERATURE;

extern TEMPERATURE temperatures[2];

typedef struct room {
  double temperature;
  double luminosity;
} ROOM;

extern ROOM rooms[2];

// prototypes
double noise(double amplitude);

int extLuminosity(void) {
  printf("external luminosity\n");
  return 0;
}

int extTemperature(int currentTime, TEMPERATURE temperatures[], int index) {
  double noise = noise(temperatures[0].amplitude);
  double omega = 2 * M_PI / temperatures[index].period;
  temperatures[index].currentTemperature =
      temperatures[index].offset +
      temperatures[index].amplitude *
          cos((omega * currentTime + temperatures[index].phase) * M_PI / 180) +
      noise;

  printf("external temperature updated to ...\n");

  return 0;
}

double noise(double amplitude) {
  return amplitude * (2 * (double)rand() / RAND_MAX - 1) / 10;
}