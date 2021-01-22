#define TEST_ENVIRONMENT

#include <string.h>

#include "../../../lib/testcases.h"
#include "../parse.h"

int test_parse_MSG1(void) {
  int NB_CASES_FAILING = 0;

  MSG1 result;

  char message[] = "1 443                                   controller";

  parse_MSG1(message, &result);

  shouldBeEqual_i(&NB_CASES_FAILING, result.type, 1);

  return checkTest(NB_CASES_FAILING);
}
