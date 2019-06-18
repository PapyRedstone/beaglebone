#include "functions.h"

void setLEDetat(char x, char y, char value, char etatTube){
  static unsigned int counter = 0;
  char fileName[29];
  sprintf(fileName, "/sys/class/gpio/gpio%d/value", x*32+y);
  FILE *file = fopen(fileName, "w");
  if(value){
    if(!etatTube){
      fprintf(file, "%d", 1);
    }else{
      if(counter < 1){
        fprintf(file, "%d", 1);
      }else{
        fprintf(file, "%d", 0);
      }
      counter++;
      if(counter > 3){
        counter = 0;
      }
    }
  }else{
    fprintf(file, "%d", 0);
  }

  fflush(file);
  fclose(file);
}

void control_RVB(char R, char V, char B){
  setLEDetat(1,18, R, etatRVB[0]);
  setLEDetat(1,28, V, etatRVB[1]);
  setLEDetat(0, 3, B, etatRVB[2]);
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
    trans_trame_433MHz('D', 1, etat[0], 10);
    break;
  case 'V':
    etat[1] = !etat[1];
    if(etat[1]){//eteint
      printf("Le tube verte est eteint\n");
    }else{//allume
      printf("Le tube verte est allume\n");
    }
    trans_trame_433MHz('C', 2, etat[1], 10);
    break;
  case 'B':
    etat[2] = !etat[2];
    if(etat[2]){//eteint
      printf("Le tube bleu est eteint\n");
    }else{//allume
      printf("Le tube bleu est allume\n");
    }
    trans_trame_433MHz('B', 3, etat[2], 10);
    break;
  default:
    printf("ERROR: Wrong tube type received\n");
    break;
  }
}

void selection(){
  static bool boutonAppuie = false;
  static time_t start = -1;
  time_t end;
  
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
      start = time(NULL);
    }
    boutonAppuie = true;
  }else{
    boutonAppuie = false;
  }

  if(start != -1 && !boutonAppuie){
    end = time(NULL);
    if(end-start >= 3){
      printf("Turn off all tubes\n");
      etatRVB[0] = 0;
      etatRVB[1] = 0;
      etatRVB[2] = 0;
      commande_radio('R', etatRVB);
      commande_radio('V', etatRVB);
      commande_radio('B', etatRVB);
    }else if(end-start >= 2){
      printf("Turn on all tubes\n");
      etatRVB[0] = 1;
      etatRVB[1] = 1;
      etatRVB[2] = 1;
      commande_radio('R', etatRVB);
      commande_radio('V', etatRVB);
      commande_radio('B', etatRVB);
    }else{
      commande_radio(choixRVB, etatRVB);
    }
    start = -1;
  }
}

void GPIO_1to0(int delay1, int delay0){
  struct timespec start, current;
  unsigned long endNano, currentNano;

  if(!p9_16){
    p9_16 = fopen("/sys/class/gpio/gpio51/value", "w");
  }
  fprintf(p9_16, "%d", 1);
  fflush(p9_16);
  usleep(delay1 - 75);
    
  fprintf(p9_16, "%d", 0);
  fflush(p9_16);
  usleep(delay0 - 80);
}

void trans_data_433MHz(char data){
  switch(data){
  case '0':
    GPIO_1to0(tREF, tREF3);
    GPIO_1to0(tREF3, tREF);
    break;
  case '1':
    GPIO_1to0(tREF, tREF3);
    GPIO_1to0(tREF, tREF3);
    break;
  case '2':
    GPIO_1to0(tREF3, tREF);
    GPIO_1to0(tREF3, tREF);
    break;
  case 'S':
    GPIO_1to0(tREF, tREF32);
    break;
  default:
    printf("ERROR: bad transmit data");
  }
}

void trans_trame_433MHz(char maison, char objet, char activation, char repetition){
  char i;
  for(i = 0 ; i < repetition ; i++){
    switch (maison)
    {
    case 'A':
        trans_data_433MHz('1');
        trans_data_433MHz('0');
        trans_data_433MHz('0');
        trans_data_433MHz('0');
      break;

    case 'B':
        trans_data_433MHz('0');
        trans_data_433MHz('1');
        trans_data_433MHz('0');
        trans_data_433MHz('0');
      break;

    case 'C':
        trans_data_433MHz('0');
        trans_data_433MHz('0');
        trans_data_433MHz('1');
        trans_data_433MHz('0');
      break;

    case 'D':
        trans_data_433MHz('0');
        trans_data_433MHz('0');
        trans_data_433MHz('0');
        trans_data_433MHz('1');
      break;
    
    default:
      break;
    }

    switch (objet)
    {
    case 1:
        trans_data_433MHz('1');
        trans_data_433MHz('0');
        trans_data_433MHz('0');
      break;

    case 2:
        trans_data_433MHz('0');
        trans_data_433MHz('1');
        trans_data_433MHz('0');
      break;

    case 3:
        trans_data_433MHz('0');
        trans_data_433MHz('0');
        trans_data_433MHz('1');
      break;
    
    default:
      break;
    }

    trans_data_433MHz('0');
    trans_data_433MHz('1');
    trans_data_433MHz('1');
    trans_data_433MHz('1');

    trans_data_433MHz(activation + 48);
    trans_data_433MHz('S');
  }
}

char* decimalNumberToBinaryString(unsigned int number){
  char binary[4];
  binary[3] = number >> 3 + 48;
  binary[2] = number >> 2 &0x1 + 48;
  binary[1] = number >> 1 &0x1 + 48;
  binary[0] = number &0x1 + 48;
  return binary;
}

}

void trans_trame2_433MHz(char maison, char objet, char activation, char repetition){
  char i;

  char *m = decimalNumberToBinaryString(maison-'A');
  char *o = decimalNumberToBinaryString(objet);
  for(i = 0 ; i < repetition ; i++){
    
    for(char j=0; j<; j++){
      trans_data_433MHz(m[j]);
    }

    for(char j=0; j<; j++){
      trans_data_433MHz(o[j]);
    }

    trans_data_433MHz('1');
    trans_data_433MHz('1');
    trans_data_433MHz('1');

    trans_data_433MHz(activation + 48);
    trans_data_433MHz('S');
  }
}
