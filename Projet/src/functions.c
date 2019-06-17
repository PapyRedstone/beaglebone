int read_ADC(){
  unsigned int etat;
  FILE *file = fopen("/sys/devices/ocp.3/helper.14/AIN3", "r");
  fscanf(file, "%d", &etat);
  fclose(file);
  return etat;
}

unsigned int etatPB(){
  FILE *file = NULL;
  unsigned int etat;
  file = fopen("/sys/class/gpio/gpio48/value", "r");
  fscanf(file, "%d", &etat);
  fclose(file);
  return etat;
}

void setLEDetat(char x, char y, char value){
  char fileName[29];
  sprintf(fileName, "/sys/class/gpio/gpio%d/value", x*32+y);
  FILE *file = fopen(fileName, "w");
  fprintf(file, "%d", value);
  fflush(file);
  fclose(file);
}

void control_RVB(char R, char V, char B){
  setLEDetat(1,18, R);
  setLEDetat(1,28, V);
  setLEDetat(0, 3, B);
}

void selection(){
  int adc = read_ADC();

  if(adc < 1800*1/3){
     control_RVB(1,0,0);
  }else if(adc < 1800*2/3){
    control_RVB(0,1,0);
  }else{
    control_RVB(0,0,1);
  }

  if(!etatPB()){
    commande_radio();
  }else{
    commande_radio();
  }
}