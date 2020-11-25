// tells if a word is a palindrom or not

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char buffer[100];
  printf("Enter a text: ");
  // scan all characters until \n is encountered => the /n remains in the
  // buffer!
  scanf("%[^\n]", buffer);

  printf("%s \n", buffer);

  char oldChar;
  printf("Enter the character you want to replace: ");
  scanf(" %c",
        &oldChar);  // the space before the %c is super important!!! it removes
                    // the newline character that remains in the buffer!
                    // Warning: a space as a character will also be ignored

  // another hack to clear newlines in buffer:
  // while ((getchar()) != '\n') {};

  char newChar;
  printf("Enter the new character: ");
  scanf(" %c", &newChar);

  int length = strlen(buffer);

  for (int i = 0; i < length; i++) {
    if (buffer[i] == oldChar) {
      buffer[i] = newChar;
    }
  }

  printf("Your text is: %s \n", buffer);

  return EXIT_SUCCESS;
}
