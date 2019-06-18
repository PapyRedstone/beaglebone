#include "functions.h"

int main(int argc, char ** argv){
  if(argc == 5){
    trans_trame_433MHz(*argv[1], atoi(argv[2]), ! atoi(argv[3]), atoi(argv[4]));
    return 0;
  }

  if(argc == 2 && !strcmp(argv[0], "autonome")){
    while(1){
      selection();
    }
  }

  printf("Veuillez choisir un mode\n");
  printf("\t1: Autonome\n");
  printf("\t2: Recherche de prises\n");
  printf("\t3: Manuelle\n");
  printf("> ");
  char choix, choix1, choix2;
  scanf(" %c", &choix);
  fflush(stdin);	
  switch(choix){
  case '1':
    while(1){
      selection();
    }
    break;

  case '2':
    bruteForce();
    break;

  case '3':
    if(!etatRVB){
      etatRVB = malloc(sizeof(char)*4);
    }
    while(1){
      printf("Voulez allumer(A) ou eteindre (E) > ");
      scanf(" %c", &choix1);
      fflush(stdin);
      printf("Selectionner une led (R,V ou B) ou tous (T) > ");
      scanf(" %c", &choix2);
      switch(choix2){
      case 'R':
	if(choix1 == 'A'){
	  etatRVB[0] = 1;
	}else if(choix1 == 'E'){
	  etatRVB[0] = 0;
	}
	commande_radio('R', etatRVB);
	control_RVB(1,0,0);
	break;
	      
      case 'V':
	if(choix1 == 'A'){
	  etatRVB[1] = 1;
	}else if(choix1 == 'E'){
	  etatRVB[1] = 0;
	}
	commande_radio('V', etatRVB);
	control_RVB(0,1,0);
	break;
	      
      case 'B':
	if(choix1 == 'A'){
	  etatRVB[2] = 1;
	}else if(choix1 == 'E'){
	  etatRVB[2] = 0;
	}
	commande_radio('B', etatRVB);
	control_RVB(0,0,1);
	break;

      case 'T':
	if(choix1 == 'A'){
	  etatRVB[0] = 1;
	  etatRVB[1] = 1;
	  etatRVB[2] = 1;
	}else if(choix1 == 'E'){
	  etatRVB[0] = 0;
	  etatRVB[1] = 0;
	  etatRVB[2] = 0;
	}
	commande_radio('R', etatRVB);
	commande_radio('V', etatRVB);
	commande_radio('B', etatRVB);
	control_RVB(0,0,0);
	break;
      }
    }
    break;
  }

  printf("Fin du programme\n");
  
  if(p9_16){
    fclose(p9_16);
  }
  if(etatRVB){
    free(etatRVB);
  }
  return 0;
}
