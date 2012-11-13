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

TUser * create_user(TUser * ulist, char * name, int grant);

TUser * get_user( TUser *ulist, char *name);
TUser * set_user(TUser * ulist, char * name);

TUser * initialize_userlist(void);


#ifdef	__cplusplus
}
#endif

#endif	/* LUSUARIO_H */

