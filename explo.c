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

// structures
struct Lieu {
  char nom[9];
  char desc[500];
  int diff;
  char id[7];
};

/*
(1) Lecocia
(2) Astaxus
(3) Ecacyre
(4) Nonalas
(5) Grajarim
(6) Phegiamel
(7) Urriran
*/

// création des lieux
struct Lieu Lieu1 = {"Lecocia", "Un petit village paisible et ensoleille s'offre a toi.", 1, 1};
struct Lieu Lieu2 = {"Astaxus", "Tu arrives dans une petite ville marchande.", 1, 2};
struct Lieu Lieu3 = {"Ecacyre", "Ecacyre est un lieu peuple principalement de soldats, avec cependant quelques commerces a disposition.", 7, 3};
struct Lieu Lieu4 = {"Nonalas", "Une cite gigantesque et pleine de joie de vivre se tient devant toi.", 14, 4};
struct Lieu Lieu5 = {"Grajarim", "Grajarim est une grande plaine vide, hormis quelques arbres.", 14, 5};
struct Lieu Lieu6 = {"Phegiamel", "Tu te rends dans cette métropole étrangement toujours de nuit, avec une lune bien claire.", 7, 6};
struct Lieu Lieu7 = {"Urriran", "Te voici finalement arrive dans cette cite abandonnee afin d'affronter le monstre qui s'y cacherait...", 19, 7};

