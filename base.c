#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"tipos.h"
#include"fila.h"
#include"lprioridade.h"
#include"lusuario.h"

TBase * start_base(void){
  TBase * base = (TBase*)malloc(sizeof(TBase));
  base->pid = 1;
  base->users = initialize_userlist();
  base->FE = initializeq();
  base->FTR = initializeq();
  base->scheduler = initialize_prioritylist();
  
  return base;
}

void waiting_for(Task * task){
  TUser * user = task->owner;
  PriorityList * plist = set_priority(user->waiting,task->priority);
  push(plist->tasks,task);
}

void to_done(Task * task){
  TUser * user = task->owner;
  PriorityList * plist = get_priority(user->waiting,task->priority);
  TQueue * q = initializeq();
  
  while(plist && plist->priority != task->priority)
   plist = plist->next;
  
  while(plist && !emptyq(plist->tasks)){
    Task * tmp = pop(plist->tasks); 
    if(tmp != task)
      push(q,tmp);
  }
  
  releaseq(plist->tasks);
  plist->tasks = q;
  
  push(user->done,task);
  
}

Task * create_task(TUser * user, int pid, int priority, char * cmd){
    
  Task * n = (Task*)malloc(sizeof(Task));
  
  n->pid = pid;
  n->owner = user;
  n->priority = priority;
  strcpy(n->cmd,cmd);
  
  waiting_for(n);
  printf("ID: %d\n", pid);
  return n;
}

void spool(TBase * base, Task * task){
  push(base->FE,task);
}

void printform_tasks(TQueue * q){
  if(!emptyq(q)){
    printf(" -> ");
    printq(q);
  } 
}

void printform_user(char * name,TQueue * q){
  printf("%s",name);
  printform_tasks(q);
  printf("\n");
}

void printform_priority(int priority,TQueue * q){
  printf("|-%i",priority);
  printform_tasks(q);
  printf("\n");
}

void printform_userpriority(char * name,PriorityList * plist){
  printf("%s",name);
  PriorityList * tmp = plist;
  printf("\n");
  while(tmp){
    if(tmp->priority != -1)
      printform_priority(tmp->priority,tmp->tasks);
          
    tmp = tmp->next;
  }
  printf("\n");
}

void print_waiting(TBase * base){
  TUser * user = base->users;
  
  while(user){
    printform_userpriority(user->id,user->waiting);
    user = user->next;
  }
}

void print_done(TBase * base){
  TUser * user = base->users;
  while(user){
    printform_user(user->id,user->done);
    user = user->next;
  }
}

void print_fu(TBase * base){
  printf("FU -> ");
  printq(base->FE);
  printf("\n");
}