#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parse.h"

// DEFINES

// PROTOTYPES

// STRUCTURES INITIALIZATION

// FUNCTIONS

int parse_MSG1(MSG stringMessage, MSG1* parsedMessage) {
  sscanf(stringMessage, "%i%i%s", &(parsedMessage->type),
         &(parsedMessage->controllerCode), parsedMessage->address);

  return 0;
}

int parse_MSG2(MSG stringMessage, MSG2* parsedMessage) {
  sscanf(stringMessage, "%i%i%i%s", &(parsedMessage->type),
         &(parsedMessage->controllerCode), &(parsedMessage->eventCode),
         parsedMessage->eventName);

  return 0;
}

int parse_MSG3(MSG stringMessage, MSG3* parsedMessage) {
  sscanf(stringMessage, "%i%i%i%lu%f", &(parsedMessage->type),
         &(parsedMessage->controllerCode), &(parsedMessage->eventCode),
         &(parsedMessage->timestamp), &(parsedMessage->measurement));

  return 0;
}