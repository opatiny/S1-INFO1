#ifndef TESTS_LIB

#define TEST_PASSING 1
#define TEST_FAILING 0

int shouldBeEqual_i(int* testState, int value, int expected);
int shouldBeEqual_d(int* testState,
                    double value,
                    double expected,
                    double maxError);

#endif  // !TESTS_LIB
