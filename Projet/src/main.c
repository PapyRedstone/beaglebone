#include "functions.h"

int main(int argc, char ** argv){
  while(1){
    //selection();
    trans_data_433MHz('1');
    trans_data_433MHz('0');
    trans_data_433MHz('S');
  }
  if(p9_16){
    free(p9_16);
  }
  if(etatRVB){
    free(etatRVB);
  }
  return 0;
}
