#include "functions.h"
#define bool int

int main(void){
  FILE *file = fopen("/sys/devices/ocp.3/pwm_test_P9_14.15/run", "w");// activer PWM sur le hard
  fprintf(file, "%d", 1);
  fflush(file);
  fclose(file);

  pthread_t tRed, tGreen, tBlue;

  pthread_create(&tRed, NULL,   red,   NULL);
  pthread_create(&tGreen, NULL, green, NULL);
  pthread_create(&tBlue, NULL,  blue,  NULL);

  pthread_join(tRed,   NULL);
  pthread_join(tGreen, NULL);//attend que les threads se finissent
  pthread_join(tBlue,  NULL);
}
