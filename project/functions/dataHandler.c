#define _USE_MATH_DEFINES

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "dataHandler.h"

// DEFINES
#define MSG_MAX_LENGTH 51
#define BUFFER_SIZE 50

// STRUCTURES
typedef char MSG[MSG_MAX_LENGTH];

// PROTOTYPES

// STRUCTURES INITIALIZATION

// FUNCTIONS
int dataHandler(void) {
  // defining an array of messages
  MSG buffer[BUFFER_SIZE];
  int writeIndex = 0;
  int readIndex = 0;

  return 0;
}

int write_MSG1(int controllerCode, char address[45]) {
  MSG msg1 = "1";

  return 0;
}

int read_MSG1(void) {
  return 0;
}

int convertCode(int code, char codeString[4]) {}