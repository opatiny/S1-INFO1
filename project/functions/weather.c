#define _USE_MATH_DEFINES

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "weather.h"

// data for Lausanne
WEATHER weathers[2] = {
    {
        .temperature = {.offset = 23, .amplitude = 5, .phase = -150},  // summer
        .luminosity =
            {.max = 100000,  // bright sunlight
             .min = 0.25,
             .slopeIncreasing = (100000 - 0.25) / (5 * 360 - 4 * 3600),
             .slopeDecreasing = (0.25 - 100000) / (23 * 360 - 21.5 * 3600),
             .intervals = {4 * 3600, 5 * 3600, 21.5 * 3600, 23 * 3600}},
    },
    {.temperature = {.offset = 5, .amplitude = 5, .phase = -150},  // winter
     .luminosity = {.max = 20000,
                    .min = 0.25,
                    .slopeIncreasing = (20000 - 0.25) / (8.25 * 360 - 7 * 3600),
                    .slopeDecreasing =
                        (20000 - 0.25) / (18 * 360 - 16.8 * 3600),
                    .intervals = {7 * 3600, 8.25 * 3600, 16.8 * 3600,
                                  18 * 3600}}}

};

// PROTOTYPES
int luminosityModel(u_int32_t currentTimeOfDay, LUMINOSITY* luminosity);
int setTwilightLuminosity(u_int32_t currentTimeOfDay,
                          LUMINOSITY* luminosity,
                          char dayPhase);
int setSlopes(WEATHER* weathers, int weathersSize);  // actually not used!
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
int updateWeatherLuminosity(u_int32_t currentTimeOfDay, int index) {
  luminosityModel(currentTimeOfDay, &(weathers[index].luminosity));
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
int updateWeatherTemperature(u_int32_t currentTimeOfDay, int index) {
  double offset = weathers[index].temperature.offset;
  double amplitude = weathers[index].temperature.amplitude;
  double period = 60 * 60 * 24;  // number of seconds in one day
  double time = (double)currentTimeOfDay;
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

int luminosityModel(u_int32_t currentTimeOfDay, LUMINOSITY* luminosity) {
  if (currentTimeOfDay < luminosity->intervals[0]) {
    luminosity->current = luminosity->min;
  } else if (luminosity->intervals[0] <= currentTimeOfDay &&
             currentTimeOfDay < luminosity->intervals[1]) {
    setTwilightLuminosity(currentTimeOfDay, luminosity, 'r');
  } else if (luminosity->intervals[1] <= currentTimeOfDay &&
             currentTimeOfDay < luminosity->intervals[2]) {
    luminosity->current = luminosity->max;
  } else if (luminosity->intervals[2] <= currentTimeOfDay &&
             currentTimeOfDay < luminosity->intervals[3]) {
    setTwilightLuminosity(currentTimeOfDay, luminosity, 's');
  } else if (luminosity->intervals[3] <= currentTimeOfDay) {
    luminosity->current = luminosity->min;
  }
  return 0;
}

int setTwilightLuminosity(u_int32_t currentTimeOfDay,
                          LUMINOSITY* luminosity,
                          char dayPhase) {
  int index = 0;
  double offset = 0;
  double slope = 0;
  switch (dayPhase) {
    case 'r':  // for sunRise
      index = 0;
      offset = luminosity->min;
      slope = luminosity->slopeIncreasing;
      // verifying that curren time of day is in correct interval
      if (!(currentTimeOfDay > luminosity->intervals[0] &&
            currentTimeOfDay < luminosity->intervals[1])) {
        printf(
            "ERROR (setTwilightLuminosity): currentTimeOfDay is out of range");
        return 1;
      }
      break;
    case 's':  // for sunSet
      index = 2;
      offset = luminosity->max;
      slope = luminosity->slopeDecreasing;
      // verifying that current time of day is in correct interval
      if (!(currentTimeOfDay > luminosity->intervals[2] &&
            currentTimeOfDay < luminosity->intervals[3])) {
        printf(
            "ERROR (setTwilightLuminosity): currentTimeOfDay is out of range");
        return 1;
      }
      break;
    default:
      printf("ERROR (setTwilightLuminosity): dayPhase option '%c' unrecognised",
             dayPhase);
      return 1;
  }

  double time = currentTimeOfDay -
                luminosity->intervals[index];  // this is a kind of relative
                                               // time for the line() function

  luminosity->current = line(time, slope, offset);

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

int setSlopes(WEATHER* weathers, int weathersSize) {
  for (int i = 0; i < weathersSize; i++) {
    weathers[i].luminosity.slopeIncreasing =
        (weathers[i].luminosity.max - weathers[i].luminosity.min) /
        (weathers[i].luminosity.intervals[1] -
         weathers[i].luminosity.intervals[0]);
    weathers[i].luminosity.slopeDecreasing =
        (weathers[i].luminosity.max - weathers[i].luminosity.min) /
        (weathers[i].luminosity.intervals[3] -
         weathers[i].luminosity.intervals[2]);
  }
  return 0;
}