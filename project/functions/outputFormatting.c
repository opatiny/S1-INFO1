// functions to format the output of the project

#include <math.h>
#include <stdio.h>

#include "outputFormatting.h"

void printHeader(void) {
  printf(BOLDWHITE "%5s %15s %15s", "TIC", "weather temp.", "weather lum.");

  for (int i = 0; i < NB_ROOMS_OUTPUT; i++) {
    char temperatureText[15];
    sprintf(temperatureText, "room %i temp.", i + 1);
    char luminosityText[15];
    sprintf(luminosityText, "room %i lum.", i + 1);
    printf("%15s %15s", temperatureText, luminosityText);
  }

  for (int i = 0; i < NB_AQUARIUMS_OUTPUT; i++) {
    char phText[15];
    sprintf(phText, "aquarium %i PH", i + 1);
    printf("%15s", phText);
  }

  printf("\n" RESET);
}

void printDataLine(DATA* data) {
  printf("%5i %15.2lf %15.2lf", data->TIC, data->weatherTemperature,
         data->weatherLuminosity);

  for (int i = 0; i < NB_ROOMS_OUTPUT; i++) {
    printf("%15.2lf %15.2lf", data->roomsTemperature[i],
           data->roomsLuminostiy[i]);
  }
  for (int i = 0; i < NB_AQUARIUMS_OUTPUT; i++) {
    printf("%15.2lf", data->aquariumsPH[i]);
  }

  printf("\n");
}