#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"tipos.h"
#include"fila.h"
#include"lprioridade.h"
#include"lusuario.h"
#include"tarefa.h"

TBase * start_base(void) {
    TBase * base = (TBase*) malloc(sizeof (TBase));
    base->FE = initializeq();
    base->FPSO = initializeq();
    base->FTR = initializeq();
    base->FU = initializep();
    base->users = initializeuser();
    base->pid = 1;

    return base;
}

void arrange(TBase * base) {
    while (!emptyq(base->FE)) {
        Task * task = pop(base->FE);
        if (task->priority == 0)
            push(base->FTR, task);
        else
            addtask(base->FU, task);
    }
}

//void waiting_for(Task * task){
//  TUser * user = task->owner;
//  PriorityList * plist = _insert(user->waiting,task->priority);
//  push(plist->tasks,task);
//}

//void to_done(Task * task){
//  TUser * user = task->owner;
//  PriorityList * plist = _contains(user->waiting,task->priority);
//  TQueue * q = initializeq();
//  
//  while(plist && plist->priority != task->priority)
//   plist = plist->next;
//  
//  while(plist && !emptyq(plist->tasks)){
//    Task * tmp = pop(plist->tasks); 
//    if(tmp != task)
//      push(q,tmp);
//  }
//  
//  releaseq(plist->tasks);
//  plist->tasks = q;
//  
//  push(user->done,task);
//  
//}

//void spool(TBase * base, Task * task){
//  push(base->FE,task);
//}

void printform_tasks(TQueue * q) {
    if (!emptyq(q)) {
        printf(" -> ");
        printq(q);
    }
}

void printform_user(char * name, TQueue * q) {
    printf("%s", name);
    printform_tasks(q);
    printf("\n");
}

void printform_priority(int priority, TQueue * q) {
    printf("|-%i", priority);
    printform_tasks(q);
    printf("\n");
}

void printform_userpriority(char * name, PriorityList * plist) {
    printf("%s", name);
    TPriority * tmp = plist->priorities;
    printf("\n");
    while (tmp) {
        printform_priority(tmp->priority, tmp->tasks);
        tmp = tmp->next;
    }
    printf("\n");
}

void print_waiting(TBase * base) {
    TUser * user = base->users;

    while (user) {
        printform_userpriority(user->id, user->waiting);
        user = user->next;
    }
}

void print_done(TBase * base) {
    TUser * user = base->users;
    while (user) {
        printform_user(user->id, user->done);
        user = user->next;
    }
}

void print_fe(TBase * base) {
    printf("FE -> ");
    printq(base->FE);
    printf("\n");
}