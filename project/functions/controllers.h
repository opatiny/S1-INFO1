#ifndef CONTROLLERS_H
#define CONTROLLERS_H

// STRUCTURES
typedef struct pump {
  double currentValue;  // in ??
  double phThreshold;   // from 0 to 1
  double factor;        // no dimension
} PUMP;

// PUBLIC FUNCTIONS
int temperatureControl(void);
int phControl(int index);

#endif
