// testing string functions

#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  // double to string
  double Double1 = 23235.6;
  char s1[11];
  sprintf(s1, "%5.3f", Double1);
  printf("valeur du string: %s\n", s1);

  // string to double
  char s2[] = "12345.56";
  double Double2;
  sscanf(s2, "%lf", &Double2);
  printf("valeur du double: %lf\n", Double2);
  return EXIT_SUCCESS;
}
