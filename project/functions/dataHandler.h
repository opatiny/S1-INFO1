#ifndef DATA_HANDLER_H
#define DATA_HANDLER_H

// STRUCTURES
typedef struct msg1 {
  int type;
  int controllerCode;
  char address[45];
} MSG1;

typedef struct msg2 {
  int type;
  int controllerCode;
  int phenomenomCode;
  char phenomenomName[20];
} MSG2;

typedef struct msg3 {
  int type;
  int controllerCode;
  int phenomenomCode;
  u_int64_t timestamp;
  float measurement;
} MSG3;

// PUBLIC FUNCTIONS
int dataHandler(void);

#endif
