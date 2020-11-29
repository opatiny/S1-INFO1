
#include "../probes.h"

int test_updateRoomTemperature(void) {
  double result = updateRoomTemperature(1);
  return result == 0;
}

int test_updateRoomLuminosity(void) {
  int result = updateRoomLuminosity();
  return result == 1;
}