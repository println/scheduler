#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"tipos.h"
#include"fila.h"
#include"lprioridade.h"

TUser * _createu(TUser * ulist, char * name, int grant){
  TUser * user = (TUser*)malloc(sizeof(TUser));
  
  strcpy(user->id,name);
  user->grant = grant;
  user->waiting= initializep();
  user->done= initializeq();
  user->next = NULL;
  
  if(!ulist)
    return user;
  
  TUser * tmp = ulist;
  while(tmp->next)
    tmp = tmp->next;
  
  tmp->next = user;
  
  return user;
}

TUser * finduser( TUser *ulist, char *name){
  if(!name)
    return NULL;
  
  TUser * tmp = ulist;
  
  while(tmp){
    if(!strcmp(name,tmp->id))
      return tmp;
    tmp = tmp->next;
  }
  
  return NULL;
}

TUser * adduser(TUser * ulist, char * name){
  if(!name)
    return NULL;
    
  TUser * user = finduser(ulist,name);
  if(!user)
    user = _createu(ulist,name,1);
  
  return user;    
}

TUser * initializeuser(void){
  return NULL;
}

