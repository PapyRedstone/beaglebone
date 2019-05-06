#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

// Protos
void setLEDetat(char x, char y, char value);
int read_ADC();
void mod_PWM(int value);

void *red(void *ptr);
void *blue(void *ptr);
void *green(void *ptr);

static int adc;
static pthread_mutex_t adcMutex;
#endif
