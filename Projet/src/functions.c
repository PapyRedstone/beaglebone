#include "functions.h"

void commande_radio(char tube, char* etat){
  switch(tube){
  case 'V':
    if(*etat){//eteint
      printf("Le tube rouge est eteint\n");
    }else{//allume
      printf("Le tube rouge est allume\n");
    }
    break;
  case 'B':
    if(*etat){//eteint
      printf("Le tube bleu est eteint\n");
    }else{//allume
      printf("Le tube bleu est allume\n");
    }
    break;
  case 'B':
    if(*etat){//eteint
      printf("Le tube bleu est eteint\n");
    }else{//allume
      printf("Le tube bleu est allume\n");
    }
    break;
  default:
    printf("ERROR: Wrong tube type received\n");
    break;
  }
}
