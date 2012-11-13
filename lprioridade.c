#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"tipos.h"
#include"fila.h"
#include "lprioridade.h"

PriorityList * _createp(PriorityList * plist, int priority) {//insere ordenado
    PriorityList * item = (PriorityList*) malloc(sizeof (PriorityList));

    item->priority = priority;
    item->tasks = initializeq();
    item->next = NULL;

    if (!plist)
        return item;

    PriorityList * tmp = plist;
    PriorityList * ant;
    while (tmp && tmp->priority <= priority) {
        ant = tmp;
        tmp = tmp->next;
    }

    if (ant) {
        ant->next = item;
        item->next = tmp;
    } else
        item->next = tmp;

    return item;
}

PriorityList * searchp(PriorityList *plist, int priority) {

    PriorityList * tmp = plist;

    while (tmp) {
        if (tmp->priority == priority)
            return tmp;
        tmp = tmp->next;
    }

    return NULL;
}

PriorityList * insertp(PriorityList * plist, int priority) {
    if (!plist)
        return NULL;

    PriorityList * user = searchp(plist, priority);
    if (!user)
        user = _createp(plist, priority);

    return user;
}

PriorityList * initializep(void) {
    return _createp(NULL, -1);
}

PriorityList * removep(PriorityList * plist, int priority) {

    if (!plist)
        return NULL;

    PriorityList * tmp = searchp(plist, priority);

    if (tmp) {
        PriorityList * p = plist, * ant = NULL, * newlist;
        while (p && p != tmp) {
            ant = p;
            p = p->next;
        }
        
        newlist = plist;
        
        if (ant)
            ant->next = p->next;
        else
            newlist = p->next;
        
        while(!emptyq(tmp->tasks))
            pop(tmp->tasks);
        
        if(emptyq(tmp->tasks))
            releaseq(tmp->tasks);
        
        free(tmp);
        
        return newlist;
    }
    return NULL;
}

int emptyp(PriorityList * plist) {
    return emptyq(plist->tasks);
}


