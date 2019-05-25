#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <ctype.h>
#include "instrumento.h"
#include "utn.h"

int ins_Inicializar(Instrumento *arrayInstrumento, int cantidad)
{
    int retorno = -1;
    int i;

    for (i = 0; i < cantidad; i++)
    {
        arrayInstrumento[i].isEmpty = 1;
        retorno=0;
    }

    return retorno;
}

int ins_buscarLibre(Instrumento *arrayInstrumento, int cantidad, int *devuelve)
{
    int retorno=-1;
    for (int i=0; i<cantidad;i++)
    {
        if (arrayInstrumento[i].isEmpty==1)
        {
            *devuelve=i;
            retorno=0;
            break;
        }

        retorno=1;
    }

    return retorno;
}

int ins_alta(Instrumento *arrayInstrumento, int cantidad, int posLibre, int id)
{
    int retorno = -1;

    if (    utn_getName("\n\nIngrese el nombre del instrumento: ","Error, vuelva a ingresar\n\n",2,30,2, arrayInstrumento[posLibre].nombre) == 0)

        {
            printf("\n\n1-Cuerdas");
            printf("\n\n2-Viento-madera");
            printf("\n\n3-viento-metal");
            printf("\n\n4-Percusion");
            if(utn_getUnsignedInt("\n\nIngrese el tipo de instrumento: ","Error, vuelva a ingresar\n\n",1,4,2,&arrayInstrumento[posLibre].tipo) == 0)
            {

                arrayInstrumento[posLibre].idInstrumento = id;
                arrayInstrumento[posLibre].isEmpty  = 0;
                retorno=0;

            }
        }

    else
    {
        retorno = 1;
    }

    return retorno;
}

int ins_buscarEnArrayPorId (Instrumento *arrayInstrumento, int idInstrumento, int cantidad, int *instrumentoEncontrado)
{
    int i;
    int retorno = 1;

        for(i=0; i < cantidad; i++)
        {
            if (arrayInstrumento[i].idInstrumento == idInstrumento)
            {
                retorno=0;
                *instrumentoEncontrado=i;
                break;
            }
        }

    return retorno;
}


void ins_mostrarArray(Instrumento *arrayInstrumento, int cantidad)
{
    int i;

    printf("\n\n\t\t\t\t||Lista de Instrumentos||\n\n");

    for (i = 0; i < cantidad ;i++)
    {
        if(arrayInstrumento[i].isEmpty == 0)
        {

            printf("\nID de Instrumento: %d\n", arrayInstrumento[i].idInstrumento);
            printf("Posicion: %d\n", i);
            printf("Estado: %d\n", arrayInstrumento[i].isEmpty);
            printf("Nombre: %s\n", arrayInstrumento[i].nombre);
            switch(arrayInstrumento[i].tipo)
            {
                case 1:
                    printf("Tipo: 1-Cuerdas\n");
                    break;
                case 2:
                    printf("Tipo: 2-Viento-madera\n");
                    break;
                case 3:
                    printf("Tipo: 3-Viento-metal\n");
                    break;
                case 4:
                    printf("Tipo: 4-Percusion\n");
                    break;
            }


        }
    }
}



int ins_existeId (Instrumento *arrayInstrumento, int cantidad, int id)
{
    int i;
    int retorno = 1;

        for(i=0; i < cantidad; i++)
        {
            if (arrayInstrumento[i].idInstrumento == id)
            {
                retorno=0;
                break;
            }
        }
    return retorno;
}

