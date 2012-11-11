#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "tipos.c"
#include "fila.c"
#include "lista.c"
#include "base.c"


int command(char * cmd, TBase * base){
  char command[120];
  char arg[120];
  
  sscanf(cmd,"%[^ ] %s",command,arg);
   
  if(!strcmp("load",command)) 
    printf("load");
  
  else if(!strcmp("print",command))
    printf("print");
  
  else if(!strcmp("exit",command)){
    printf("exit");
    return 0;
  }
  
  else if(!strcmp("exec",command))
    printf("exec");
  
  else
    printf("comando desconhecido");
  
  printf("\n");
  return 1;
}

int main(void){  
  TBase * base = start_base();
  char input[120];
  int loop = 1;
  
  
  scanf("%[^\n]s", input);
  loop = command(input,base);
  
  return(0); 
}


