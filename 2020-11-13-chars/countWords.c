#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isAlphanumeric(char character);

int main(void) {
  char text[300] = "Bluetooth is Always; a Few... Years-Away 2020";  // 8 words
  int counter;
  char previousChar = ' ';
  for (int i = 0; i < strlen(text); i++) {
    if (!(isAlphanumeric(text[i])) && isAlphanumeric(previousChar) ||
        (i == strlen(text) - 1 && isAlphanumeric(text[i]))) {
      counter++;
    }
    previousChar = text[i];
  }

  printf("The text contains %i words. \n", counter);
  return EXIT_SUCCESS;
}

int isAlphanumeric(char character) {
  if (character >= 65 && character <= 65 + 25 ||  // uppercase
      character >= 97 && character <= 97 + 25 ||  // lowercase
      character >= 48 && character <= 48 + 10) {  // numbers
    return 1;
  } else {
    return 0;
  }
}