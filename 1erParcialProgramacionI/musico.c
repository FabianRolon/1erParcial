#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <ctype.h>
#include "instrumento.h"
#include "orquesta.h"
#include "musico.h"
#include "utn.h"

int mus_Inicializar(Musico *arrayMusico, int cantidad)
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

int mus_buscarLibre(Musico *arrayMusico, int cantidad, int *devuelve)
{
    int retorno=-1;
    for (int i=0; i<cantidad;i++)
    {
        if (arrayMusico[i].isEmpty==1)
        {
            *devuelve=i;
            retorno=0;
            break;
        }

        retorno=1;
    }

    return retorno;
}

int mus_alta(Musico *arrayMusico, Instrumento *arrayInstrumento, Orquesta *arrayOrquesta, int cantidadMusico, int cantidadInstrumento, int cantidadOrquesta, int posLibre, int id)
{
    int retorno = -1;

    if (    utn_getName("\n\nIngrese el nombre : ","Error, vuelva a ingresar\n\n",2,30,2, arrayMusico[posLibre].nombre) == 0 &&
            utn_getName("\n\nIngrese el apellido: ","Error, vuelva a ingresar\n\n",2,30,2, arrayMusico[posLibre].apellido) == 0 &&
            utn_getUnsignedInt("\n\nIngrese la edad: ","Error, vuelva a ingresar\n\n",1,9,2,&arrayMusico[posLibre].edad) == 0)
        {
           ins_mostrarArray(arrayInstrumento, cantidadInstrumento);
            if(utn_getUnsignedInt("\n\nIngrese ID de instrumento: ","Error, vuelva a ingresar\n\n",1,20,2,&arrayMusico[posLibre].idInstrumento) == 0)
            {
                orq_mostrarArray(arrayOrquesta, cantidadOrquesta);
                if(utn_getUnsignedInt("\n\nIngrese ID de Orquesta: ","Error, vuelva a ingresar\n\n",1,50,2,&arrayMusico[posLibre].idOrquesta) == 0)
                {
                    arrayMusico[posLibre].idMusico = id;
                    arrayMusico[posLibre].isEmpty  = 0;
                    retorno=0;
                }

            }
        }
        else
        {
            retorno = 1;
        }

        return retorno;
}

int mus_buscarEnArrayPorId (Musico *arrayMusico, int cantidad, int *musuestaEncontrada,char *textoAMostrar)
{
    int i;
    int retorno = 1;
    Musico auxMusico;

    if (utn_getUnsignedInt(textoAMostrar, "Ingreso incorrecto\n", 0, 100, 2, &auxMusico.idMusico) == 0)
    {
        for(i=0; i < cantidad; i++)
        {
            if (arrayMusico[i].idMusico == auxMusico.idMusico)
            {
                retorno=0;
                *musuestaEncontrada=i;
                break;
            }
        }
    }
    return retorno;
}

int mus_baja(Musico *arrayMusico, Instrumento *arrayInstrumento, int cantidadMusico, int cantidadInstrumento)
{
    int retorno = -1;
    int posicionMusico;
    mus_mostrarArray(arrayMusico, arrayInstrumento, cantidadMusico, cantidadInstrumento);
    switch (mus_buscarEnArrayPorId(arrayMusico, cantidadMusico,&posicionMusico,"Ingrese el codigo del musico a dar de baja: "))
    {
    case 0:
        if (arrayMusico[posicionMusico].isEmpty == 0)
        {
            printf("Hubo coincidencia\n\n");
            arrayMusico[posicionMusico].isEmpty = 2;
            printf("El musico borrado es: %d\n\n",arrayMusico[posicionMusico].idMusico);
            retorno = 0;
        }
        break;
    case 1:
        printf("No se encontro el codigo\n\n");
        break;
    }
    return retorno;
}

