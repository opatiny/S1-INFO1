// testing string functions

#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char letter = 'A';
  printf("%c\n", letter + 32);

  char hello[100] = "hello";

  char hi[] = {
      'h', 'i',
      '\0'};  // array of chars syntax -> array lentgh is not given initially

  char name[5] = "Marc";

  printf("string hello is: %s \n", hello);  // printf format for string is %s

  stpcpy(hello, hi);  // copying strings

  printf("string hi was copied to string hello: %s \n",
         hello);  // printf format for string is %s

  strcat(hello,
         " ");  // concatenation -> adding space at the end of string hello

  strcat(hello, name);  // concatenation -> adding the name string at the end of
                        // hello string
  strcat(hello, "!");  // concatenation -> adding "!" at the end of string hello

  printf("%s \n", hello);  // printf format for string is %s

  char word[10] = "ABCDE";
  char substring[10];
  strncpy(substring, word, 3);  // allows to get substrings

  printf("%s \n", substring);

  return EXIT_SUCCESS;
}
