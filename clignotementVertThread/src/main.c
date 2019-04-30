#include "functions.h"
#include <unistd.h>
#define bool int

int main(void){
  bool etatLed = 0;
  
  while(1){
    permutLED();
    usleep(500000);
  }
}
