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

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"tipos.h"
#include"fila.h"
#include"lprioridade.h"
#include"lusuario.h"
#include"tarefa.h"
#include "base.h"

    TBase * start_base(void);

    void arrange(TBase * base);

    void printform_tasks(TQueue * q);

    void printform_user(char * name, TQueue * q);

    void printform_priority(int priority, TQueue * q);

    void printform_prioritylist(PriorityList * plist);

    void print_user(TUser * user);

    void print_users(TBase * base);

    void print_fe(TBase * base);

    void print_ftr(TBase * base);

    void print_fpso(TBase * base);

    void print_fu(TBase * base);

    void freebase(TBase * base);


#ifdef	__cplusplus
}
#endif

#endif	/* BASE_H */

