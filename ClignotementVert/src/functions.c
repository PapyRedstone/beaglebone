#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void allumeLED(){
  FILE *file = NULL;

  file = fopen("/sys/class/gpio/gpio50/value", "w");
  fprintf(file, "%d", 1);
  fflush(file);
  fclose(file);
}

void eteintLED(){
  FILE *file = NULL;

  file = fopen("/sys/class/gpio/gpio50/value", "w");
  fprintf(file, "%d", 0);
  fflush(file);
  fclose(file);
}

unsigned int etatPB(){
  FILE *file = NULL;
  unsigned int etat;
  file = fopen("/sys/class/gpio/gpio48/value", "r");
  fscanf(file, "%d", &etat);
  fclose(file);
  return etat;
}
