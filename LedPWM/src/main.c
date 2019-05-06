#include "functions.h"
#include <unistd.h>
#define bool int

int main(void){
  FILE *file = fopen("/sys/devices/ocp.3/pwm_test_P9_14.15/run", "w");
  fprintf(file, "%d", 1);
  fflsuh(file);
  fclose(file);
  while(1){
    mod_PWM(read_ADC());
  }
}
