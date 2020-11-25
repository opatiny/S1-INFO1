#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char text[300] = "hello  a b c - / d";
  int counter[26] = {0};
  for (int i = 0; i < strlen(text); i++) {
    if (text[i] >= 'A' && text[i] <= 'Z') {  // uppercase
      counter[text[i] - 'A']++;
    } else if (text[i] >= 'a' && text[i] <= 'z') {  // lowercase
      counter[text[i] - 'a']++;
    }
  }
  printf("%s %12s \n", "Letter", "Occurences");

  for (int i = 0; i < 26; i++) {
    printf("%c %c %12i \n", 'a' + i, 'A' + i, counter[i]);
  }
  return EXIT_SUCCESS;
}
