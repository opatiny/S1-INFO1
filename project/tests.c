#include <stdio.h>
#include <stdlib.h>

#include "./functions/__tests__/controller.test.h"
#include "./functions/__tests__/weather.test.h"
#include "./functions/__tests__/probes.test.h"
int main(void) {
printf("%-40s %10s\n", "testController",
        testController() ? "\033[0;32mPASSING\033[0m"
                         : "\033[0;31mFAILING\033[0m");
printf("%-40s %10s\n", "test_updateWeatherTemperature",
        test_updateWeatherTemperature() ? "\033[0;32mPASSING\033[0m"
                         : "\033[0;31mFAILING\033[0m");
printf("%-40s %10s\n", "test_updateRoomTemperature",
        test_updateRoomTemperature() ? "\033[0;32mPASSING\033[0m"
                         : "\033[0;31mFAILING\033[0m");
printf("%-40s %10s\n", "test_updateRoomTemperature",
        test_updateRoomTemperature() ? "\033[0;32mPASSING\033[0m"
                         : "\033[0;31mFAILING\033[0m");
  return EXIT_SUCCESS;
}
