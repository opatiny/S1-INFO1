// functions to format the output of the project

#include <math.h>
#include <stdio.h>

#include "outputFormatting.h"

void printHeader(DATA* data) {
  printf(BOLDWHITE "%5s %15s %15s", "TIC", "weather temp.", "weather lum.");

  for (int i = 0; i < NB_ROOMS_OUTPUT; i++) {
    char temperatureText[15];
    sprintf(temperatureText, "room %i temp.", i + 1);
    printf("%15s", temperatureText);
    if (data->showControlValues) {
      char tempControlText[20];
      sprintf(tempControlText, "temp. control %i", i + 1);
      printf("%17s", tempControlText);
    }
    char luminosityText[15];
    sprintf(luminosityText, "room %i lum.", i + 1);
    printf("%15s", luminosityText);
  }

  for (int i = 0; i < NB_AQUARIUMS_OUTPUT; i++) {
    char phText[15];
    sprintf(phText, "aquarium %i PH", i + 1);
    printf("%15s", phText);

    if (data->showControlValues) {
      char phControlText[15];
      sprintf(phControlText, "PH control %i", i + 1);
      printf("%15s", phControlText);
    }
  }

  printf("\n" RESET);
}

void printDataLine(DATA* data) {
  printf("%5i %15.2lf %15.2lf", data->TIC, data->weatherTemperature,
         data->weatherLuminosity);

  for (int i = 0; i < NB_ROOMS_OUTPUT; i++) {
    printf("%15.2lf", data->roomsTemperature[i]);
    if (data->showControlValues) {
      printf("%17.2lf", data->temperatureControllers[i]);
    }
    printf("%15.2lf", data->roomsLuminostiy[i]);
  }
  for (int i = 0; i < NB_AQUARIUMS_OUTPUT; i++) {
    printf("%15.2lf", data->aquariumsPH[i]);
    if (data->showControlValues) {
      printf("%15.2lf", data->phControllers[i]);
    }
  }

  printf("\n");
}