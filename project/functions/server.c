#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>

#include "messages/dataHandler.h"

// PROTOTYPES

// STRUCTURES INITIALIZATION

// FUNCTIONS

/* server(): update PH of given aquarium
  PARAMETERS:
    -
  RETURNS:
    - (int): possible error message
  Author: Océane Patiny
 */
int server(void) {
  return 0;
}

int initializeServer(void) {
  int result = remove("./msg1.txt");
  printf("File should be removed: %i\n", result);
  // remove("msg2.txt");
  // remove("msg3.txt");
  return 0;
}

int readAndStoreAllMsg(void) {
  for (int i = 0; i < BUFFER_SIZE; i++) {
    char msg_s[MSG_MAX_LENGTH];
    while (1) {
      read_buffer_MSG(msg_s);
      if (sizeof(msg_s) == 0) {
        break;
      }
      char msgType = msg_s[0];

      MSG1 msg;

      switch (msgType) {
        case 1:
          parse_MSG1(msg_s, &msg);
          // fptr = fopen("C:\\program.txt", "w");
          break;

        default:
          break;
      }
    };
  }
  return 0;
}
