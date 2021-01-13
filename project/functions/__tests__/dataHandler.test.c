#define TEST_ENVIRONMENT

#include <string.h>

#include "../../lib/testcases.h"
#include "../dataHandler.h"

int test_convert_to_MSG1(void) {
  MSG message;

  convert_to_MSG1(message, 443, "controller");

  if (!strcmp(message, "1 443                                   controller")) {
    return 1;
  }
  return 0;
}