int deplacement() {

  // variables de la fonction
  char choixdestination[10];
  int niveau = 1;
  int niveausuffisant = 1;
  int lieuactuel = 0;

    // choix destination
    color(15, 0);
    printf("     --> Lecocia\n");
    Sleep(250);
    printf("     --> Astaxus\n");
    Sleep(250);
    printf("     --> Ecacyre\n");
    Sleep(250);
    printf("     --> Nonalas\n");
    Sleep(250);
    printf("     --> Grajarim\n");
    Sleep(250);
    printf("     --> Phegiamel\n");
    Sleep(250);
    printf("     --> Urriram\n\n");
    Sleep(1000);
    printf("Choisis ta destination : ");
    scanf("%s", choixdestination);
    printf("\n\n");

    // le joueur se rend à Lecocia
    if (choixdestination[0] == 'L' && choixdestination[1] == 'e' && choixdestination[2] == 'c' && choixdestination[3] == 'o' && choixdestination[4] == 'c' && choixdestination[5] == 'i' && choixdestination[6] == 'a') {
      if (lieuactuel == 0 || lieuactuel == 3 || lieuactuel == 5 || lieuactuel == 7) {
        niveausuffisant = 1;
        color(9, 0);
        printf("Vous avez atteint %s. ", Lieu1.nom);
        printf("%s\n\n", Lieu1.desc);
      } else if (lieuactuel == 2 || lieuactuel == 4 || lieuactuel == 6) {
        printf("Le lieu se trouve trop loin de ta position.\n\n");
      }
    }

    // le joueur se rend à Astaxus
    else if (choixdestination[0] == 'A' && choixdestination[1] == 's' && choixdestination[2] == 't' && choixdestination[3] == 'a' && choixdestination[4] == 'x' && choixdestination[5] == 'u' && choixdestination[6] == 's') {
      if (lieuactuel == 0 || lieuactuel == 4 || lieuactuel == 6 || lieuactuel == 7) {
        niveausuffisant = 1;
        color(9, 0);
        printf("Vous avez atteint %s. ", Lieu2.nom);
        printf("%s\n\n", Lieu2.desc);
      } else if (lieuactuel == 1 || lieuactuel == 3 || lieuactuel == 5) {
        printf("Le lieu se trouve trop loin de ta position.\n\n");
      }
    }

    // le joueur se rend à Ecacyre
    else if (choixdestination[0] == 'E' && choixdestination[1] == 'c' && choixdestination[2] == 'a' && choixdestination[3] == 'c' && choixdestination[4] == 'y' && choixdestination[5] == 'r' && choixdestination[6] == 'e' && niveau >= 7) {
      if (lieuactuel == 1 || lieuactuel == 4 || lieuactuel == 7) {
        niveausuffisant = 1;
        color(9, 0);
        printf("Vous avez atteint %s. ", Lieu3.nom);
        printf("%s\n\n", Lieu3.desc);
      }
    } else if (niveau < 7 || lieuactuel == 2 || lieuactuel == 3 || lieuactuel == 5 || lieuactuel == 6 || lieuactuel == 0) {
      niveausuffisant = 0;
      color(15,0);
      printf("Tu n'as pas un niveau suffisant pour acceder a ce lieu, ou bien il se trouve trop loin.\n\n");
    }

    // le joueur se rend à Nonalas
    else if (choixdestination[0] == 'N' && choixdestination[1] == 'o' && choixdestination[2] == 'n' && choixdestination[3] == 'a' && choixdestination[4] == 'l' && choixdestination[5] == 'a' && choixdestination[6] == 's' && niveau >= 14) {
      if (lieuactuel == 2 || lieuactuel == 3 || lieuactuel == 7) {
        niveausuffisant = 1;
        color(9, 0);
        printf("Vous avez atteint %s. ", Lieu4.nom);
        printf("%s\n\n", Lieu4.desc);
      }
    } else if (niveau < 14 || lieuactuel == 1 || lieuactuel == 4 || lieuactuel == 5 || lieuactuel == 6 || lieuactuel == 0) {
      niveausuffisant = 0;
      color(15,0);
      printf("Tu n'as pas un niveau suffisant pour acceder a ce lieu, ou bien il se trouve trop loin.\n\n");
    }

    // le joueur se rend à Grajarim
    else if (choixdestination[0] == 'G' && choixdestination[1] == 'r' && choixdestination[2] == 'a' && choixdestination[3] == 'j' && choixdestination[4] == 'a' && choixdestination[5] == 'r' && choixdestination[6] == 'i' && choixdestination[7] == 'm' && niveau >= 14) {
      if (lieuactuel == 1 || lieuactuel == 6 || lieuactuel == 7) {
        niveausuffisant = 1;
        color(9, 0);
        printf("Vous avez atteint %s. ", Lieu5.nom);
        printf("%s\n\n", Lieu5.desc);
      }
    } else if (niveau < 14 || lieuactuel == 2 || lieuactuel == 3 || lieuactuel == 4 || lieuactuel == 5 || lieuactuel == 0) {
      niveausuffisant = 0;
      color(15,0);
      printf("Tu n'as pas un niveau suffisant pour acceder a ce lieu, ou bien il se trouve trop loin.\n\n");
    }

    // le joueur se rend à Phegiamel
    else if (choixdestination[0] == 'P' && choixdestination[1] == 'h' && choixdestination[2] == 'e' && choixdestination[3] == 'g' && choixdestination[4] == 'i' && choixdestination[5] == 'a' && choixdestination[6] == 'm' && choixdestination[7] == 'e' && choixdestination[8] == 'l' && niveau >= 7) {
      if (lieuactuel == 2 || lieuactuel == 5 || lieuactuel == 7) {
        niveausuffisant = 1;
        color(9, 0);
        printf("Vous avez atteint %s. ", Lieu6.nom);
        printf("%s\n\n", Lieu6.desc);
      }
    } else if (niveau < 7 || lieuactuel == 1 || lieuactuel == 3 || lieuactuel == 4 || lieuactuel == 6 || lieuactuel == 0) {
      niveausuffisant = 0;
      color(15,0);
      printf("Tu n'as pas un niveau suffisant pour acceder a ce lieu, ou bien il se trouve trop loin.\n\n");
    }

    // le joueur se rend à Urriram
    else if (choixdestination[0] == 'U' && choixdestination[1] == 'r' && choixdestination[2] == 'r' && choixdestination[3] == 'i' && choixdestination[4] == 'r' && choixdestination[5] == 'a' && choixdestination[6] == 'm' && niveau >= 19) {
      if (lieuactuel == 1 || lieuactuel == 2 || lieuactuel == 3 || lieuactuel == 4 || lieuactuel == 5 || lieuactuel == 6) {
        niveausuffisant = 1;
        color(9, 0);
        printf("Vous avez atteint %s. ", Lieu7.nom);
        printf("%s\n\n", Lieu7.desc);
      }
    } else if (niveau < 19 || lieuactuel == 7 || lieuactuel == 0) {
      niveausuffisant = 0;
      color(15,0);
      printf("Tu n'as pas un niveau suffisant pour acceder a ce lieu, ou bien il se trouve trop loin.\n\n");
    }


  return 0;
}

int main() {

  // variables
  char nom[20];


  system("cls");

  //titre
  color(0, 15);
  printf("\n\n");
  printf("                    <<<<<<<<<< JEU D'EXPLORATION >>>>>>>>>>                    \n\n");
  printf("\n\n");

  // choix du nom
  printf("\n\n");
  color(12, 0);
  printf("Comment vous appelez-vous ?  ");
  scanf("%s", nom);
  Sleep(1000);
  printf("\n");
  color(9, 0);
  printf("Bonjour %s, es-tu pret a decouvrir de nouveaux horizons ?\n\n", nom);
  Sleep(1000);

  deplacement();


  color(15, 0);
  return 0;

}
