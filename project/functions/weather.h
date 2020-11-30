#ifndef WEATHER_H
#define WEATHER_H

double noisySinusoid(
    double offset,
    double amplitude,
    double period,
    double time,
    double phase,
    double noiseFunction(double));  // public only for testing!!

double updateWeatherLuminosity(void);
double updateWeatherTemperature(int currentTime, int index);

#endif
