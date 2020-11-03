#define _USE_MATH_DEFINES

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int harmonicOscillation(void) {
  srand(time(0));  // to do once, we "seed" the rand function

  printf(
      "This script returns the value of a function with 4 parameters: "
      "A*sin(omega * t + phi) + noise.\n");

  double amplitude;
  printf("Enter the amplitude (A): \n");
  scanf("%lf", &amplitude);

  double omega;
  printf("Enter the anglular frequency in Hz (omega): \n");
  scanf("%lf", &omega);

  double t;
  printf("Enter the time in seconds (t): \n");
  scanf("%lf", &t);

  double phi;
  printf("Enter the phase shift in degrees (phi): \n");
  scanf("%lf", &phi);

  double noise = amplitude * (2 * (double)rand() / RAND_MAX - 1) / 10;
  double result = amplitude * cos((omega * t + phi) * M_PI / 180) + noise;

  // converting degrees to rad
  printf("The result of the operation is %lf", result);

  printf("\n");
  return EXIT_SUCCESS;
}
