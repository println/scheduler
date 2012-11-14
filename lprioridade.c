
#include "tipos.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"tipos.h"
#include"fila.h"
#include "lprioridade.h"

TPriority * _contains(TPriority *prio, int priority) {

    TPriority * tmp = prio;

    while (tmp) {
        if (tmp->priority == priority)
            return tmp;
        tmp = tmp->next;
    }

    return NULL;
}

TPriority * _create(int priority) {
    TPriority * item = (TPriority*) malloc(sizeof (TPriority));
    item->priority = priority;
    item->tasks = initializeq();
    item->next = NULL;
    return item;

}

void _insert(PriorityList * plist, Task * task) {//insere ordenado

    if (!plist->priorities) {

        TPriority * p = _create(task->priority);
        push(p->tasks, task);
        plist->priorities = p;

    } else {

        TPriority * p = _contains(plist->priorities, task->priority);

        if (p)
            push(p->tasks, task);
        else {

            TPriority * tmp = plist->priorities;
            TPriority * ant = NULL;

            while (tmp && tmp->priority < task->priority) {
                ant = tmp;
                tmp = tmp->next;
            }

            p = _create(task->priority);
            push(p->tasks, task);

            if (ant) {
                ant->next = p;
                p->next = tmp;
            } else {
                p->next = tmp;
                plist->priorities = p;
            }
        }
    }
}

void * _removepriority(PriorityList * plist, TPriority * prio) {
    if (!prio || !plist)
        return;

    TPriority * p = plist->priorities, * ant = NULL;


    while (p && p != prio) {
        ant = p;
        p = p->next;
    }

    if (ant)
        ant->next = p->next;
    else {
        if (p->next)
            plist->priorities = p->next;
        else
            plist->priorities = NULL;
    }
    dropq(prio->tasks);


    free(prio);

}

int _remove(PriorityList * plist, Task * task) {

    if (!plist->priorities)
        return 0;

    TPriority * p = _contains(plist->priorities, task->priority);

    if (!p)
        return 0;

    TQueue * q = initializeq();

    while (!emptyq(p->tasks)) {
        Task * temp = pop(p->tasks);
        if (temp != task)
            push(q, temp);
    }



    if (emptyq(q)) {
        _removepriority(plist, p);
        q = NULL;
    }

    p->tasks = q;

    return 1;

}

PriorityList * initializep(void) {
    PriorityList * pl = (PriorityList*) malloc(sizeof (PriorityList));
    pl->priorities = NULL;
    return pl;
}

int emptyp(PriorityList * plist) {
    return (plist->priorities == NULL);
}

void addtask(PriorityList * plist, Task * task) {
    _insert(plist, task);
}

Task * toptask(PriorityList * plist) {

    if (plist && plist->priorities && !emptyq(plist->priorities->tasks)) {
        Task * task = pop(plist->priorities->tasks);
        _remove(plist, task);
        return task;
    }
    return NULL;

}

