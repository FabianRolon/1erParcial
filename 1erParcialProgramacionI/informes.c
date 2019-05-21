#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//#include <stdio_ext.h>
#include <ctype.h>
#include "instrumento.h"
#include "orquesta.h"
#include "musico.h"
#include "informes.h"
#include "utn.h"

/** \brief Ordena por campo XXXXX los elementos de un array ante la igualdad de estos ordena por el campo ZZZZZZ
* \param array musico Array de musico
* \param size int Tamaño del array
* \param orderFirst int Determina si el orden del primer criterio es ascendete o descendente
* \param orderSecond int Determina si el orden del segunbdo criterio es ascendete o descendente
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int musico_ordenarPorDobleCriterio(Musico *arrayMusico,int size, int orderFirst, int orderSecond)                              //cambiar musico
{
    int retorno=-1;
    int i;
    Musico buffer;
    int flagSwap;

    if(arrayMusico!=NULL && size>=0)
    {
        do
        {
            flagSwap=0;
            for (i = 1; i < size-1; i++)
            {
                if( ((strcmp(arrayMusico[i].nombre,arrayMusico[i+1].nombre) < 0) && orderFirst) ||
                    ((strcmp(arrayMusico[i].nombre,arrayMusico[i+1].nombre) > 0) && !orderFirst) )
                {
                    flagSwap=1;
                    buffer = arrayMusico[i];
                    arrayMusico[i] = arrayMusico[i+1];
                    arrayMusico[i+1] = buffer;
                }
                else if(strcmp(arrayMusico[i].nombre,arrayMusico[i+1].nombre) == 0)
                {
                    if( ((arrayMusico[i].apellido < arrayMusico[i+1].apellido) && orderSecond) ||
                        ((arrayMusico[i].apellido > arrayMusico[i+1].apellido) && !orderSecond) )
                    {
                        flagSwap=1;
                        buffer = arrayMusico[i];
                        arrayMusico[i] = arrayMusico[i+1];
                        arrayMusico[i+1] = buffer;
                    }
                }
            }
        }while(flagSwap);
        retorno=0;
    }
    return retorno;
}

int inf_contadorMusicosOrquesta(ContadorMusicos *arrayContadorMusicos, Orquesta *arrayOrquesta, Musico *arrayMusico, int cantidadMusico, int cantidadOrquesta)
{
    int retorno = -1;
    int i;
    int j;
    int posicionArrayContador = 0;

    if(arrayContadorMusicos != NULL && arrayMusico != NULL && arrayOrquesta != NULL)
    {
        for(i = 0; i<cantidadOrquesta; i++)
        {
            if(arrayOrquesta[i].isEmpty == 0)
            {
                arrayContadorMusicos[posicionArrayContador].idOrquesta = arrayOrquesta[i].idOrquesta;

                for(j = 0;j<cantidadMusico;j++)
                {
                    if(arrayMusico[j].isEmpty == 0 && arrayContadorMusicos[posicionArrayContador].idOrquesta == arrayMusico[j].idOrquesta)
                    {
                        arrayContadorMusicos[posicionArrayContador].cantMusico++;
                    }
                }
                posicionArrayContador++;
            }

        }
        retorno = 0;
    }
    return retorno;
}
