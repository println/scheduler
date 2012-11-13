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
PriorityList * _createp(PriorityList * plist, int priority);

PriorityList * searchp( PriorityList *plist, int priority);

PriorityList * insertp(PriorityList * plist, int priority);

PriorityList * initializep(void);

int emptyp(PriorityList * plist);



#ifdef	__cplusplus
}
#endif

#endif	/* LPRIORIDADE_H */

