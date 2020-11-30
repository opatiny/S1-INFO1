#define _USE_MATH_DEFINES

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// PROTOTYPES
double randomTenPercentNoise(double amplitude);
double noisySinusoid(double offset,
                     double amplitude,
                     double period,
                     double time,
                     double phase,
                     double noiseFunction(double));

// STRUCTURES
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

double updateWeatherLuminosity(void) {
  // printf("external luminosity\n");
  return 0;
}

/* updateWeatherTemperature(): updates weather temperature

  PARAMETERS:
    -  currentTime (int): current time in [s]
    -  index (int): index of the temperature struct to modify in "temperatures"

  RETURNS:
    - (double): new weather temperature

  Author: Océane Patiny
 */
double updateWeatherTemperature(int currentTime, int index) {
  double offset = temperatures[index].offset;
  double amplitude = temperatures[index].amplitude;
  double period = 60 * 60 * 24;  // number of seconds in one day
  double time = currentTime;
  double phase = temperatures[index].phase;

  temperatures[index].currentTemperature = noisySinusoid(
      offset, amplitude, period, time, phase, &randomTenPercentNoise);

  return temperatures[index].currentTemperature;
}

/* noisySinusoid(): returns the value of a noisy sinusoidal signal at a given
  time

  PARAMETERS:
    -  offset (double): constant value added to the sinusoid
    -  amplitude (double): amplitude of the signal
    -  period (double): period of the sinusoid in [s]
    -  time (double): time in [s]
        -  phase (double): phase in [°]
    -  controllerImpact (*)(double): pointer on function that generates noise
  based on amplitude

  RETURNS:
    - (double)

  Author: Océane Patiny
 */
double noisySinusoid(double offset,
                     double amplitude,
                     double period,
                     double time,
                     double phase,
                     double noiseFunction(double)) {
  double omega = 2 * M_PI / period;
  double noise = noiseFunction(amplitude);
  double result =
      offset + amplitude * sin(omega * time + phase * M_PI / 180) + noise;
  return result;
}

// returns random value between 0 and 10% of amplitude
double randomTenPercentNoise(double amplitude) {
  return amplitude * (2 * (double)rand() / RAND_MAX - 1) / 10;
}