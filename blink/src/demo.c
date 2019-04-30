/*******************************************************************************
 * demo.c
 * Programme de test pour BeagleBone - Yves Auffret - ISEN Brest - Yncrea Ouest
 * Configuration ISEN 2019 :
 * - Container LXC avec LXDE sous Debian 9 et x2go server (NX protocol over ssh)
 * - GCC-ARM arm-linux-gnueabihf- 8.3-2019.03
 * - Eclipse C/C++ 2019-03
 ******************************************************************************/

// Mettre les includes systemes entre < >
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#pragma message "Vous devez ajouter un include pour usleep"

// Mettre les includes projet entre " " et dans le rep. src/include du projet
#include "demo.h"

/*******************************************************************************
 * Main
 ******************************************************************************/
 int main(void)
{
	unsigned int loop = 0;
	printf("Hello world !!!\n");
	while(loop < 300)
	{
		printf("Start blinking: %d\n",++loop);
		led_on (3); usleep(100000); led_on (2);
		led_off(3); usleep(100000); led_off(2);
	}
}
