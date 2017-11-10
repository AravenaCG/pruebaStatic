#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Socio.h"
#include "DataManager.h"


int dm_saveAll(ArrayList* pListaSocios)
{
    int retorno=-1;
    Socio* buffListSocio= NULL;
    FILE* pArchivo;
    pArchivo = fopen(ARCHIVO_SOCIOS, "wb");
    int i=0;
    if (pArchivo!=NULL)
    {
        for (i=0;i<al_len(pListaSocios);i++)

        buffListSocio = al_get(pListaSocios,i);
        fwrite(buffListSocio, sizeof(Socio),1,pArchivo);
        retorno=0;
    }
    fclose(pArchivo);
return retorno;
}

int dm_readAll(ArrayList* pListaSocios)
{
    int retornoIdMasAlto=0;

    FILE* pArchivo;
    Socio buffSocio;
    Socio* pSocio;
    pArchivo = fopen(ARCHIVO_SOCIOS, "rb");
    int max=-1;
    if (pArchivo!=NULL)
    {

        do{
            if (fread(&buffSocio,sizeof(Socio),1,pArchivo)==1)
            {
                pSocio = soc_new(buffSocio.nombre,buffSocio.apellido,buffSocio.dni,buffSocio.id,SOCIO_ESTADO_ACTIVO);
                al_add(pListaSocios,pSocio);
                if (buffSocio.id>max)
                {
                    retornoIdMasAlto = buffSocio.id;
                }
            }
          }while(!feof(pArchivo));



    }
    return retornoIdMasAlto;
}
