// tells if a word is a palindrom or not

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isAlphanumeric(char character);

int main(void) {
  char sentence[100];
  printf("Enter a sentence: ");
  scanf("%[^\n]", sentence);

  while (getchar() != '\n') {
  };

  printf("%s", sentence);

  bool isPalindrom = true;

  char onlyChars[100] = "";

  int position = 0;
  for (int i = 0; i < strlen(sentence); i++) {
    if (isAlphanumeric(sentence[i])) {
      onlyChars[position++] = sentence[i];
    }
  }

  int length = strlen(onlyChars);
  for (int i = 0; i < length / 2; i++) {
    if (onlyChars[i] != onlyChars[length - 1 - i]) {
      isPalindrom = false;
    }
  }

  if (isPalindrom) {
    printf("The sentence \"%s\" is a palindrom. \n", sentence);
  } else {
    printf("The sentence \"%s\" is not a palindrom. \n", sentence);
  }

  return EXIT_SUCCESS;
}

bool isAlphanumeric(char character) {
  if (character >= 65 && character <= 65 + 25 ||  // uppercase
      character >= 97 && character <= 97 + 25 ||  // lowercase
      character >= 48 && character <= 48 + 9) {   // numbers
    return true;
  } else {
    return false;
  }
}