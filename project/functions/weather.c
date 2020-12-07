#define _USE_MATH_DEFINES

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "weather.h"

// data for Lausanne
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

// PROTOTYPES
int luminosityModel(double currentTime, LUMINOSITY* luminosity);
int setTwilightLuminosity(double currentTime,
                          LUMINOSITY* luminosity,
                          char dayPhase);
double line(double x, double slope, double offset);
double randomTenPercentNoise(double amplitude);
double noisySinusoid(double offset,
                     double amplitude,
                     double period,
                     double time,
                     double phase,
                     double noiseFunction(double));

// PUBLIC FUNCTIONS

/* updateWeatherLuminosity(): updates current weather luminosity

  PARAMETERS:
    -  currentTime (int): current time in [s]
    -  index (int): index of the weather struct to modify in "weathers"

  RETURNS:
    - (int): possible error message

  Author: Océane Patiny
 */
int updateWeatherLuminosity(int currentTime, int index) {
  luminosityModel(currentTime, &(weathers[index].luminosity));
  return 0;
}

/* updateWeatherTemperature(): updates current weather temperature

  PARAMETERS:
    -  currentTime (int): current time in [s]
    -  index (int): index of the weather struct to modify in "weathers"

  RETURNS:
    - (int): possible error message

  Author: Océane Patiny
 */
int updateWeatherTemperature(int currentTime, int index) {
  double offset = weathers[index].temperature.offset;
  double amplitude = weathers[index].temperature.amplitude;
  double period = 60 * 60 * 24;  // number of seconds in one day
  double time = currentTime;
  double phase = weathers[index].temperature.phase;

  weathers[index].temperature.current = noisySinusoid(
      offset, amplitude, period, time, phase, &randomTenPercentNoise);

  return 0;
}

double getWeatherLuminosity(int index) {
  return weathers[index].luminosity.current;
}

double getWeatherTemperature(int index) {
  return weathers[index].temperature.current;
}

// PRIVATE FUNCTIONS

int luminosityModel(double currentTime, LUMINOSITY* luminosity) {
  if (currentTime < luminosity->intervals[0]) {
    luminosity->current = luminosity->min;
  } else if (luminosity->intervals[0] <= currentTime &&
             currentTime < luminosity->intervals[1]) {
    setTwilightLuminosity(currentTime, luminosity, 'r');
  } else if (luminosity->intervals[1] <= currentTime &&
             currentTime < luminosity->intervals[2]) {
    luminosity->current = luminosity->max;
  } else if (luminosity->intervals[2] <= currentTime &&
             currentTime < luminosity->intervals[3]) {
    setTwilightLuminosity(currentTime, luminosity, 's');
  } else if (luminosity->intervals[3] <= currentTime) {
    luminosity->current = luminosity->min;
  }
  return 0;
}

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