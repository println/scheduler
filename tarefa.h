/* 
 * File:   tarefa.h
 * Author: proto
 *
 * Created on 13 de Novembro de 2012, 16:22
 */

#ifndef TAREFA_H
#define	TAREFA_H

#ifdef	__cplusplus
extern "C" {
#endif
    
int execute(Task * task);

int newtask(TBase * base, char * username, int priority, char * cmd);


#ifdef	__cplusplus
}
#endif

#endif	/* TAREFA_H */

