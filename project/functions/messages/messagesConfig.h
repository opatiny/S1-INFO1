#ifndef MSG_CONFIG_H
#define MSG_CONFIG_H

#include <stdio.h>
#include <stdlib.h>

// DEFINES
#define MSG_MAX_LENGTH 51
#define BUFFER_SIZE 50
#define CODE_MAX_VALUE 9999
#define MAX_ADDRESS_LENGTH 46
#define MAX_PHENOMENOM_NAME_LENGTH 21
#define MAX_TIMESTAMP_VALUE 999999999
#define MAX_MEASUREMENT_ABS_VALUE 99999.999

// STRUCTURES
typedef char MSG[MSG_MAX_LENGTH];

typedef struct msg1 {
  int type;
  int controllerCode;
  char address[MAX_ADDRESS_LENGTH];
} MSG1;

typedef struct msg2 {
  int type;
  int controllerCode;
  int phenomenomCode;
  char phenomenomName[MAX_PHENOMENOM_NAME_LENGTH];
} MSG2;

typedef struct msg3 {
  int type;
  int controllerCode;
  int phenomenomCode;
  u_int64_t timestamp;
  float measurement;
} MSG3;

#endif  // MSG_CONFIG_H
