#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <ctype.h>
#include "instrumento.h"
#include "orquesta.h"
#include "musico.h"
#include "informes.h"
#include "utn.h"
#define CANTIDAD_ORQUESTA 50
#define CANTIDAD_INSTRUMENTO 20
#define CANTIDAD_MUSICO 1000

void harcodeo(Orquesta *orquesta, Instrumento *instrumento, Musico *musico, int *generadorCodigoOrquesta, int *generadorCodigoInstrumento,  int *generadorCodigoMusico)
{
    orquesta[0].idOrquesta=1;
    orquesta[0].isEmpty=0;
    strcpy(orquesta[0].nombre,"Orquesta1");
    strcpy(orquesta[0].lugar,"LugarUno");
    orquesta[0].tipo = 1;
    generadorCodigoOrquesta++;

    orquesta[1].idOrquesta=2;
    orquesta[1].isEmpty=0;
    strcpy(orquesta[1].nombre,"Orquesta2");
    strcpy(orquesta[1].lugar,"LugarUno");
    orquesta[1].tipo = 2;
    generadorCodigoOrquesta++;

    orquesta[2].idOrquesta=3;
    orquesta[2].isEmpty=0;
    strcpy(orquesta[2].nombre,"Orquesta3");
    strcpy(orquesta[2].lugar,"LugarDos");
    orquesta[2].tipo = 3;
    generadorCodigoOrquesta++;

    orquesta[3].idOrquesta=4;
    orquesta[3].isEmpty=0;
    strcpy(orquesta[3].nombre,"Orquesta4");
    strcpy(orquesta[3].lugar,"LugarTres");
    orquesta[3].tipo = 2;
    generadorCodigoOrquesta++;

    instrumento[0].idInstrumento=1;
    instrumento[0].isEmpty=0;
    strcpy(instrumento[0].nombre,"Instr1");
    instrumento[0].tipo = 1;
    generadorCodigoInstrumento++;

    instrumento[1].idInstrumento=2;
    instrumento[1].isEmpty=0;
    strcpy(instrumento[1].nombre,"Instr2");
    instrumento[1].tipo = 2;
    generadorCodigoInstrumento++;

    instrumento[2].idInstrumento=3;
    instrumento[2].isEmpty=0;
    strcpy(instrumento[2].nombre,"Instr3");
    instrumento[2].tipo = 2;
    generadorCodigoInstrumento++;

    instrumento[3].idInstrumento=4;
    instrumento[3].isEmpty=0;
    strcpy(instrumento[3].nombre,"Instr4");
    instrumento[3].tipo = 3;
    generadorCodigoInstrumento++;

    instrumento[4].idInstrumento=5;
    instrumento[4].isEmpty=0;
    strcpy(instrumento[4].nombre,"Instr5");
    instrumento[4].tipo = 4;
    generadorCodigoInstrumento++;

    musico[0].idMusico=1;
    musico[0].isEmpty=0;
    strcpy(musico[0].nombre,"Mus1");
    strcpy(musico[0].apellido,"AMus1");
    musico[0].edad = 30;
    musico[0].idOrquesta = 1;
    musico[0].idInstrumento = 2;
    generadorCodigoMusico++;

    musico[1].idMusico=2;
    musico[1].isEmpty=0;
    strcpy(musico[1].nombre,"Mus2");
    strcpy(musico[1].apellido,"AMus");
    musico[1].edad = 20;
    musico[1].idOrquesta = 2;
    musico[1].idInstrumento = 5;
    generadorCodigoMusico++;

    musico[2].idMusico=3;
    musico[2].isEmpty=0;
    strcpy(musico[2].nombre,"Mus3");
    strcpy(musico[2].apellido,"AMus3");
    musico[2].edad = 25;
    musico[2].idOrquesta = 4;
    musico[2].idInstrumento = 2;
    generadorCodigoMusico++;

    musico[3].idMusico=4;
    musico[3].isEmpty=0;
    strcpy(musico[3].nombre,"Mus4");
    strcpy(musico[3].apellido,"AMus4");
    musico[3].edad = 27;
    musico[3].idOrquesta = 4;
    musico[3].idInstrumento = 1;
    generadorCodigoMusico++;

    musico[4].idMusico=5;
    musico[4].isEmpty=0;
    strcpy(musico[4].nombre,"Mus5");
    strcpy(musico[4].apellido,"AMus5");
    musico[4].edad = 22;
    musico[4].idOrquesta = 1;
    musico[4].idInstrumento = 3;
    generadorCodigoMusico++;

    musico[5].idMusico=6;
    musico[5].isEmpty=0;
    strcpy(musico[5].nombre,"Mus6");
    strcpy(musico[5].apellido,"AMus6");
    musico[5].edad = 35;
    musico[5].idOrquesta = 3;
    musico[5].idInstrumento = 4;
    generadorCodigoMusico++;
}



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

