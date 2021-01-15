#define _USE_MATH_DEFINES

// exercice 3

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float findMin(float* table, int tableSize);
float findMax(float* table, int tableSize);
float average(float* table, int tableSize);
void sort(float* table, int tableSize);
void printTable(float* table, int tableSize);
float computePolynom(float value, float* table, int tableSize);

int main(void) {
  const int tableSize = 5;
  float table[] = {4.3, 43.0, 9.0, 1.0, 5.7};

  printTable(table, tableSize);

  printf("Min. value: %.2f\n", findMin(table, tableSize));
  printf("Max. value: %.2f\n", findMax(table, tableSize));
  printf("Average: %.2f\n", average(table, tableSize));

  sort(table, tableSize);
  printTable(table, tableSize);

  float table2[] = {1, 2, 3};
  float result = computePolynom(2, table2, 3);
  printf("Polynom: %.2f\n", result);

  return EXIT_SUCCESS;
}

float findMin(float* table, int tableSize) {
  float minValue = table[0];
  for (int i = 0; i < tableSize; i++) {
    if (minValue > table[i]) {
      minValue = table[i];
    }
  }

  return minValue;
}

float findMax(float* table, int tableSize) {
  float maxValue = table[0];
  for (int i = 0; i < tableSize; i++) {
    if (maxValue < table[i]) {
      maxValue = table[i];
    }
  }

  return maxValue;
}

float average(float* table, int tableSize) {
  float sum = 0;
  for (int i = 0; i < tableSize; i++) {
    sum += table[i];
  }

  return sum / tableSize;
}

void sort(float* table, int tableSize) {
  for (int i = 0; i < tableSize - 1; i++) {
    for (int j = i + 1; j < tableSize; j++) {
      if (table[i] > table[j]) {
        float temp = table[j];
        table[j] = table[i];
        table[i] = temp;
      }
    }
  }
}

void printTable(float* table, int tableSize) {
  for (int i = 0; i < tableSize; i++) {
    printf("%.2f ", table[i]);
  }
  printf("\n");
}

float computePolynom(float value, float* table, int tableSize) {
  float polynom = table[tableSize - 1];
  for (int i = 0; i < tableSize - 1; i++) {
    polynom += table[i] * pow(value, tableSize - i - 1);
  }
  return polynom;
}