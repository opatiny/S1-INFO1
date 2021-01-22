#define TEST_ENVIRONMENT

#include <string.h>

#include "../../../lib/testcases.h"
#include "../convert.h"

int test_convert_to_MSG1(void) {
  MSG message;

  convert_to_MSG1(message, 443, "controller");

  char expected[] = "1 443                                   controller";

  if (strcmp(message, expected)) {
    printf("%10s%50s\n", "expected:", expected);
    printf("%10s%50s\n", "got:", message);

    return 1;
  }
  return 0;
}

int test_convert_to_MSG2(void) {
  MSG message;

  convert_to_MSG2(message, 443, 512, "temperature");

  char expected[] = "2 443 512         temperature";

  if (strcmp(message, expected)) {
    printf("%10s%50s\n", "expected:", expected);
    printf("%10s%50s\n", "got:", message);

    return 1;
  }
  return 0;
}

int test_convert_to_MSG3(void) {
  MSG message;

  convert_to_MSG3(message, 543, 2, 12345, -5.7);

  char expected[] = "3 543   2     12345    -5.700";

  if (strcmp(message, expected)) {
    printf("%10s%50s\n", "expected:", expected);
    printf("%10s%50s\n", "got:", message);

    return 1;
  }
  return 0;
}
