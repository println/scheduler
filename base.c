TBase * start_base(void){
  TBase * base = (TBase*)malloc(sizeof(TBase));
  base->pid = 1;
  base->users = initialize_userlist();
  base->fu = initializeq();
  base->scheduler;
  
  return base;
}

Task * create_task(TUser * user, int pid, int priority, char * cmd){
    
  Task * n = (Task*)malloc(sizeof(Task));
  
  n->pid = pid;
  n->owner = user;
  n->priority = priority;
  strcpy(n->cmd,cmd);
  
  waiting_for(n);
  
  return n;
}
