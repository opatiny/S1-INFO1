
#include "../probes.h"

int testProbeTemperature(void) {
  int result = tempProbe();
  return result == 0;
}

int testProbeLight(void) {
  int result = lightProbe();
  return result == 1;
}