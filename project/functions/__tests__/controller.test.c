
#include "../controllers.h"

int testController(void) {
    int result = temperatureControl();
    return result == 0;
}
