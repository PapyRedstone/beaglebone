#include "functions.h"

static int adc = 0;
static pthread_mutex_t adcMutex = PTHREAD_MUTEX_INITIALIZER;

void setLEDetat(char x, char y, char value){
  char fileName[29];
  sprintf(fileName, "/sys/class/gpio/gpio%d/value", x*32+y);
  FILE *file = fopen(fileName, "w");
  fprintf(file, "%d", value);
  fflush(file);
  fclose(file);
}

int read_ADC(){
  unsigned int etat;
  FILE *file = fopen("/sys/devices/ocp.3/helper.14/AIN3", "r"); //valeurs potar
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

void *red(void *ptr){
  while(1){
    pthread_mutex_lock(&adcMutex);
    adc = read_ADC();
    mod_PWM(adc);
    pthread_mutex_unlock(&adcMutex);
    //printf("RED\n");
  }
  (void) ptr;
  pthread_exit(NULL);
}

void *green(void *ptr){
  while (1){
    pthread_mutex_lock(&adcMutex);
    int tmp = adc;
    pthread_mutex_unlock(&adcMutex);
    setLEDetat(1,28,1);
    usleep(tmp);
    setLEDetat(1,28,0);
    usleep(1800-tmp);
    //printf("GREEN\n");
  }
  (void) ptr;
  pthread_exit(NULL);
}

void *blue(void *ptr){
  while (1){
    pthread_mutex_lock(&adcMutex);
    int tmp = adc;
    pthread_mutex_unlock(&adcMutex);
    setLEDetat(0,3,1);
    usleep(tmp);
    setLEDetat(0,3,0);
    usleep(1800-tmp);
    //printf("BLUE");
  }
  (void) ptr;
  pthread_exit(NULL);
}
