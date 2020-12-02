#define _USE_MATH_DEFINES

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "weather.h"

// PROTOTYPES
double line(double x, double slope, double offset);
double randomTenPercentNoise(double amplitude);
double noisySinusoid(double offset,
                     double amplitude,
                     double period,
                     double time,
                     double phase,
                     double noiseFunction(double));

// STRUCTURES
typedef struct temperature {
  double current;    // in °C
  double offset;     // in °C
  double amplitude;  // in °C
  double phase;      // in degrees

} TEMPERATURE;

typedef struct luminosity {
  double current;  // in lux
  double max;      // in lux (typically 20000 lux at midday with clear sky)
  double min;      // in lux (typically <0 lux at night)
  double slopeIncreasing;  // no unit
  double slopeDecreasing;  // no unit
  double intervals[4];     // intervals for each segment in seconds
} LUMINOSITY;

typedef struct weather {
  TEMPERATURE temperature;
  LUMINOSITY luminosity;  // in cd
} WEATHER;

WEATHER weathers[2] = {
    {
        .temperature = {.offset = 23, .amplitude = 5, .phase = -150},  // summer
        .luminosity = {.max = 100000,  // bright sunlight
                       .min = 0.25,
                       .slopeIncreasing = 0.3,
                       .slopeDecreasing = 0.5,
                       .intervals = {4 * 3600, 5 * 3600, 21.5 * 3600,
                                     23 * 3600}},
    },
    {.temperature = {.offset = 5, .amplitude = 5, .phase = -150},  // winter
     .luminosity = {.max = 20000,
                    .min = 0.25,
                    .slopeIncreasing = 0.3,
                    .slopeDecreasing = 0.5,
                    .intervals = {7 * 3600, 8.25 * 3600, 16.8 * 3600,
                                  18 * 3600}}}

};

// PUBLIC FUNCTIONS

double updateWeatherLuminosity(int currentTime, int index) {
  if (currentTime < weathers[index].luminosity.intervals[0]) {
    weathers[index].luminosity.current = weathers[index].luminosity.min;
  } else if (weathers[index].luminosity.intervals[0] <= currentTime <
             weathers[index].luminosity.intervals[1]) {
  } else if (weathers[index].luminosity.intervals[1] <= currentTime <
             weathers[index].luminosity.intervals[2]) {
    weathers[index].luminosity.current = weathers[index].luminosity.max;

  } else if (weathers[index].luminosity.intervals[2] <= currentTime <
             weathers[index].luminosity.intervals[3]) {
  }
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
  double offset = weathers[index].temperature.offset;
  double amplitude = weathers[index].temperature.amplitude;
  double period = 60 * 60 * 24;  // number of seconds in one day
  double time = currentTime;
  double phase = weathers[index].temperature.phase;

  weathers[index].temperature.current = noisySinusoid(
      offset, amplitude, period, time, phase, &randomTenPercentNoise);

  return weathers[index].temperature.current;
}

// PRIVATE FUNCTIONS
int setTwilightLuminosity(double currentTime,
                          LUMINOSITY* luminosity,
                          char dayPhase) {
  int index = 0;
  int offset = 0;
  switch (dayPhase) {
    case 'r':  // for sunRise
      index = 0;
      offset = luminosity->min;
      break;
    case 's':  // for sunSet
      index = 2;
      offset = luminosity->max;
      break;
    default:
      return 1;
  }

  double slope =
      luminosity->max - luminosity->min / (luminosity->intervals[index + 1] -
                                           luminosity->intervals[index]);

  luminosity->current = line(currentTime, slope, offset);

  return 0;
}

/* line(): evaluates an affine function at a given point
  PARAMETERS:
    -  x (double): point at which to evaluate the function
    -  slope (double): slope of the line
    -  offset (double): y offset of the line
  RETURNS:
    - (double)
  Author: Océane Patiny
 */
double line(double x, double slope, double offset) {
  return slope * x + offset;
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