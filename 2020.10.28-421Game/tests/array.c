/*
 ============================================================================
 Name        : INFO1MI2020_labo4.c
 Author      : E.ZYSMAN
 Version     : 1
 Copyright   : Your copyright notice
 Description : JOUER AUX DéS in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void viderBuffer(void) {
  // méthode efficace pour vider le buffer clavier
  // il faut consommer tous les caractères présents dans ce buffer jusqu'à ce
  // qu'il soit vide !!!
  int c;

  do {
    c = getchar();
  } while (c != '\n' && c != EOF);
}

int main(void) {
  char conserver[4] = {0};

  char onContinue;
  do {
    printf("entrer votre choix: ");
    scanf("%s", conserver);
    viderBuffer();
    // conserver[3]='\0';
    printf("vous avez choisi %s \n", conserver);
    printf("détail de votre choix Dé1 = %c, Dé2=%c, Dé3=%c \n", conserver[0],
           conserver[1], conserver[2]);
    // chaque dé peut donc être testé séparément
    printf("voulez vous jouer taper y/n ");
    scanf("%c", &onContinue);
  } while (onContinue == 'y');

  return EXIT_SUCCESS;
}