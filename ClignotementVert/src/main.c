#include "functions.h"
#include <unistd.h>
#define bool int

int main(void){
  bool etatLed = 0;
  
  while(1){
    if(etatLed){
      allumeLED();
    }else{
      eteintLED();
    }
    etatLed = !etatLed;
    usleep(500);
  }
}
