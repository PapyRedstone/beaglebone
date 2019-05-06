#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
// Protos
void allumeLED();
void eteintLED();
void permutLED();
void *clignot(void *arg);
#endif
