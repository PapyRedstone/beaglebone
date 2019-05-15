#include "functions.h"

int main(void){
  unsigned int i;
  char *words = read_EEPROM();
  for(i = 0 ; i<32768 ; i++){
    printf("%d : %x\n", i, words[i]);
  }

  free(words);
}
