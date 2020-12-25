#ifndef SCHEDULER_H
#define SCHEDULER_H

// STRUCTURES
typedef struct user_options {
  int weather;            // can be LAUSANNE_SUMMER or LAUSANNE_WINTER
  int showControlValues;  // 0 or 1
} USER_OPTIONS;

// PUBLIC FUNCTIONS
int Scheduler(void);

#endif
