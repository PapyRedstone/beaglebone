#include "functions.h"

int main(void){

  while(1){
    if(etatPB()){
      allumeLED();
    }else{
      eteintLED();
    }
  }
}