int inf_Inicializar(ContadorMusicos *arrayContadorMusico, int cantidad)
{
    int retorno = -1;
    int i;

    for (i = 0; i < cantidad; i++)
    {
        arrayContadorMusico[i].cantMusico = 0;
        retorno=0;
    }

    return retorno;
}

int inf_InicializarCantidadMusico(ContadorMusicos *arrayMusico, int cantidad)
{
    int retorno = -1;
    int i;

    for (i = 0; i < cantidad; i++)
    {
        arrayMusico[i].isEmpty = 1;
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
                arrayContadorMusicos[posicionArrayContador].isEmpty = 0;
                posicionArrayContador++;
            }

        }
        retorno = 0;
    }
    return retorno;
}

int inf_orquestasDeUnLugar(Orquesta *arrayOrquesta, int cantidadOrquesta)
{
    int retorno = -1;
    char auxLugar[30];
    int auxFlag;

    int i;

    utn_getName("\nIngrese un lugar: \n", "\nError, dato no valido", 3, 30,2, auxLugar);

    if(arrayOrquesta != NULL && cantidadOrquesta > 0)
    {
        for(i=0;i<cantidadOrquesta;i++)
        {
            auxFlag = 1;
            if(strcmp(auxLugar, arrayOrquesta[i].lugar) == 0 && arrayOrquesta[i].isEmpty == 0)
            {
                auxFlag = 0;
                printf("ID de Orquesta: %d\n", arrayOrquesta[i].idOrquesta);
                printf("Nombre: %s\n", arrayOrquesta[i].nombre);
                printf("Lugar: %s\n", arrayOrquesta[i].lugar);
                switch(arrayOrquesta[i].tipo)
                {
                    case 1:
                        printf("Tipo: 1-Sinfonica\n\n");
                        break;
                    case 2:
                        printf("Tipo: 2-Filarmonica\n\n");
                        break;
                    case 3:
                        printf("Tipo: 3-Camara\n\n");
                        break;
                }
            }
            else
            {
                if(!auxFlag)
                    printf("No hubo coincidencia\n\n");
                break;
            }


        }
        retorno = 0;
    }
    return retorno;
}

int inf_menosDe25(Musico *arrayMusico, Orquesta *arrayOrquesta, Instrumento *arrayInstrumento, int cantidadMusico,int cantidadOrquesta,int cantidadInstrumento)
{
    int retorno = -1;
    int auxPosInstrumento;
    int auxPosOrquesta;

    int i;

    if(arrayMusico != NULL && cantidadMusico > 0)
    {
        for(i = 0;i < cantidadMusico; i++)
        {
            if(arrayMusico[i].isEmpty == 0)
            {
                if(arrayMusico[i].edad < 25 )
                {
                    printf("ID de musico: %d\n", arrayMusico[i].idMusico);
                    printf("Nombre: %s\n", arrayMusico[i].nombre);
                    printf("Apellido: %s\n", arrayMusico[i].apellido);
                    printf("Edad: %d\n", arrayMusico[i].edad);
                    ins_buscarEnArrayPorId (arrayInstrumento, arrayMusico[i].idInstrumento, cantidadInstrumento, &auxPosInstrumento);
                    printf("Instrumento: %s\n", arrayInstrumento[auxPosInstrumento].nombre);
                    orq_buscarEnArrayPorId2 (arrayOrquesta, arrayMusico[i].idOrquesta, cantidadOrquesta, &auxPosOrquesta);
                    printf("Orquesta: %s\n", arrayOrquesta[auxPosOrquesta].nombre);
                }
            }
        }
        retorno = 0;
    }
    return retorno;
}

void inf_mostrarArrayContadorMusico(ContadorMusicos *arrayContadorMusico, int cantidad)
{
    int i;

    printf("\n\n\t\t\t\t||Lista de cantidades de musico por orquesta||\n\n");

    for (i = 0; i < cantidad ;i++)
    {
        if(arrayContadorMusico[i].isEmpty == 0)
        {

            printf("ID de Orquesta: %d\n", arrayContadorMusico[i].idOrquesta);
            printf("Cantidad de musicos: %d\n", arrayContadorMusico[i].cantMusico);
        }
    }
}

