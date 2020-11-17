#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char letter = 'A';
  printf("%c\n", letter + 32);

  char hello[6] = "hello";

  char hi[] = {
      'h', 'i',
      '\0'};  // array of chars syntax -> array lentgh is not given initially

  printf("string hello is: %s \n", hello);  // printf format for string is %s

  stpcpy(hello, hi);  // copying strings

  printf("string hi was copied to string hello: %s \n",
         hello);  // printf format for string is %s

  return EXIT_SUCCESS;
}
