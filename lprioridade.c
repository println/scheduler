PriorityList * create_priority(PriorityList * plist, int priority){//insere ordenado
  PriorityList * item = (PriorityList*)malloc(sizeof(PriorityList));
  
  item->priority = priority;
  item->tasks = initializeq();
  item->next = NULL;
  
  if(!plist)
    return item;
  
  PriorityList * tmp = plist;
  PriorityList * ant;
  while(tmp && tmp->priority <= priority){
    ant = tmp;
    tmp = tmp->next;    
  }
  
  if(ant){
    ant->next = item;
    item->next = tmp;
  }else
    item->next = tmp;
  
  return item;  
}

PriorityList * get_priority( PriorityList *plist, int priority){
 
  PriorityList * tmp = plist;
  
  while(tmp){
    if(tmp->priority == priority)
      return tmp;
    tmp = tmp->next;
  }
  
  return NULL;
}

PriorityList * set_priority(PriorityList * plist, int priority){
  if(!plist)
    return NULL;
    
  PriorityList * user = get_priority(plist,priority);
  if(!user)
    user = create_priority(plist,priority);
  
  return user;    
}

PriorityList * initialize_prioritylist(void){
  return create_priority(NULL,-1);
}

