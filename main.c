#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"base.h"
#include"fila.h"
#include"lprioridade.h"
#include"lusuario.h"

int run_exec(TBase * base){
    Task * task = NULL;
    if(!emptyq(base->FTR))
        task = pop(base->FTR);
    else if(!emptyp(base->FU))
        task = toptask(base->FU);
    
    if(task)
        return execute(task);
    
    return 0;
}
int run_execall(TBase * base){
    while(!emptyq(base->FTR) || !emptyp(base->FU))
        run_exec(base);
}

int run_prepare(TBase * base){
    arrange(base);
}

int run_usercmd(TBase * base, char * cmd){
  int i, j, value = 0;
  
  char end = '\0';
  char u[120] = "", p[120] = "", c[120] = "";
  
  for(i = 0, j = 0; cmd[i] != end; i++, j++){  
    if(cmd[i] == ':' && value < 2){
      value++;
      j = -1;
    }else{
      if(value == 0){
	u[j] = cmd[i];
	u[j+1] = end;
      }
      if(value == 1){
	p[j] = cmd[i];
	p[j+1] = end;
      }
      if(value == 2){
	c[j] = cmd[i];
	c[j+1] = end;	
      }
    }
  }
  
  if(value != 2 || u[0] == '\0' || p[0] == '\0' || c[0] == '\0')
    return 0;
  
  for(j = 0; p[j] != end; j++){//somente valores positivos
    if(p[j] == '-' || p[j] < '0' || p[j] > '9'){
      printf("somente prioridade inteira positiva!\n");
      return 0;     
    }    
  }
  
  if(!base)
    return 1;
  
  int priority;
  
  sscanf(p,"%i",&priority);

  unsigned int pid = newtask(base, u, priority, c);
  
  printf("ID: %d\n", pid);
  
  return 1;
}

int check_user_cmd(char * cmd){
  return run_usercmd(NULL,cmd);
}

int command(char * cmd, TBase * base){
  char command[120];
  char arg[120];
  
  sscanf(cmd,"%[^ ] %s",command,arg);
   
  if(!strcmp("load",command)) 
    printf("load\n");
  
  else if(!strcmp("make",command)){
    run_prepare(base);
  }
  else if(!strcmp("run",command)){
    run_exec(base);
  }
  else if(!strcmp("runall",command)){
    run_execall(base);
  }
  else if(!strcmp("exit",command)){
    return 0;
  }
  
  else if(check_user_cmd(cmd))
    run_usercmd(base,cmd);
  
  else
    printf("comando inexistente\n");
  
  return 1;
}

int main(void){  
  TBase * base = start_base();
  char input[120];
  int loop = 1;
  
  while(loop){
    scanf(" %[^\n]s", input);
    loop = command(input,base);
  }
  
  printf("\n");
  print_waiting(base);
  
  print_fe(base);

  return(0); 
}


