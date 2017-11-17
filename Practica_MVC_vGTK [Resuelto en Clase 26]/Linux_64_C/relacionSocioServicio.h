#include "ArrayList.h"
#ifndef RELACIONSOCIOSERVICIO_H_INCLUDED
#define RELACIONSOCIOSERVICIO_H_INCLUDED


typedef struct
{
    int idRelacion;
    int idSocio;
    int idServicio;
    int estado;
}RelacionSS;

#endif // RELACIONSOCIOSERVICIO_H_INCLUDED

#define RELACION_ESTADO_ACTIVO 0
#define RELACION_ESTADO_INACTIVO 1



RelacionSS* relSS_new(int idRelacion, int idSocio, int idServicio, int estado);
int relSS_setIdRelacion(RelacionSS* this,int idRelacion);
int relSS_getIdRelacion(RelacionSS* this);
int relSS_setIdSocio(RelacionSS* this,int idSocio);
int relSS_getIdSocio(RelacionSS* this);
int relSS_setIdServicio(RelacionSS* this,int idServicio);
int relSS_getIdServicio(RelacionSS* this);
int relSS_setEstado(RelacionSS* this,int estado);
int relSS_getEstado(RelacionSS* this);
int relSS_delete(RelacionSS*);
RelacionSS* relSS_findbyIdSocioServicio(ArrayList* ,  int idRelacion, int idSocio, int idServicio);

