#include "functions.h"

int read_ADC(){
  unsigned int etat;
  FILE *file = fopen("/sys/devices/ocp.3/helper.14/AIN3", "r");
  fscanf(file, "%d", &etat);
  fclose(file);
  return etat;
}

void mod_PWM(int value){
  FILE *file = fopen("/sys/devices/ocp.3/pwm_test_P9_14.15/duty", "w");
  fprintf(file, "%d", value);
  fflush(file);
  fclose(file);
}
