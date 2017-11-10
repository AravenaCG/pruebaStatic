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