void mus_mostrarArray(Musico *arrayMusico, Instrumento *arrayInstrumento, int cantidadMusico, int cantidadInstrumento)
{
    int i;
    int posicionInstrumento;

    printf("\n\n\t\t\t\t||Lista de Musicos||\n\n");

    for (i = 0; i < cantidadMusico ;i++)
    {
        if(arrayMusico[i].isEmpty == 0)
        {

            printf("\nID de Musico: %d\n", arrayMusico[i].idMusico);
            printf("Posicion: %d\n", i);
            printf("Estado: %d\n", arrayMusico[i].isEmpty);
            printf("Nombre: %s\n", arrayMusico[i].nombre);
            printf("Apellido: %s\n", arrayMusico[i].apellido);
            printf("Edad: %d\n", arrayMusico[i].edad);
            ins_buscarEnArrayPorId (arrayInstrumento, arrayMusico[i].idInstrumento, cantidadInstrumento, &posicionInstrumento);
            printf("Nombre de Instrumento: %s\n", arrayInstrumento[posicionInstrumento].nombre);
            switch(arrayInstrumento[posicionInstrumento].tipo)
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

int mus_modificacion(Musico *arrayMusico, Instrumento *arrayInstrumento, Orquesta *arrayOrquesta, int cantidadMusico, int cantidadInstrumento, int cantidadOrquesta)
{

    int retorno = -1;
    int opcion;
    int posicionMusico;
    char seguir = 's';

   mus_mostrarArray2(arrayMusico, cantidadMusico);

    switch (mus_buscarEnArrayPorId2(arrayMusico, cantidadMusico,&posicionMusico,"Ingrese el ID de musico a modificar: "))
    {
    case 0:
        if (arrayMusico[posicionMusico].isEmpty == 0)
        {
            printf("Hubo coincidencia\n\n");

            while(seguir == 's')
            {
                printf("Elija el dato que desea modificar\n\n");

                printf("\n\n1-Nombre");
                printf("\n\n2-Edad");
                printf("\n\n2-ID Orquesta");
                printf("\n\n4-Salir de la modificacion");

                utn_getUnsignedInt("\n\t\tIngrese opcion: ", "Ingreso incorrecto\n", 1, 3, 2, &opcion);


                switch(opcion)
                {
                    case 1:
                        if (getString("Ingrese el nuevo nombre de musico: ","Error",2,20,2, arrayMusico[posicionMusico].nombre)==0)
                        {
                            printf("El dato fue modificado con exito.\n\n");
                        }
                        break;
                    case 2:
                        if (utn_getUnsignedInt("Ingrese la nueva edad: " ,"Error, vuelva a ingresar\n\n",1,9,2, &arrayMusico[posicionMusico].edad)==0)
                        {
                            printf("El dato fue modificado con exito.\n\n");
                        }
                        break;

                    case 3:
                         orq_mostrarArray(arrayOrquesta, cantidadOrquesta);
                         if (utn_getUnsignedInt("Ingrese el nuevo ID de Orquesta: " ,"Error, vuelva a ingresar\n\n",1,50,2, &arrayMusico[posicionMusico].idOrquesta)==0)
                            {
                                printf("El dato fue modificado con exito.\n\n");
                            }

                        break;

                    case 4:
                        seguir = 'n';
                        retorno = 0;
                        break;
                }
            }
        }
        break;

    case 1:
        printf("No se encontro el ID");
        break;
        }

    return retorno;
}

void mus_mostrarArray2(Musico *arrayMusico, int cantidad)
{
    int i;

    printf("\n\n\t\t\t\t||Lista de Musicos||\n\n");

    for (i = 0; i < cantidad ;i++)
    {
        if(arrayMusico[i].isEmpty == 0)
        {

            printf("ID de Musico: %d\n", arrayMusico[i].idMusico);
            printf("Nombre: %s\n", arrayMusico[i].nombre);
            printf("Apellido: %s\n\n", arrayMusico[i].apellido);
        }
    }
}

int mus_buscarEnArrayPorId2 (Musico *arrayMusico, int cantidad, int *musicoEncontrado,char *textoAMostrar)
{
    int i;
    int retorno = 1;
    Musico auxMusico;

    if (utn_getUnsignedInt(textoAMostrar, "Ingreso incorrecto\n", 0, 100, 2, &auxMusico.idMusico) == 0)
    {
        for(i=0; i < cantidad; i++)
        {
            if (arrayMusico[i].idMusico == auxMusico.idMusico)
            {
                retorno=0;
                *musicoEncontrado=i;
                break;
            }
        }
    }
    return retorno;
}

int orq_baja(Orquesta *arrayOrquesta, Musico *arrayMusico, int cantidadOrquesta, int cantidadMusico)
{
    int retorno = -1;
    int posicionOrquesta;
    int i;

    orq_mostrarArray(arrayOrquesta, cantidadOrquesta);
    switch (orq_buscarEnArrayPorId(arrayOrquesta, cantidadOrquesta,&posicionOrquesta,"Ingrese el Id de orquesta a dar de baja: "))
    {
    case 0:
        if (arrayOrquesta[posicionOrquesta].isEmpty == 0)
        {
            for(i=0;i<cantidadMusico;i++)
            {
                if(arrayMusico[i].idOrquesta == arrayOrquesta[posicionOrquesta].idOrquesta && arrayMusico[i].isEmpty == 0)
                {
                    arrayMusico[i].isEmpty = 2;
                }
            }
            printf("Hubo coincidencia\n\n");
            arrayOrquesta[posicionOrquesta].isEmpty = 2;
            printf("La orquesta borrada junto con sus musicos es: %d\n\n",arrayOrquesta[posicionOrquesta].idOrquesta);
            retorno = 0;
        }
        break;
    case 1:
        printf("No se encontro el codigo\n\n");
        break;
    }
    return retorno;
}
