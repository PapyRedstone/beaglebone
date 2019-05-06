#include "functions.h"
#include <unistd.h>
#define bool int

int main(void){
  while(1){
    int val = readADC();
    if(val < 1800*2/3){
      control_RVB(1,0,0);
    }else if(val < 1800*1/3){
      control_RVB(0,1,0);
    }else{
      control_RVB(0,0,1);
    }
  }
}
