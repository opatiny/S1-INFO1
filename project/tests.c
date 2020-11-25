#include "./functions/__tests__/functions.test.h"

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  printf("%-40s %10s\n", "Controller",
         testController() ? "\033[0;32mPASSING\033[0m"
                          : "\033[0;31mFAILING\033[0m");
  return EXIT_SUCCESS;
}
