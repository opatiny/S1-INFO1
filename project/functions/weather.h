#ifndef WEATHER_H
#define WEATHER_H

double noisySinusoid(
    double offset,
    double amplitude,
    double period,
    double time,
    double phase,
    double noiseFunction(double));  // public only for testing!!

int updateWeatherLuminosity(int currentTime, int index);
int updateWeatherTemperature(int currentTime, int index);

double getWeatherLuminosity(int index);
double getWeatherTemperature(int index);

#endif
