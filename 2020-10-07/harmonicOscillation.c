#define _USE_MATH_DEFINES

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  printf(
      "This script returns the value of a function with 4 parameters: "
      "A*sin(omega * t + phi).\n");

  double amplitude;
  printf("Enter the amplitude (A): \n");
  scanf("%lf", &amplitude);

  double omega;
  printf("Enter the anglular frequency in Hz (omega): \n");
  scanf("%lf", &omega);

  double time;
  printf("Enter the time in seconds (t): \n");
  scanf("%lf", &time);

  double phi;
  printf("Enter the phaseShift in degrees (phi): \n");
  scanf("%lf", &phi);   

  // converting degrees to rad
  printf("The result of the operation %lf * cos(%lf * %lf + %lf) is %lf",
         amplitude, omega, time, phi,
         amplitude * cos((omega * time + phi)) * M_PI / 180);

  printf("\n");
  return EXIT_SUCCESS;
}
