#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "tipos.c"
#include "fila.c"
#include "lprioridade.c"
#include "lusuario.c"
#include "base.c"


int run_rootcmd(TBase * base, char * cmd){
  
  TUser * user = get_user(base->users,"root");

  Task * task = create_task(user, base->pid++, 0, cmd);
  spool(base,task);
  
  return 1;
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
  
  TUser * user = set_user(base->users,u);

  Task * task = create_task(user, base->pid++, priority, c);
  spool(base,task);
  
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
  
  else if(!strcmp("print",command))
    printf("print\n");
  
  else if(!strcmp("exit",command)){
    printf("exit\n");
    return 0;
  }
  
  else if(check_user_cmd(command))
    run_usercmd(base,command);
  
  else
    run_rootcmd(base,cmd);
  
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
  
  print_fu(base);

  return(0); 
}


