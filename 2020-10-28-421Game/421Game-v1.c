#define _USE_MATH_DEFINES

// standard libraries includes
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// custom defines
#define NUMBER_DICES 3

// prototypes
int gameStart(int* continueGame_p);  // prints text for user interface
int diceSimulator(void);             // simulates dice
int comparator(const void* p1, const void* p2);  // for sort function
void printDices(int* dices_p);                   // print dices values
void printStats(int* stats_p);  // prints stats of the dices thrown

int main(void) {
  srand(time(0));
  int continueGame = 1;
  int youWin = 0;

  gameStart(&continueGame);

  int dices[NUMBER_DICES];
  int dicesWithIndex[NUMBER_DICES];  // array in which we encode the dice
                                     // position in the original array on low
                                     // weight bits
  int stats[6] = {0};  // array to count occurences of every dice value

  for (int i = 0; i < NUMBER_DICES; i++) {
    dices[i] = diceSimulator();
    stats[dices[i] - 1]++;
  }

  while (continueGame) {
    printDices(dices);
    for (int i = 0; i < NUMBER_DICES; i++) {
      dicesWithIndex[i] = dices[i] << 2 | i;
    }
    qsort(dicesWithIndex, NUMBER_DICES, sizeof(int), comparator);

    if (dicesWithIndex[0] >> 2 == 1 && dicesWithIndex[1] >> 2 == 2 &&
        dicesWithIndex[2] >> 2 == 4) {
      continueGame = 0;
      youWin = 1;
    } else {
      int previous = 0;
      for (int i = 0; i < NUMBER_DICES; i++) {
        int currentDice = dicesWithIndex[i] >> 2;
        if (currentDice == previous ||
            (currentDice != 1 && currentDice != 2 && currentDice != 4)) {
          previous = currentDice;
          dices[dicesWithIndex[i] & 3] = diceSimulator();
          stats[dices[i] - 1]++;
        }
      }
      printf("Do you want to continue the game (0 = no, 1 = yes)? ");
      scanf("%i", &continueGame);
    }
  }

  if (youWin == 0) {
    printf("YOU LOST! :( \n");
    printStats(stats);
  } else if (youWin == 1) {
    printf("YOU WON! :) \n");
    printStats(stats);
  }

  return EXIT_SUCCESS;
}

int gameStart(int* continueGame_p) {
  printf(
      "Welcome to the 421 game! Enter: \n"
      "- 0 : exit program\n"
      "- 1 : start a new game\n"
      "- 2 : see the rules and then start a new game\n");
  scanf("%i", continueGame_p);

  if (*continueGame_p == 2) {
    printf(
        "Rules:\n "
        "- In the first turn, you will throw three dices\n "
        "- The goal is to get the values 4, 2 and 1\n "
        "- If the values are not right the first time, the dices that are not "
        "correct are thrown again\n"
        "- You can repeat this until you get the right combination \n \n ");
    *continueGame_p = 1;
  }
  if (*continueGame_p == 0) {
    printf("Goodbye!\n");
    exit(0);
  }
}

/* diceSimulator(): returns integer in range [1; 6]
  PARAMETERS:
    -  void
  RETURNS:
    - integer
  Author: Océane Patiny - 2020.10.28
 */
int diceSimulator(void) {
  return rand() % 6 + 1;
}

// The comparator compares two values (in this case, we'll sort in ascending
// order). The result is passed to the sort function. This function comes from:
// https://www.educative.io/edpresso/what-is-the-qsort-function-in-c
int comparator(const void* p1, const void* p2) {
  return (*(int*)p1 - *(int*)p2);
}

void printDices(int* dices_p) {
  printf("Your dices are: %i %i %i \n", dices_p[0], dices_p[1], dices_p[2]);
}

void printStats(int* stats_p) {
  printf("Dice value  Occurences");
  for (int i = 0; i < 6; i++) {
    printf("%i %i", i + 1, stats_p[i]);
  }
}