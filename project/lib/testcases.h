#ifndef TESTS_LIB

#define TEST_PASSING 0
#define TEST_FAILING 1

int shouldBeEqual_i(int* testState, int value, int expected);
int shouldBeEqual_d(int* testState,
                    double value,
                    double expected,
                    double maxError);

#endif  // !TESTS_LIB
