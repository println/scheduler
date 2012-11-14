#include<stdio.h>
#include<stdlib.h>
#include"tipos.h"

void printq(TQueue * q){
  if(emptyq(q))
    return;
  
  TNode * acc = q->begin;
  while(acc){
    Task * task = acc->info;
    printf("%d:%d:%s", task->pid,task->priority,task->cmd);
    acc = acc->next;
    if(acc)
      printf(" - ");
  }
}

void dropq(TQueue * q){
  TNode * acc = q->begin, * temp;
  while(acc){
    temp = acc;
    acc = acc->next;
    temp->info = NULL;
    free(temp);
  }
  free(q);
}

void releaseq(TQueue * q){
  TNode * acc = q->begin, * temp;
  while(acc){
    temp = acc;
    acc = acc->next;
    free(temp->info);
    free(temp);
  }
  free(q);
}

TQueue * initializeq(void){
  TQueue * q = (TQueue *)malloc(sizeof(TQueue));
  q->begin = q->end = NULL;
  return q;
}

void push(TQueue * q, Task * t){
  TNode * n = (TNode *)malloc(sizeof(TNode));
  n->info = t;
  n->next = NULL;
  
  if(q->end)
    q->end->next = n;
 
  q->end = n;
  
  if(!q->begin)
    q->begin = n;
}

Task * pop(TQueue * q){
  if(emptyq(q))
    exit(1);
  
  TNode * n = q->begin;
  q->begin = n->next;
  
  if(!q->begin)
    q->end = NULL;
  
  Task * t = n->info;
  
  free(n);
  
  return t;
}

int emptyq(TQueue * q){
  return (q->begin == NULL);
}

