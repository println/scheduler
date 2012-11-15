/* 
 * File:   filas.h
 * Author: proto
 *
 * Created on 13 de Novembro de 2012, 11:49
 */

#ifndef FILAS_H
#define	FILAS_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct user {
        char id[80];
        struct prioritylist * waiting;
        struct queue * done;
        struct user * next;
    } TUser;

    typedef struct prioritylist {
        struct prio * priorities;
    }PriorityList;
    
    typedef struct prio {
        int priority;
        struct queue * tasks;
        struct prio * next;
    }TPriority;
    
    typedef struct task {
        /**
         * TUser do dono o processo
         */
        TUser * owner;
        /**
         * ID do processo no sistema
         */
        unsigned int pid;
        /**
         * Prioridade de execucao do processo
         */
        int priority;
        /**
         * Comando para a ser executado pelo system
         */
        char cmd[80];
    } Task;

    typedef struct node {
        Task * info;
        struct node * next;
    } TNode;

    typedef struct queue {
        TNode * begin;
        TNode * end;
    } TQueue;
    
    
    /**
    * Estrutura para a referencia base do sistema
    */
    typedef struct base {
        /**
         * Contador de ID de processo
         */
        unsigned int pid; 
        /**
         * Lista todos os usuarios que entraram com comando
         */
        TUser * users;
        /**
         * Fila de entrada de processos
         */
        TQueue * FE;
        /**
         * Lista de processos organizados por prioridade
         */
        PriorityList * FU;
        /**
         * Fila de processos prontos de tempo-real
         */
        TQueue * FTR;
        /**
         * Fila de todos os processos executados no sistema o operacional
         */
        TQueue * FPSO;        
        
    } TBase;



#ifdef	__cplusplus
}
#endif

#endif	/* FILAS_H */

