#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>

#include "messages/dataHandler.h"

// GLOBAL VARIABLES
FILE* msg1_log_file;
FILE* msg2_log_file;
FILE* msg3_log_file;

// FUNCTIONS

/* server(): update PH of given aquarium
  PARAMETERS:
    -
  RETURNS:
    - (int): possible error message
  Author: Océane Patiny
 */
int initServer(void) {
  msg1_log_file = fopen("./logs/msg1.txt", "w");
  msg2_log_file = fopen("./logs/msg2.txt", "w");
  msg3_log_file = fopen("./logs/msg3.txt", "w");
  return 0;
}

int closeServer(void) {
  fclose(msg1_log_file);
  fclose(msg2_log_file);
  fclose(msg3_log_file);
  return 0;
}

int server(void) {
  printf("Inside server!\n");

  char msg_s[MSG_MAX_LENGTH] = {
      'a'};  // we have to fill the array with something

  while (msg_s[0] != '\0') {
    read_buffer_MSG(msg_s);

    printf("Message: %s, %c\n", msg_s, msg_s[0]);

    if (msg_s[0] == '\0') {
      break;
    }

    char msgType = msg_s[0];

    MSG1 msg1;
    MSG2 msg2;
    MSG3 msg3;

    switch (msgType) {
      case '1':
        parse_MSG1(msg_s, &msg1);
        fprintf(msg1_log_file, "%1i, %4i, %45s\n", msg1.type,
                msg1.controllerCode, msg1.address);
        break;
      case '2':
        parse_MSG2(msg_s, &msg2);
        fprintf(msg2_log_file, "%1i, %4i, %4i, %20s\n", msg2.type,
                msg2.controllerCode, msg2.eventCode, msg2.eventName);
        break;
      case '3':
        parse_MSG3(msg_s, &msg3);
        fprintf(msg3_log_file, "%1i, %4i, %10lu, %10.3lf\n", msg3.type,
                msg3.controllerCode, msg3.timestamp, msg3.measurement);
        break;
      default:
        break;
    };
  }
  return 0;
}
