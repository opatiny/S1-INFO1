#include "../../lib/testcases.h"
#include "../controllers.h"

int test_temperatureControl(void) {
  int result = temperatureControl(0);
  return TEST_FAILING;
}
