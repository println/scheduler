TUser * create_user(TUser * ulist, char * name, int grant){
  TUser * user = (TUser*)malloc(sizeof(TUser));
  
  strcpy(user->id,name);
  user->grant = grant;
  user->waiting= initialize_prioritylist();
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

TUser * get_user( TUser *ulist, char *name){
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

TUser * set_user(TUser * ulist, char * name){
  if(!ulist || !name)
    return NULL;
    
  TUser * user = get_user(ulist,name);
  if(!user)
    user = create_user(ulist,name,1);
  
  return user;    
}

TUser * initialize_userlist(void){
  return create_user(NULL,"root",0);
}