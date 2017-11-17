#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Socio.h"
#include "servicios.h"
#include "relacionSocioServicio.h"



RelacionSS* relSS_new(int idRelacion, int idSocio, int idServicio, int estado)
{
    RelacionSS* nuevaRelacion = malloc(sizeof(RelacionSS));
    relSS_setIdRelacion(nuevaRelacion, idRelacion);
    relSS_setIdSocio(nuevaRelacion,idSocio);
    relSS_setIdServicio(nuevaRelacion,idServicio);
    relSS_setEstado(nuevaRelacion,estado);


    return nuevaRelacion;
}


int relSS_delete(RelacionSS* this)
{
    free(this);
    return 0;
}

//ID RELACION
int relSS_setIdRelacion(RelacionSS* this,int idRelacion)
{

    this->idRelacion = idRelacion;
    return 0;
}

int relSS_getIdRelacion(RelacionSS* this)
{
    return this->idRelacion;
}

//ID SOCIO

int relSS_setIdSocio(RelacionSS* this,int idSocio)
{

    this->idSocio = idSocio;
    return 0;
}

int relSS_getIdSocio(RelacionSS* this)
{
    return this->idSocio;
}


//ID SERVICIOS_H_INCLUDED

int relSS_setIdServicio(RelacionSS* this,int idServicio)
{

    this->idServicio = idServicio;
    return 0;
}

int relSS_getIdServicio(RelacionSS* this)
{
    return this->idServicio;
}


int relSS_setEstado(RelacionSS* this,int estado)
{

    this->estado = estado;
    return 0;
}

int relSS_getEstado(RelacionSS* this)
{
    return this->estado;
}

RelacionSS* relSS_findByIdSocioServicio(ArrayList* pArrayRelaciones, int idSocio, int idServicio)
{
    int i;
    Socio *auxRelacion;
    void* retorno=NULL;

    for(i=0;i<al_len(pArrayRelaciones);i++)
    {
        auxRelacion = al_get(pArrayRelaciones,i);
        if(idSocio == relSS_getIdSocio(auxRelacion) && idServicio == relSS_getIdRelacion(auxRelacion) )
        {
            retorno = auxRelacion;
            break;
        }
    }

    return retorno;
}




