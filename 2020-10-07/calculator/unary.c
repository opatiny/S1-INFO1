// using array of function
// pointers:https://stackoverflow.com/questions/252748/how-can-i-use-an-array-of-function-pointers

#define _USE_MATH_DEFINES

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void exponential(double number) {
  printf("exp(%lf) = %lf", number, exp(number));
}
void naturalLog(double number) {
  printf("ln(%lf) = %lf", number, log(number));
}
void logBase2(double number) {
  printf("log2(%lf) = %lf", number, log2(number));
}
void logBase10(double number) {
  printf("log10(%lf) = %lf", number, log10(number));
}
void squareRoot(double number) {
  printf("sqrt(%lf) = %lf", number, sqrt(number));
}
void sine(double number) {
  printf("sin(%lf) = %lf", number, sin(number));
}
void cosine(double number) {
  printf("cos(%lf) = %lf", number, cos(number));
}
void tangent(double number) {
  printf("tan(%lf) = %lf", number, tan(number));
}
void arccosine(double number) {
  printf("acos(%lf) = %lf", number, acos(number));
}
void arcsine(double number) {
  printf("asin(%lf) = %lf", number, asin(number));
}
void arctangent(double number) {
  printf("atan(%lf) = %lf", number, atan(number));
}

int main(void) {
  // array of functions pointers
  void (*functions[11])(double number) = {
      exponential, naturalLog, logBase2, logBase10, squareRoot, arccosine,
      arcsine,     arctangent, sine,     cosine,    tangent};

  int function;
  printf(
      "Enter number of desired function: 1) exp, 2) ln,  3) log2, 4) log10, 5) "
      "sqrt,  6) asin, 7) acos, 8) atan, 9) sin, 10) cos, 11) tan\n");
  scanf("%i", &function);

  double number;
  printf("Enter desired number: ");
  scanf("%lf", &number);

  if (function > 8) {
    number = number * M_PI / 180;
  }

  // executing correct function from array, with index function-1
  (*functions[function - 1])(number);
  printf("\n");

  return EXIT_SUCCESS;
}
