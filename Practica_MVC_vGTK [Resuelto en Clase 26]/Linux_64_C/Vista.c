#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "Socio.h"
#include "ArrayList.h"
#include "Vista.h"
#include "Controlador.h"
#include "servicios.h"



static int idiomaVista = VISTA_IDIOMA_ES;

static void opcionAlta();
static void opcionBaja();
static void opcionModificacion();
static void opcionListado();

// Opciones Servicios

static void opcionAltaServicio();
static void opcionBajaServicio();
static void opcionModificacionServicio();
static void opcionListadoServicio();






int vista_init (int idioma)
{
    idiomaVista = idioma;
    return 0;
}

int vista_mostrarMenu()
{
    char buffer[10];
    int option=0;

    while(option != 9)
    {
        val_getInt(buffer, MENU_PPAL_ES, MENU_PPAL_ERROR_ES,2,5);
        option = atoi(buffer);

        switch(option)
        {
            case 1:
                opcionListado();
                break;
            case 2:
                opcionAlta();
                break;
            case 3:
                opcionBaja();
                break;
            case 4:
                opcionModificacion();
                break;
            case 5:
                opcionAltaServicio();
                break;
            case 6:
                opcionBajaServicio();
                break;
            case 7:
                opcionModificacionServicio();
                break;
            case 8:
                opcionListadoServicio();
                break;
        }
    }

    return 0;
}

void vista_mostrarSocios(ArrayList* pListaSocios)
{
    int i;
    Socio* auxSocio;
    for(i=0;i<al_len(pListaSocios);i++)
        {
            auxSocio=al_get(pListaSocios,i);
            if(auxSocio->estado==SOCIO_ESTADO_ACTIVO)
            {
            auxSocio = al_get(pListaSocios,i);
            printf("NOMBRE: %s - APELLIDO: %s- ID: %d - DNI: %s\n",soc_getNombre(auxSocio),
                            soc_getApellido(auxSocio),soc_getId(auxSocio),soc_getDni(auxSocio));
            }
        }

}

void vista_mostrarServicios(ArrayList* pListaServicios)
{
    int i;
    Servicio* auxServicio;
    for(i=0;i<al_len(pListaServicios);i++)
        {
            auxServicio=al_get(pListaServicios,i);
            if(auxServicio->estado==SOCIO_ESTADO_ACTIVO)
            {
            auxServicio = al_get(pListaServicios,i);
            printf("DESCRIPCION: %s -  ID: %d - \n",serv_getDescripcion(auxServicio),
                            serv_getId(auxServicio));
            }
        }

}








void mostrarError(char *);

static void opcionAlta()
{
    char auxNombre[50];
    char auxApellido[50];
    char auxDni[50];
    val_getString(auxNombre, "Nombre? ", "Error",2,50);
    val_getString(auxApellido, "Apellido? ", "Error",2,50);
    val_getInt(auxDni, "DNI? ", "Error",2,50);
    cont_altaSocio(auxNombre,auxApellido,auxDni);

}

static void opcionAltaServicio()
{
    char auxDescripcion[50];
    val_getString(auxDescripcion, "Detalle del servicio? ", "Error",2,50);
    cont_altaServicio(auxDescripcion);

}


static void opcionBaja()
{
    char auxId[10];
    int id;

    if((val_getUnsignedInt(auxId,"Id a dar de baja" , "Error",2,10)==0))
    {
        id = atoi(auxId);
        cont_bajaSocio(id);
    }

}



static void opcionBajaServicio()
{
    char auxId[10];
    int id;

    if((val_getUnsignedInt(auxId,"Id de Servicio a dar de baja" , "Error",2,10)==0))
    {
        id = atoi(auxId);
        cont_bajaServicio(id);
    }

}

static void opcionModificacion()
{
    char auxId[10];
    int id;
    int estado;
    char auxNombre[50];
    char auxApellido[50];
    char auxDni[50];
    char auxEstado[5];

    if((val_getUnsignedInt(auxId,"Id a modificar" , "Error",2,10)==0))
    {
        id = atoi(auxId);
        if(val_getString(auxNombre, "Nombre? ", "Error",2,50)==0)
        {
            if(val_getString(auxApellido, "Apellido? ", "Error",2,50)==0)
            {
                if(val_getInt(auxDni, "DNI? ", "Error",2,50)==0)
                {
                    if(val_getUnsignedInt(auxEstado,"Estado?\nACTIVO= 0\nINACTIVO= 1", "Error",2,5)==0)
                    {
                        estado=atoi(auxEstado);
                        if(estado == 0 || estado == 1)
                        {
                            cont_modificarSocio(auxNombre,auxApellido,auxDni,id,estado);
                        }

                    }

                }
            }

        }

    }

}
static void opcionModificacionServicio()
{
    char auxId[10];
    int id;
    int estado;
    char auxDescripcion[50];
    char auxEstado[5];

    if((val_getUnsignedInt(auxId,"Id de Servicio a modificar", "Error",2,10)==0))
    {
        id = atoi(auxId);
        if(val_getString(auxDescripcion, "Detalle del servicio? ", "Error",2,50)==0)
        {
            if(val_getUnsignedInt(auxEstado,"Estado?\nACTIVO= 0\nINACTIVO= 1", "Error",2,5)==0)
            {
                estado=atoi(auxEstado);
                if(estado == 0 || estado == 1)
                {
                    cont_modificarServicio(auxDescripcion,id,estado);
                }

            }

        }
    }

}





static void opcionListado()
{
    cont_listarSocios();
}

static void opcionListadoServicio()
{
    cont_listarServicios();
}
