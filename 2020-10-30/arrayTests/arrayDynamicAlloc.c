#define _USE_MATH_DEFINES

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  // this is a dynamic allocation of memory -> the memory is allocated AFTER the
  // code is compiled. This works here, because the compiler must use C99
  // version of C, which allows it. HOWEVER, it will not work with all C
  // compilers!
  int size;

  printf("Enter table size: ");
  scanf("%i", &size);
  int table[size];

  return EXIT_SUCCESS;
}
