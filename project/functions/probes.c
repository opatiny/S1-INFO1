#define _USE_MATH_DEFINES

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct temperature {
  double current;
  double weatherImpact;
  double controllerImpact;
} TEMPERATURE;

typedef struct luminosity {
  double current;
  double weatherImpact;
  double controllerImpact;
} LUMINOSITY;

typedef struct room {
  TEMPERATURE temperature;
  LUMINOSITY luminosity;
} ROOM;

extern ROOM rooms[2];

int tempProbe(int roomNumber) {
  printf("room temperature measured:\n");
  return 0;
}

int lightProbe(int roomNumber) {
  printf("room luminosity updated\n");
  return 0;
}
