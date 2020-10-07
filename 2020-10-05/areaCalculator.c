/*
 ============================================================================
 Name        :
 Author      :
 Version     :
 Copyright   :
 Description :
 ============================================================================
 */

#define _USE_MATH_DEFINES

#include <math.h>   //d�clare les fonctions math�matiques usuelles
#include <stdio.h>  //fonctions qui g�rent les entr�es/sorties des programmes �crits en C. Vous en aurez besoin � cause des printf et scanf
#include <stdlib.h>  //d�clare des fonctions qui effectuent la conversion de nombres, la gestion de la m�moire et d'autres t�ches.

int main(
    void)  // fonction principale. Tout programme fait appel � cette fonction
{
  int continueCalculation = 1;

  while (continueCalculation) {
    int shape;
    printf(
        "Enter number of desired shape: 1) square, 2) rectangle, 3) triangle, "
        "4) circle\n");
    scanf("%i", &shape);
    printf("You entered: %i \n", shape);

    switch (shape) {
      case 1: {
        double side;
        printf("Enter square side: ");
        scanf("%lf", &side);
        printf("The square area is %lf \n", side * side);
        printf("\n");
        break;
      }
      case 2: {
        double side1;
        double side2;

        printf("Enter first rectangle side: ");
        scanf("%lf", &side1);
        printf("Enter second rectangle side: ");
        scanf("%lf", &side2);
        printf("The rectangle area is %lf \n", side1 * side2);
        printf("\n");
        break;
      }
      case 3: {
        double base;
        double height;

        printf("Enter triangle base: ");
        scanf("%lf", &base);
        printf("Enter triangle height: ");
        scanf("%lf", &height);

        printf("The triangle area is %lf \n", base * height / 2);
        printf("\n");
        break;
      }
      case 4: {
        double radius;
        printf("Enter circle radius: ");
        scanf("%lf", &radius);
        printf("The circle area is %lf \n", radius * radius * M_PI);
        printf("\n");
        break;
      }

      default:
        break;
    }

    printf("Do you want to continue (1 = yes, 0 = no)? ");
    scanf("%i", &continueCalculation);
  }

  return EXIT_SUCCESS;
}
