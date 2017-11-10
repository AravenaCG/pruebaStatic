#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Socio.h"
#include "Vista.h"
#include "Controlador.h"


static ArrayList* nominaSocios;
static int proximoIdSocio=0;
static int getNewId();
static int setNewId(int id);

void cont_init()
{
    nominaSocios = al_newArrayList();
    setNewId(0);
    vista_init(VISTA_IDIOMA_ES);
    vista_mostrarMenu();
}

int cont_altaSocio (char* nombre,char* apellido,char* dni)
{
    Socio* auxSocio;
    auxSocio = soc_new(nombre,apellido,dni,getNewId(),SOCIO_ESTADO_ACTIVO);
    al_add(nominaSocios,auxSocio);
    return 0;
}

int cont_bajaSocio (int id)
{
    //comprobar con retorno en vista el valor y devolver un mensaje de ok o de error segun corresponda
    int retorno=0;
    Socio* auxSocio= NULL;

    auxSocio = soc_findById(nominaSocios,id);
    if (auxSocio != NULL)
    {

        soc_setEstado(auxSocio,SOCIO_ESTADO_INACTIVO);
    }


    return retorno;
}


int cont_modificarSocio (char* nombre,char* apellido,char* dni, int id)
{
    int retorno=0;
    Socio* auxSocio= NULL;

    auxSocio = soc_findById(nominaSocios,id);
    if (auxSocio != NULL)
    {

        soc_setNombre(auxSocio,nombre);
        soc_setApellido(auxSocio,apellido);
        soc_setDni(auxSocio,dni);

    }


    return retorno;
}

int cont_listarSocios ()
{
    vista_mostrarSocios(nominaSocios);
    return 0;
}


static int getNewId()
{
    return proximoIdSocio++;
}

static int setNewId(int id)
{
    proximoIdSocio = id;
    return 0;
}

void* cont_findSocio(int id)
{
    Socio* auxSocio= NULL;


    if (soc_findById(nominaSocios,id) !=  NULL)
    {
        auxSocio=soc_findById(nominaSocios,id);

    }
    return auxSocio;
}
