#include "../../lib/testcases.h"
#include "../controllers.h"

int test_temperatureControlModel(void) {
  int NB_CASES_FAILING = 0;
  TEMPERATURE_CONTROLLER tc = {.currentValue = 0,
                               .minTemperatureThreshold = 10,
                               .maxTemperatureThreshold = 20,
                               .factor = 1};

  temperatureControlModel(15, &tc);
  shouldBeEqual_d(&NB_CASES_FAILING, tc.currentValue, 0, 0);

  temperatureControlModel(5, &tc);
  shouldBeGreaterThan_d(&NB_CASES_FAILING, tc.currentValue, 0);

  temperatureControlModel(25, &tc);
  shouldBeSmallerThan_d(&NB_CASES_FAILING, tc.currentValue, 0);

  if (NB_CASES_FAILING != 0) {
    return TEST_FAILING;
  }
}

int test_phControlModel(void) {
  PUMP pump1 = {

  };
  int result = temperatureControl(0);
  return TEST_FAILING;
}