int menosDe6musicos(ContadorMusicos *arrayContadorMusicos,Orquesta *arrayOrquesta, int cantidadOrquesta)
{
    int retorno = -1;
    int i;
    int posicionOrquesta;

    if(arrayContadorMusicos != NULL && arrayOrquesta != NULL && cantidadOrquesta > 0)
    {
        for(i=0;i<cantidadOrquesta;i++)
        {
            if(arrayContadorMusicos[i].cantMusico < 6 && arrayContadorMusicos[i].isEmpty == 0)
            {
                orq_buscarEnArrayPorId2 (arrayOrquesta, arrayContadorMusicos[i].idOrquesta, cantidadOrquesta, &posicionOrquesta);
                printf("ID de Orquesta: %d\n", arrayOrquesta[posicionOrquesta].idOrquesta);
                printf("Nombre: %s\n", arrayOrquesta[posicionOrquesta].nombre);
                printf("Lugar: %s\n", arrayOrquesta[posicionOrquesta].lugar);
                switch(arrayOrquesta[posicionOrquesta].tipo)
                {
                    case 1:
                        printf("Tipo: 1-Sinfonica\n\n");
                        break;
                    case 2:
                        printf("Tipo: 2-Filarmonica\n\n");
                        break;
                    case 3:
                        printf("Tipo: 3-Camara\n\n");
                        break;
                }
                retorno = 0;
            }
        }
    }
    return retorno;
}

/*int listaTodosInstrumentosDeUnaOrquesta(Orquesta *arrayOrquesta, Instrumento *arrayInstrumento, Musico *arrayInstrumento, int cantidadMusico,int cantidadOrquesta,int cantidadInstrumento)
{

    if(arrayInstrumento != NULL && arrayMusico != NULL && arrayOrquesta != NULL)
    {
        orq_buscarEnArrayPorId (arrayOrquesta, cantidadOrquesta, int *orquestaEncontrada,char *textoAMostrar)
    }
}*/


int menosMusicos(ContadorMusicos *arrayContadorMusicos,Orquesta *arrayOrquesta, int cantidadOrquesta)
{
    int retorno = -1;
    int i;
    int posicionOrquesta;
    int menosMusicos = 1000;

    if(arrayContadorMusicos != NULL && arrayOrquesta != NULL && cantidadOrquesta > 0)
    {
        for(i=0;i<cantidadOrquesta;i++)
        {
            if(arrayContadorMusicos[i].cantMusico < menosMusicos && arrayContadorMusicos[i].isEmpty == 0)
            {
                menosMusicos = arrayContadorMusicos[i].cantMusico;
                posicionOrquesta = i;
            }
        }

        orq_buscarEnArrayPorId2 (arrayOrquesta, arrayOrquesta[posicionOrquesta].idOrquesta, cantidadOrquesta, &posicionOrquesta);
        printf("ID de Orquesta: %d\n", arrayOrquesta[posicionOrquesta].idOrquesta);
        printf("Nombre: %s\n", arrayOrquesta[posicionOrquesta].nombre);
        printf("Lugar: %s\n", arrayOrquesta[posicionOrquesta].lugar);
        printf("Cantidad de musicos: %d\n", menosMusicos);
        switch(arrayOrquesta[posicionOrquesta].tipo)
        {
            case 1:
                printf("Tipo: 1-Sinfonica\n\n");
                break;
            case 2:
                printf("Tipo: 2-Filarmonica\n\n");
                break;
            case 3:
                printf("Tipo: 3-Camara\n\n");
                break;
        }
        retorno = 0;
    }
    return retorno;
}

/*int musicosNoInstrumentoViento(Musico *arrayMusico, Instrumento *arrayInstrumento, int cantidadInstrumento, int cantidadMusico)
{
     if(arrayMusicos != NULL && arrayOrquesta != NULL && cantidadOrquesta > 0 && cantidadMusico >0)
     {
        if(arrayMusico[i].)
     }
}*/

int promedioInstrumentoPorOrquesta(ContadorMusicos *arrayContador, Musico *arrayMusico, int cantidadContador, int cantidadMusico)
{
    int retorno = -1;
    int i;
    int contadorOrquestas = 0;
    int contadorInstrumentos = 0;
    float promedio;

    if(arrayContador != NULL && arrayMusico != NULL && cantidadContador >0)
    {
        for(i=0;i<cantidadContador;i++)
        {
            if(arrayContador[i].isEmpty == 0)
            {
                contadorOrquestas++;
                retorno = 0;
            }
        }
        for(i=0;i<cantidadMusico;i++)
        {
            if(arrayMusico[i].isEmpty == 0)
            {
                contadorInstrumentos++;
                retorno = 0;
            }
        }

        promedio =(float) contadorInstrumentos/(float)contadorInstrumentos;
        printf("El promedio de instrumentos por orquesta es: %f\n\n", (float)promedio);
    }

    return retorno;
}


