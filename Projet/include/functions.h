#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define false 0
#define true 1
typedef int bool;

#define tREF   333
#define tREF3  999
#define tREF32 10656

void selection();
void commande_radio(char tube, char *etat);
void GPIO_1to0(int delay1, int delay0);

FILE* p9_16;
char* etatRVB;


