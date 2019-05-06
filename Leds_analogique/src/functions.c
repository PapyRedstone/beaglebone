#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

