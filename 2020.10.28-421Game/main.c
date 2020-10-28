#define _USE_MATH_DEFINES

// standard libraries includes
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// custom defines
#define NUMBER_DICES 3

// prototypes
int diceSimulator(void);

int main(void) {
  int continueGame = 1;
  int youWin = 0;

  int dice1 = diceSimulator();
  int dice2 = diceSimulator();
  int dice3 = diceSimulator();

  // the only combination where the XOR of all dices is 7 is when they have
  // values 4, 2 and 1!
  if (dice1 ^ dice2 ^ dice3 == 7) {
    youWin = 1;
  }

  printf("%i \n", diceSimulator());

  return EXIT_SUCCESS;
}

/* diceSimulator(): returns integer in range [1; 6]
  PARAMETERS:
    -  void
  RETURNS:
    - integer
  Author: Océane Patiny - 2020.10.28
 */
int diceSimulator(void) {
  srand(time(0));
  return rand() % 6 + 1;
}

// *(int[NUMBER_DICES])throwDices(){};
