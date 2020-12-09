#include "../../lib/testcases.h"
#include "../controllers.h"

int test_temperatureControl(void) {
  int result = temperatureControl();
  return TEST_FAILING;
}
