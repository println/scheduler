/* 
 * File:   tipos.h
 * Author: proto
 *
 * Created on 12 de Novembro de 2012, 23:37
 */

#ifndef TIPOS_H
#define	TIPOS_H

#ifdef	__cplusplus
extern "C" {
#endif

typedef struct user{
  char id[80];
  int grant;
  struct scheduler * waiting;
  struct queue * done;
  struct user * next;
}TUser;

typedef struct scheduler{
  int priority;
  struct queue * tasks;
  struct scheduler * next;
}TScheduler, PriorityList;

typedef struct task{
  TUser * owner;
  unsigned int pid;
  int priority;
  char cmd[80];
}Task;

typedef struct node{
  Task * info;
  struct node * next;
}TNode;

typedef struct queue{
  TNode * begin;
  TNode * end;
}TQueue;

typedef struct base{
  unsigned int pid;		//id para o prox processo
  TUser * users;		//LISTA de usuarios
  TQueue * FE;			//FILA de processos inicias
  TQueue * FTR;
  TScheduler * scheduler;	//LISTA do escalonador
}TBase;


#ifdef	__cplusplus
}
#endif

#endif	/* TIPOS_H */

