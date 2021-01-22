#define TEST_ENVIRONMENT

#include <string.h>

#include "../../../lib/testcases.h"
#include "../parse.h"

int test_parse_MSG1(void) {
  int NB_CASES_FAILING = 0;

  MSG1 result;

  char message[] = "1 443              a controller address street 4.5";

  parse_MSG1(message, &result);

  shouldBeEqual_i(&NB_CASES_FAILING, result.type, 1);
  shouldBeEqual_i(&NB_CASES_FAILING, result.controllerCode, 443);
  shouldBeEqual_s(&NB_CASES_FAILING, result.address,
                  "a controller address street 4.5");

  return checkTest(NB_CASES_FAILING);
}

int test_parse_MSG2(void) {
  int NB_CASES_FAILING = 0;

  MSG2 result;

  char message[] = "232445567    room temperature";

  parse_MSG2(message, &result);

  shouldBeEqual_i(&NB_CASES_FAILING, result.type, 2);
  shouldBeEqual_i(&NB_CASES_FAILING, result.controllerCode, 3244);
  shouldBeEqual_i(&NB_CASES_FAILING, result.eventCode, 5567);
  shouldBeEqual_s(&NB_CASES_FAILING, result.eventName, "room temperature");

  return checkTest(NB_CASES_FAILING);
}
