#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Socio.h"
#include "Vista.h"
#include "DataManager.h"
#include "servicios.h"
#include "relacionSocioServicio.h"

static ArrayList* nominaSocios;
static int proximoIdSocio=0;
static int getNewId();
static int setNewId(int id);
static int getNewIdServicio();
static int setNewIdServicio(int id);
static int setNewIdRelacion(int idRelacion);
static int getNewIdRelacion();


static ArrayList* nominaServicios;
static int proximoIdServicio=0;
static int getNewIdServicio();
static int setNewId(int idServicio);

static ArrayList* nominaInscriptos;
static int proximoIdRelacion=0;
static int getNewIdRelacion();
static int setNewIdRelacion(int idRelacion);

void cont_init()
{
    nominaSocios = al_newArrayList();
    nominaServicios = al_newArrayList();
    nominaInscriptos = al_newArrayList();

    setNewIdRelacion(dm_readAllRelacion(nominaInscriptos)+1);
    setNewIdServicio(dm_readAllServicios(nominaServicios)+1);
    setNewId(dm_readAll(nominaSocios) + 1);

    vista_init(VISTA_IDIOMA_ES);
    vista_mostrarMenu();
}

int cont_altaSocio (char* nombre,char* apellido,char* dni)
{
    Socio* auxSocio;
    auxSocio = soc_new(nombre,apellido,dni,getNewId(),SOCIO_ESTADO_ACTIVO);
    al_add(nominaSocios,auxSocio);
    dm_saveAll(nominaSocios);
    return 0;
}

int cont_altaServicio (char* descripcion)
{
    Servicio* auxServicio;
    auxServicio = serv_new(descripcion,getNewIdServicio(),SERVICIO_ESTADO_ACTIVO);
    al_add(nominaServicios,auxServicio);
    dm_saveAllServicios(nominaServicios);
    return 0;
}

int cont_altaRelacion (int* idRelacion, int* idSocio, int* idServicio)
{
    int retorno=-1;

    RelacionSS* auxRelacion;
    if ( relSS_findByIdSocioServicio(auxRelacion,idSocio,idServicio) == NULL)
    {
    auxRelacion = relSS_new(idRelacion,idSocio,idServicio,RELACION_ESTADO_ACTIVO);
    al_add(nominaInscriptos,auxRelacion);
    dm_saveAllRelacion(nominaInscriptos);
    retorno=0;
    }
    else
    {
       retorno=-2;
    }
    return retorno;
}




int cont_bajaSocio (int id)
{
    Socio* auxSocio;
    auxSocio=soc_findById(nominaSocios,id);
    if(auxSocio!=NULL)
    {
        soc_setEstado(auxSocio,SOCIO_ESTADO_INACTIVO);
        dm_saveAll(nominaSocios);
    }

    return 0;
}



int cont_bajaServicio(int id)
{
    Servicio* auxServicio;
    auxServicio=serv_findById(nominaServicios,id);
    if(auxServicio!=NULL)
    {
        serv_setEstado(auxServicio,SERVICIO_ESTADO_INACTIVO);
        dm_saveAllServicios(nominaServicios);
    }

    return 0;
}




int cont_modificarSocio (char* nombre,char* apellido,char* dni, int id, int estado)
{
    Socio* auxSocio;

    auxSocio=soc_findById(nominaSocios,id);

    if(auxSocio!=NULL)
    {
        soc_setNombre(auxSocio,nombre);
        soc_setApellido(auxSocio,apellido);
        soc_setDni(auxSocio,dni);
        soc_setEstado(auxSocio,estado);
        dm_saveAll(nominaSocios);
    }

    return 0;
}

int cont_modificarServicio (char* descripcion, int id, int estado)
{
    Servicio* auxServicio;

    auxServicio=serv_findById(nominaServicios,id);

    if(auxServicio!=NULL)
    {
        serv_setDescripcion(auxServicio,descripcion);
        serv_setEstado(auxServicio,estado);
        dm_saveAllServicios(nominaServicios);
    }

    return 0;
}








int cont_listarSocios ()
{
    vista_mostrarSocios(nominaSocios);
    return 0;
}


int cont_listarServicios ()
{
    vista_mostrarServicios(nominaServicios);
    return 0;
}

//SETTER-GETTER ID SOCIO
static int getNewId()
{
    return proximoIdSocio++;
}

static int setNewId(int id)
{
    proximoIdSocio = id;
    return 0;
}

//SETTTER-GETTER ID SERVICIO
static int getNewIdServicio()
{
    return proximoIdServicio++;
}

static int setNewIdServicio(int id)
{
    proximoIdServicio = id;
    return 0;
}


//SETTER-GETTER ID RELACION


static int getNewIdRelacion()
{
    return proximoIdRelacion++;
}

static int setNewIdRelacion(int idRelacion)
{
    proximoIdRelacion = idRelacion;
    return 0;
}


