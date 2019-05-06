#include "functions.h"

void allumeLED(){
  FILE *file = fopen("/sys/class/gpio/gpio60/value", "w");
  fprintf(file, "%d", 1);
  fflush(file);
  fclose(file);
}

void eteintLED(){
  FILE *file = fopen("/sys/class/gpio/gpio60/value", "w");
  fprintf(file, "%d", 0);
  fflush(file);
  fclose(file);
}

void permutLED(){
  FILE * file = fopen("/sys/class/gpio/gpio60/value", "r");
  int etat;
  fscanf(file, "%d", &etat);
  fclose(file);
  if(etat){
    eteintLED();
  }else{
    allumeLED();
  }
}

void *clignot(void *ptr)
{
  printf("Nous sommes dans le thread.\n");
  while(1){
    permutLED();
    usleep(500000);
  }
  /* Pour enlever le warning */
  (void) ptr;
  pthread_exit(NULL);
}