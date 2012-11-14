#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"tipos.h"
#include"fila.h"
#include"lprioridade.h"
#include "lusuario.h"


Task * _createtask(TUser * user, int pid, int priority, char * cmd){
  Task * n = (Task*)malloc(sizeof(Task));
  
  n->pid = pid;
  n->owner = user;
  n->priority = priority;
  strcpy(n->cmd,cmd);
  
  return n;
}

void _waitingfor(Task * task){
    TUser * user = task->owner;
    addtask(user->waiting,task);
}

void _done(Task * task){
    TUser * user = task->owner;
    _remove(user->waiting,task);
    push(user->done, task);
}

int newtask(TBase * base, char * username, int priority, char * cmd){
    
  TUser * user = adduser(base->users,username);
  Task * newtask = _createtask(user,base->pid++,priority,cmd);
  

  _waitingfor(newtask);
  
  push(base->FE,newtask);
  
  if(!base->users)
      base->users = user;
  
  return newtask->pid;
}

int execute(Task * task){ 
    int exec = system(task->cmd);
    _done(task);
    return exec;
}



