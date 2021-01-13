#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dataHandler.h"

// DEFINES

// PROTOTYPES

// STRUCTURES INITIALIZATION
// defining an array of messages
MSG buffer[BUFFER_SIZE];
int writeIndex = 0;
int readIndex = 0;

// FUNCTIONS

int convert_to_MSG1(MSG message, int controllerCode, char address[45]) {
  if (controllerCode > 9999) {
    return 1;
  } else if (sizeof(address) > 46) {
    return 1;
  }

  sprintf(message, "%s%4i%45s", "1", controllerCode, address);

  return 0;
}

int write_MSG1(int controllerCode, char address[45]) {
  MSG msg1 = "";

  convert_to_MSG1(msg1, controllerCode, address);
  stpcpy(buffer[writeIndex], msg1);
  writeIndex++;

  return 0;
}

int read_MSG1(MSG1* message) {
  return 0;
}

int convertCode(int code, char codeString[4]) {}