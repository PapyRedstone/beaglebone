#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
