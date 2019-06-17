#include "functions.h"

void setLEDetat(char x, char y, char value){
  char fileName[29];
  sprintf(fileName, "/sys/class/gpio/gpio%d/value", x*32+y);
  FILE *file = fopen(fileName, "w");
  fprintf(file, "%d", value);
  fflush(file);
  fclose(file);
}

void control_RVB(char R, char V, char B){
  setLEDetat(1,18, R);
  setLEDetat(1,28, V);
  setLEDetat(0, 3, B);
}

int read_ADC(){
  unsigned int etat;
  FILE *file = fopen("/sys/devices/ocp.3/helper.14/AIN3", "r");
  fscanf(file, "%d", &etat);
  fclose(file);
  return etat;
}

unsigned int etatPB(){
  FILE *file = NULL;
  unsigned int etat;
  file = fopen("/sys/class/gpio/gpio48/value", "r");
  fscanf(file, "%d", &etat);
  fclose(file);
  return etat;
}

void commande_radio(char tube, char* etat){
  switch(tube){
  case 'R':
    etat[0] = !etat[0];
    if(etat[0]){//eteint
      printf("Le tube rouge est eteint\n");
    }else{//allume
      printf("Le tube rouge est allume\n");
    }
    break;
  case 'B':
    etat[2] = !etat[2];
    if(etat[2]){//eteint
      printf("Le tube bleu est eteint\n");
    }else{//allume
      printf("Le tube bleu est allume\n");
    }
    break;
  case 'V':
    etat[1] = !etat[1];
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

void selection(){
  static bool boutonAppuie = false;
  if (!etatRVB){
    etatRVB = malloc(sizeof(char)*3);
  }
  char choixRVB;
  int adc = read_ADC();
  
  if(adc < 1796*1/3){
    control_RVB(1,0,0);
    choixRVB = 'R';
  }else if(adc < 1796*2/3){
    control_RVB(0,1,0);
    choixRVB = 'V';
  }else{
    control_RVB(0,0,1);
    choixRVB = 'B';
  }

  if(!etatPB()){
    if(!boutonAppuie){
      commande_radio(choixRVB, etatRVB);
    }
    boutonAppuie = true;
  }else{
    boutonAppuie = false;
  }
}

void GPIO_1to0(int delay1, int delay0){
  if(!p9_16){
    p9_16 = fopen("/sys/class/gpio/gpio51/value", "w");
  }
  fprintf(p9_16, "%d", 1);
  fflush(p9_16);
  usleep(delay1);
  fprintf(p9_16, "%d", 0);
  fflush(p9_16);
  usleep(delay0);
}
