/* 
 * File:   lusuario.h
 * Author: proto
 *
 * Created on 12 de Novembro de 2012, 23:47
 */

#ifndef LUSUARIO_H
#define	LUSUARIO_H

#ifdef	__cplusplus
extern "C" {
#endif

TUser * finduser( TUser *ulist, char *name);

TUser * adduser(TUser * ulist, char * name);

TUser * initializeuser(void);

void releaseu(TUser * user);

#ifdef	__cplusplus
}
#endif

#endif	/* LUSUARIO_H */

