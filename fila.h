/* 
 * File:   fila.h
 * Author: proto
 *
 * Created on 12 de Novembro de 2012, 23:41
 */

#ifndef FILA_H
#define	FILA_H

#ifdef	__cplusplus
extern "C" {
#endif

#include"tipos.h"

void printq(TQueue * q);

void releaseq(TQueue * q);

TQueue * initializeq(void);

void push(TQueue * q, Task * t);

Task * pop(TQueue * q);

int emptyq(TQueue * q);



#ifdef	__cplusplus
}
#endif

#endif	/* FILA_H */

