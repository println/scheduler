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

void arrange(TBase * base);

void printform_tasks(TQueue * q);

void printform_user(char * name, TQueue * q);

void printform_priority(int priority, TQueue * q);

void printform_prioritylist(PriorityList * plist);

void print_fe(TBase * base);

void print_user(TUser * user);

void print_users(TBase * base);

void print_ok();

#ifdef	__cplusplus
}
#endif

#endif	/* BASE_H */

