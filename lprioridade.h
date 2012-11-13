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
PriorityList * create_priority(PriorityList * plist, int priority);

PriorityList * get_priority( PriorityList *plist, int priority);

PriorityList * set_priority(PriorityList * plist, int priority);
PriorityList * initialize_prioritylist(void);





#ifdef	__cplusplus
}
#endif

#endif	/* LPRIORIDADE_H */

