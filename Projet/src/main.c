#include "functions.h"

int main(int argc, char ** argv){
  if(argc == 5){
    trans_trame_433MHz(*argv[1], atoi(argv[2]), ! atoi(argv[3]), atoi(argv[4]));
    return 0;
  }
  while(1){
    selection();
  }
  if(p9_16){
    free(p9_16);
  }
  if(etatRVB){
    free(etatRVB);
  }
  return 0;
}
