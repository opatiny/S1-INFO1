#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char text[300] = "hello  a b c - / d";
  int counter;
  for (int i = 0; i < strlen(text); i++) {
    if (text[i] >= 65 && text[i] <= 65 + 25 ||  // uppercase
        text[i] >= 97 && text[i] <= 97 + 25) {  // lowercase
      counter++;
    }
  }

  printf("The text contains %i letters. \n", counter);
  return EXIT_SUCCESS;
}
