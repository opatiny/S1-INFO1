#define _USE_MATH_DEFINES

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int sum(int* array, int size) {
  int i;
  int sum = 0;
  for (i = 0; i < size; i++) {
    sum += array[i];
  }
  return sum;
}

double average(int* array, int size) {
  int arraySum = sum(array, size);
  return arraySum / size;
}

/* main(): prints "hello world"
  PARAMETERS:
    -  void
  RETURNS:
    - STATUS (integer)
  Author: Océane Patiny - 2020.10.28
 */
double standardDeviation(int* array, int size) {
  int arraySum = sum(array, size);
  double average = arraySum / size;

  double squaresSum = 0;

  for (int i = 0; i < size; i++) {
    squaresSum += pow(array[i] - average, 2);
  }

  return sqrt(squaresSum / size);
}
