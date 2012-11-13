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

TUser * _createu(TUser * ulist, char * name, int grant);

TUser * finduser( TUser *ulist, char *name);
TUser * adduser(TUser * ulist, char * name);

TUser * initializeuser(void);


#ifdef	__cplusplus
}
#endif

#endif	/* LUSUARIO_H */

