/*******************************************************************************
 * leds.c
 ******************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*******************************************************************************
 * Controle des leds -> off
 ******************************************************************************/
void led_off(char led_number)
{
  FILE *file = NULL;
  switch(led_number)
    {
#pragma message "Vous ne devez pas faire d'appel systeme depuis le C"
#pragma message "Remplacer le code ci-dessous avec des fopen, fprintf, fclose"
#pragma message "Verifier sur la Beaglebone le chemin /sys/class/leds/..."
    case 0 : file = fopen("/sys/class/leds/beaglebone:green:usr0/brightness", "w"); break;
    case 1 : file = fopen("/sys/class/leds/beaglebone:green:usr1/brightness", "w"); break;
    case 2 : file = fopen("/sys/class/leds/beaglebone:green:usr2/brightness", "w"); break;
    case 3 : file = fopen("/sys/class/leds/beaglebone:green:usr3/brightness", "w"); break;
    }
  fprintf(file, "%d", 0);
  fflush(file);
  fclose(file);
}

/*******************************************************************************
 * Controle des leds -> on
 ******************************************************************************/
void led_on(char led_number)
{
  FILE *file = NULL;
  switch(led_number)
    {
#pragma message "Vous ne devez pas faire d'appel systeme depuis le C"
#pragma message "Remplacer le code ci-dessous avec des fopen, fprintf, fclose"
#pragma message "Verifier sur la Beaglebone le chemin /sys/class/leds/..."
    case 0 : file = fopen("/sys/class/leds/beaglebone:green:usr0/brightness", "w"); break;
    case 1 : file = fopen("/sys/class/leds/beaglebone:green:usr1/brightness", "w"); break;
    case 2 : file = fopen("/sys/class/leds/beaglebone:green:usr2/brightness", "w"); break;
    case 3 : file = fopen("/sys/class/leds/beaglebone:green:usr3/brightness", "w"); break;
    }
  fprintf(file, "%d", 1);
  fflush(file);
  fclose(file);
}
