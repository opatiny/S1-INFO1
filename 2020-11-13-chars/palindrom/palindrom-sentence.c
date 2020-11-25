// tells if a word is a palindrom or not

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isAlphanumeric(char character);

int main(void) {
  char sentence[100];
  printf("Enter a sentence: ");
  scanf("%[^\n]", sentence);

  while (getchar() != '\n') {
  };

  printf("%s", sentence);

  bool isPalindrom = true;
  int length = strlen(sentence);

  char onlyChars[100] = "";
  for (int i; i < length; i) {
    if (isAlphanumeric(sentence[i])) {
      char oneCharacter[1];
      oneCharacter[0] = sentence[i];
      strcat(onlyChars, oneCharacter);
    }
  }

  printf("%s \n", onlyChars);

  printf("%s \n", onlyChars);

  for (int i = 0; i < length / 2; i++) {
    if (sentence[i] != sentence[length - 1 - i]) {
      isPalindrom = 0;
    }
  }

  if (isPalindrom) {
    printf("The sentence \"%s\" is a palindrom. \n", sentence);
  } else {
    printf("The sentence \"%s\" is not a palindrom. \n", sentence);
  }

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