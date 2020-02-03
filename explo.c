#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <locale.h>

// fonction couleur de texte
void color(int couleurtexte, int couleurfond) {
  HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(H,couleurfond*16+couleurtexte);
}

// pense-bête couleurs
/*      0: noir
        1: bleu foncé
        2: vert
        3: bleu-gris
        4: marron
        5: pourpre
        6: kaki
        7: gris clair
        8: gris
        9: bleu
        10: vert fluo
        11: turquoise
        12: rouge
        13: rose
        14: jaune
        15: blanc          */

int main() {

  // variables
  char nom[20];
  int choixdestination;
  int lecocia;
  int astaxus;




  system("cls");

  //titre
  color(0, 15);
  printf("\n\n");
  printf("                    <<<<<<<<<< JEU D'EXPLORATION >>>>>>>>>>                    \n\n");
  printf("\n\n");

  // choix du nom
  printf("\n\n");
  color(9, 0);
  printf("Comment vous appelez-vous ?  ");
  scanf("%s", nom);
  Sleep(1000);
  printf("\n");
  printf("Bonjour %s, es-tu pret a decouvrir de nouveaux horizons ?\n\n", nom);
  Sleep(1000);

  // choix destination
  color(15, 0);
  printf("     --> Lecocia (1)\n");
  Sleep(500);
  printf("     --> Astaxus (2)\n\n");
  Sleep(1000);
  printf("Choisis ta destination : ");
  scanf("%d", &choixdestination);
  printf("\n\n");

  // le joueur se rend à Lecocia
  if (choixdestination == 1) {
    color(9, 0);
    printf("Vous avez atteint Lecocia.\n");
  }

  // le joueur se rend à Astaxus
  if (choixdestination == 2) {
    color(9, 0);
    printf("Vous avez atteint Astaxus.\n");
  }

}
