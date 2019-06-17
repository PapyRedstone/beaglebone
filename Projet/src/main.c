#include "functions.h"

int main(int argc, char ** argv){
  while(1){
    //selection();
    GPIO_1to0(tREF, tREF3);
  }
  if(p9_16){
    free(p9_16);
  }
  if(etatRVB){
    free(etatRVB);
  }
  return 0;
}
