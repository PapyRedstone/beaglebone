#include "functions.h"

void selection(){}

void commande_radio(char tube, char* etat){
  switch(tube){
  case 'R':
    if(etat[0]){//eteint
      printf("Le tube rouge est eteint\n");
    }else{//allume
      printf("Le tube rouge est allume\n");
    }
    break;
  case 'B':
    if(etat[2]){//eteint
      printf("Le tube bleu est eteint\n");
    }else{//allume
      printf("Le tube bleu est allume\n");
    }
    break;
  case 'V':
    if(etat[1]){//eteint
      printf("Le tube verte est eteint\n");
    }else{//allume
      printf("Le tube verte est allume\n");
    }
    break;
  default:
    printf("ERROR: Wrong tube type received\n");
    break;
  }
}
