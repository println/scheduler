void waiting_for(Task * task){
  TUser * user = task->owner;
  push(user->waiting,task);
}

void to_done(Task * task){
  TUser * user = task->owner;
  TQueue * q = initializeq();
  while(!emptyq(user->waiting)){
    Task * tmp = pop(user->waiting); 
    if(tmp != task)
      push(q,tmp);
  }
  
  releaseq(user->waiting);
  user->waiting = q;
  
  push(user->done,task);
  
}

TUser * create_user(TUser * ulist, char * name, int grant){
  TUser * user = (TUser*)malloc(sizeof(TUser));
  
  strcpy(user->id,name);
  user->grant = grant;
  user->waiting= initializeq();
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

TUser * search_user( TUser *ulist, char *name){
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

TUser * get_user(TUser * ulist, char * name){
  if(!ulist || !name)
    return NULL;
    
  TUser * user = search_user(ulist,name);
  if(!user)
    user = create_user(ulist,name,1);
  
  return user;    
}

TUser * initialize_userlist(void){
  return create_user(NULL,"root",0);
}