#define _USE_MATH_DEFINES

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// STRUCTURES

// PROTOTYPES
double getNoise(double amplitude);
double noisySinusoid(double offset,
                     double amplitude,
                     double period,
                     double time,
                     double phase);

typedef struct temperature {
  double offset;              // in °C
  double amplitude;           // in °C
  double phase;               // in degrees
  double currentTemperature;  // in °C
} TEMPERATURE;

// actual weather temperature model parameters first element is for winter,
// second element for summer
TEMPERATURE temperatures[2] = {{.offset = 10, .amplitude = 5, .phase = -150},
                               {.offset = 20, .amplitude = 5, .phase = -150}};

int updateExtLuminosity(void) {
  printf("external luminosity\n");
  return 0;
}

int updateExtTemperature(int currentTime, int index) {
  double offset = temperatures[index].offset;
  double amplitude = temperatures[index].amplitude;
  double period = 60 * 60 * 24;  // number of seconds in one day
  double time = currentTime;
  double phase = temperatures[index].phase;

  temperatures[index].currentTemperature =
      noisySinusoid(offset, amplitude, period, time, phase);

  printf("external temperature: %lf\n", temperatures[index].currentTemperature);

  return 0;
}

// phase is in degrees!
double noisySinusoid(double offset,
                     double amplitude,
                     double period,
                     double time,
                     double phase) {
  double omega = 2 * M_PI / period;
  double noise = getNoise(amplitude);
  double result =
      offset + amplitude * sin(omega * time + phase * M_PI / 180) + noise;
  return result;
}

double getNoise(double amplitude) {
  return amplitude * (2 * (double)rand() / RAND_MAX - 1) / 10;
}