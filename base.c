#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"tipos.h"
#include"fila.h"
#include"lprioridade.h"
#include"lusuario.h"
#include"tarefa.h"
#include "base.h"

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

void printform_tasks(TQueue * q) {
    if (!emptyq(q)) {
        printf(" -> ");
        printq(q);
        printf("\n");
    }
}

void printform_user(char * name, TQueue * q) {
    printf("%s", name);
    printform_tasks(q);
}

void printform_priority(int priority, TQueue * q) {
    printf("|-%i", priority);
    printform_tasks(q);
}

void printform_prioritylist(PriorityList * plist) {
    TPriority * tmp = plist->priorities;
    while (tmp) {
        printform_priority(tmp->priority, tmp->tasks);
        tmp = tmp->next;
    }
}

void print_user(TUser * user) {
    printf("*%s\n", user->id);
    if (!emptyp(user->waiting)) {
        printf("Nao executados:\n");
        printform_prioritylist(user->waiting);
    }
    if (!emptyq(user->done)) {
        printf("Executados:");
        printform_tasks( user->done);
    }
    printf("-----------------\n");
}

void print_users(TBase * base) {
    TUser * user = base->users;
    while (user) {
        print_user(user);
        user = user->next;
    }
}

void print_fe(TBase * base) {
    printf("FE -> ");
    printq(base->FE);
    printf("\n");
}

void print_ftr(TBase * base) {
    printf("FTR -> ");
    printq(base->FTR);
    printf("\n");
}

void print_fpso(TBase * base) {
    printf("FPSO -> ");
    printq(base->FPSO);
    printf("\n");
}

void print_fu(TBase * base) {
    printf("FU");
    if(!emptyp(base->FU))
        printf("\n");
    printform_prioritylist(base->FU);
}

void freebase(TBase * base){
    dropq(base->FE);
    dropq(base->FPSO);
    dropq(base->FTR);
    dropp(base->FU);
    releaseu(base->users);
}
