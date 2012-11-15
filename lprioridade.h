/* 
 * File:   lprioridade.h
 * Author: proto
 *
 * Created on 12 de Novembro de 2012, 23:45
 */

#ifndef LPRIORIDADE_H
#define	LPRIORIDADE_H

#ifdef	__cplusplus
extern "C" {
#endif


PriorityList * initializep(void);

int emptyp(PriorityList * plist);

void addtask(PriorityList * plist, Task * task);

Task * toptask(PriorityList * plist);

void dropp(PriorityList * plist);

void releasep(PriorityList * plist);

#ifdef	__cplusplus
}
#endif

#endif	/* LPRIORIDADE_H */

