#include "functions.h"

char *read_EEPROM(){

  char *words = malloc(32768 * sizeof(char));
  unsigned int i = 0;
  FILE *file = fopen("/sys/bus/i2c/devices/1-0054/eeprom", "r");
  while(!feof(file)){
    fscanf(file, "%c", &words[i]);
    i++;
    printf("%d\n", i);
  }
  fclose(file);
  return words;
}
