#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void allumeLED(int x, int y){
  char fileName[29];
  sprintf(fileName, "/sys/class/gpio/gpio%d/value", x*32+y);
  FILE *file = fopen(fileName, "w");
  fprintf(file, "%d", 1);
  fflush(file);
  fclose(file);
}

void eteintLED(int x, int y){
  char fileName[29];
  sprintf(fileName, "/sys/class/gpio/gpio%d/value", x*32+y);
  FILE *file = fopen(fileName, "w");
  fprintf(file, "%d", 0);
  fflush(file);
  fclose(file);
}
