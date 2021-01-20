#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// FUNCTIONS
/* convert_to_MSG1(): converts data to MSG1 format string
  PARAMETERS:
    - message (MSG): pointer on first element of an array of chars that is a
      message
    - controllerCode (int): code of the controller
    - address (char[]): the name / address of the controller (text)
  RETURNS:
    - (int): possible error message
  Author: Océane Patiny
 */
int convert_to_MSG1(MSG message, int controllerCode, char address[]) {
  if (controllerCode > 9999) {
    return 1;  // the controller code is too large
  } else if (strlen(address) > 46) {
    return 1;  // the address string is too long
  }

  sprintf(message, "%s%4i%45s", "1", controllerCode, address);

  return 0;
}

/* convert_to_MSG2(): converts data to MSG2 format string
  PARAMETERS:
    - message (MSG): pointer on first element of an array of chars that is a
      message
    - controllerCode (int): code of the controller
    - eventCode (int): code of the event
    - eventName (char[]): the name of the event (text)
  RETURNS:
    - (int): possible error message
  Author: Océane Patiny
 */
int convert_to_MSG2(MSG message,
                    int controllerCode,
                    int eventCode,
                    char eventName[]) {
  if (controllerCode > 9999) {
    return 1;  // the controller code is too large
  } else if (eventCode > 9999) {
    return 1;  // the event code is too large
  } else if (strlen(eventName) > 21) {
    return 1;  // the address string is too long
  }

  sprintf(message, "%s%4i%4i%20s", "2", controllerCode, eventCode, eventName);

  return 0;
}

/* convert_to_MSG3(): converts data to MSG3 format string
  PARAMETERS:
    - message (MSG): pointer on first element of an array of chars that is a
      message
    - controllerCode (int): code of the controller
    - eventCode (int): code of the event
    - timestamp (u_int_64): timestamp (since beginning of simulation) of the log
    - measurement (char[]): value of the measurement in special float format
  (text)
  RETURNS:
    - (int): possible error message
  Author: Océane Patiny
 */
int convert_to_MSG2(MSG message,
                    int controllerCode,
                    int eventCode,
                    u_int64_t timestamp,
                    char measurement[]) {
  if (controllerCode > 9999) {
    return 1;  // the controller code is too large
  } else if (eventCode > 9999) {
    return 1;  // the event code is too large
  } else if (timestamp > 9999999999) {
    return 1;  // the address string is too long
  }

  sprintf(message, "%s%4i%4i%10i%10s", "3", controllerCode, eventCode,
          timestamp, measurement);

  return 0;
}

/* write_MSG1(): write a MSG1 message to the data handler
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
  incrementWriteIndex;

  return 0;
}

int read_MSG1(MSG1* message) {
  sscanf(buffer[readIndex], "%i%i%s", &(message->type),
         &(message->controllerCode), message->address);

  return 0;
}

int read_buffer_MSG(MSG message) {
  strcpy(message, buffer[readIndex]);
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