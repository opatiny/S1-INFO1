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

  printf(
      "Welcome to the 421 game! Enter 2 to see the rules and then start a new "
      "game, enter 1 to start a new game.\n");
  scanf("%i", &continueGame);

  if (continueGame == 2) {
    printf(
        "Rules:\n "
        "- In the first turn, you will throw three dices\n "
        "- The goal is to get the values 4, 2 and 1\n "
        "- If the values are not right the first time, the dices that are not "
        "correct are thrown again\n"
        "- You can repeat this until you get the right combination \n \n ");
    continueGame = 1;
  }

  int dice1 = diceSimulator();
  int dice2 = diceSimulator();
  int dice3 = diceSimulator();

  while (continueGame) {
    // the only combination where the XOR of all dices is 7 is when they have
    // values 4, 2 and 1!
    if (dice1 ^ dice2 ^ dice3 == 7) {
      youWin = 1;
    } else {
      if (dice1 != 1 && dice1 != 2 && dice1 != 3) {
        dice1 = diceSimulator();
      }
      if (dice2 != 1 && dice2 != 2 && dice2 != 3 || dice2 == dice1) {
        dice2 = diceSimulator();
      }
      if (dice3 != 1 && dice3 != 2 && dice3 != 3 || dice3 == dice1 ||
          dice3 == dice2) {
        dice3 = diceSimulator();
      }
    }
  }

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
