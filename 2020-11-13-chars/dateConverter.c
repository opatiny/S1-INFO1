// convert american dates (month/day/year) to swiss dates (day.month.year)

#define _USE_MATH_DEFINES

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char dateUS[15];
  char dateCH[15];
  printf("Enter date in US format: ");
  scanf("%s", dateUS);

  int day = 0;
  int month = 0;
  int year = 0;
  sscanf(dateUS, "%i/%i/%i", &month, &day, &year);

  sprintf(dateCH, "%i.%i.%i", day, month, year);

  printf("Date in CH format: %s \n", dateCH);

  return EXIT_SUCCESS;
}
