#ifndef WEATHER_H
#define WEATHER_H

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
  double slopeIncreasing;  // slope of the second segment
  double slopeDecreasing;  // slope of the fourth segment
  double intervals[4];     // intervals for each segment in seconds
} LUMINOSITY;

typedef struct weather {
  TEMPERATURE temperature;
  LUMINOSITY luminosity;  // in cd
} WEATHER;

// PUBLIC FUNCTIONS
int updateWeatherLuminosity(u_int32_t currentTimeOfDay, int index);
int updateWeatherTemperature(u_int32_t currentTimeOfDay, int index);

double getWeatherLuminosity(int index);
double getWeatherTemperature(int index);

// PUBLIC ONLY FOR TESTING
int luminosityModel(u_int32_t currentTimeOfDay, LUMINOSITY* luminosity);
int setTwilightLuminosity(u_int32_t currentTimeOfDay,
                          LUMINOSITY* luminosity,
                          char dayPhase);
double line(double x, double slope, double offset);
double noisySinusoid(double offset,
                     double amplitude,
                     double period,
                     double time,
                     double phase,
                     double noiseFunction(double));

#endif
