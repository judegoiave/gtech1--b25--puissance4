#include <stdio.h>
#include <stdbool.h>

#define NBL 6
#define NBC 7

char tokens[] = "ox";
char tab [NBL] [NBC];
int tours = 0;

//Initiation tableau

void inittab(void) {
  for (int l=0; l<NBL ; l++) {
    for(int c=0; c<NBC ; c++) {
      tab [l][c] = '.';
    }
  }
}

void printtab(){
  for (int l=0; l<NBL; l++){
    printf("\n-----------------------------\n");
    for (int c=0; c<NBC; c++) {
      printf("| %c ", tab [l][c]);
}
    printf("|");
  }
printf("\n-----------------------------\n");
printf("  1   2   3   4   5   6   7");
printf("\n");
}

void main(void){
 bool player = 0;
  printf("\n");
  printf("Bienvenue dans le jeu du Puissance 4 ! \n ");
  printf("Joueur 1 vous avez les Pions 'x'\n ");
  printf("Joueur 2 vous avez les Pions 'o'\n ");
  printf("Joueur 1 veuiller commencer la partie");
  inittab();
  printtab();

   do{ //Boucle de jeu
    do{ // boucle de saisie du joueur courant
      int saisie;
      printf("\n");
      printf("Veuillez entrer un chiffre entre 1 et 7: ");
      scanf("%d", &saisie);
      // TODO: tester nbmatch
   if(saisie < 1||saisie > 7){
        printf("Votre numéro de colonne n'est pas valide \n");
      }
        else{
          tours++;
         for(int l=0;l<NBL;l++){
           if(tab[l][saisie-1]=='x'||tab[l][saisie-1]=='o'){
             tab[l-1][saisie-1]=tokens[player];
            break;
           }
           else if(l==NBL-1){
             tab[l][saisie-1]=tokens[player];
         }
       }
    printtab();
    player = !player;
 }

   }while(true); // Fin de boucle saisie
  }while(tours < 42); // Fin de boucle
}
