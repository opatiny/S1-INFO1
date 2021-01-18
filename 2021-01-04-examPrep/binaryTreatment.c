#define _USE_MATH_DEFINES

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int countOnes(int number);
int checkBits11111(int number);
int checkBits55(int number);
int checkBits3(int number);

int main(void) {
  printf("number of ones in 5: %i\n", countOnes(5));
  printf("check bits 8-12 are 0b11111: %i\n", checkBits11111(0b111110000000));
  printf("check bits 8-12 are 0b11111 (wrong number): %i\n",
         checkBits3(0b0100000));
  printf("check bits 8-15 are 0x55: %i\n", checkBits55(0b1101110000000));
  printf("check bits 8-15 are 0x55 (wrong number): %i\n",
         checkBits3(0b100000000));
  printf("check there is only one 1 per char: %i\n",
         checkBits3(0b100000100100));
  printf("check there is only one 1 per char (wrong number): %i\n",
         checkBits3(0b100000100111));

  return EXIT_SUCCESS;
}

int countOnes(int number) {
  int counter = 0;
  for (int i = 0; i < 32; i++) {
    if (number & 1) {
      counter++;
    }
    number = number >> 1;
  }

  return counter;
}

int checkBits11111(int number) {
  number = number >> 7;
  if (number & 0b11111 == 0b11111) {
    return 1;
  }

  return 0;
}

int checkBits55(int number) {
  number = number >> 7;
  if (number & 0x55 == 0x55) {
    return 1;
  }

  return 0;
}

int checkBits3(int number) {
  for (int i = 1; i < 8; i++) {
    int currentChar = number & 0b1111;
    if (currentChar & (currentChar - 1)) {
      return 0;
    }
    number = number >> 4;
  }

  return 1;
}