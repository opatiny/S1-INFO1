// tells if a word is a palindrom or not

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char word[100];
  printf("Enter a word: ");
  scanf("%s", word);

  int isPalindrom = 1;
  int length = strlen(word);

  for (int i = 0; i < length / 2; i++) {
    if (word[i] != word[length - 1 - i]) {
      isPalindrom = 0;
    }
  }

  if (isPalindrom) {
    printf("The word \"%s\" is a palindrom. \n", word);
  } else {
    printf("The word \"%s\" is not a palindrom. \n", word);
  }

  return EXIT_SUCCESS;
}
