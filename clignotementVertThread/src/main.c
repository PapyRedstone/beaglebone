#include "functions.h"

#define bool int

int main(void){

  pthread_t thread1;
  
  if(pthread_create(&thread1, NULL, clignot, NULL) == -1) {
	  perror("pthread_create");
	  return -1;
    }
  
  while(1){}
}
