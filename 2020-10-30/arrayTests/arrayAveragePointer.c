#define _USE_MATH_DEFINES

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int average(int* table, int size);

int main(void) {
  int values[SIZE] = {1, 2, 3, 4, 5};

  printf("The average of the elements of the array is: %i \n",
         average(values, SIZE));
  return EXIT_SUCCESS;
}

int average(int* table, int size) {
  int i;
  int sum = 0;
  for (i = 0; i < size; i++) {
    sum += table[i];
  }
  return sum / size;
}