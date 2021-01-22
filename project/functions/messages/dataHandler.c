#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "convert.h"
#include "dataHandler.h"

// DEFINES

// PROTOTYPES
int incrementReadIndex(void);
int incrementWriteIndex(void);

// STRUCTURES INITIALIZATION
// defining an array of messages
MSG buffer[BUFFER_SIZE];
int writeIndex = 0;
int readIndex = 0;

// FUNCTIONS

/* write_MSG1(): write an MSG1 message to the data handler
  PARAMETERS:
    - controllerCode (int): code of the controller
    - address (char[]): the name / address of the controller (text)
  RETURNS:
    - (int): possible error message
  Author: Océane Patiny
 */
int write_MSG1(int controllerCode, char address[]) {
  MSG msg1 = "";

  convert_to_MSG1(msg1, controllerCode, address);
  stpcpy(buffer[writeIndex], msg1);
  incrementWriteIndex();

  return 0;
}

int read_buffer_MSG(MSG message) {
  strcpy(message, buffer[readIndex]);
  stpcpy(buffer[readIndex], "");  // erasing message that was read to avoid
                                  // looping over and reading it twice
  incrementReadIndex();
  return 0;
}

int incrementReadIndex(void) {
  // handling edge effect
  if (readIndex == BUFFER_SIZE - 1) {
    readIndex = 0;
  } else {
    readIndex++;
  }

  return 0;
}

int incrementWriteIndex(void) {
  // handling edge effect
  if (readIndex == BUFFER_SIZE - 1) {
    readIndex = 0;
  } else {
    readIndex++;
  }

  return 0;
}