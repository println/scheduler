/* 
 * File:   base.h
 * Author: proto
 *
 * Created on 12 de Novembro de 2012, 23:31
 */

#ifndef BASE_H
#define	BASE_H

#ifdef	__cplusplus
extern "C" {
#endif

#include"tipos.h"

TBase * start_base(void);

void waiting_for(Task * task);

void to_done(Task * task);

void spool(TBase * base, Task * task);

void printform_tasks(TQueue * q);

void printform_user(char * name,TQueue * q);

void printform_priority(int priority,TQueue * q);

void printform_userpriority(char * name,PriorityList * plist);

void print_waiting(TBase * base);

void print_done(TBase * base);

void print_fe(TBase * base);



#ifdef	__cplusplus
}
#endif

#endif	/* BASE_H */

