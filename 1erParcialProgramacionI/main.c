#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//#include <stdio_ext.h>
#include "orquesta.h"
#include "instrumento.h"
#include "utn.h"
#include "musico.h"
#include "informes.h"
#define CANTIDAD_ORQUESTA 50
#define CANTIDAD_INSTRUMENTO 20
#define CANTIDAD_MUSICO 1000

int main()
{
    int generadorCodigoOrquesta = 1;
    int generadorCodigoInstrumento = 1;
    int generadorCodigoMusico = 1;
    char seguir = 's';
    char salirListaOrquesta = 'n';
    char salirListaInstrumento = 'n';
    char salirListaMusicos = 'n';
    int salirListaInformes = 1;
    int opcion;
    int opcionInforme;
    int valor1;
    int valor2;
    int valor3;
    int posicionLibreOrquesta;
    int posicionLibreInstrumento;
    int posicionLibreMusico;

    Orquesta orquesta[CANTIDAD_ORQUESTA];
    Instrumento instrumento[CANTIDAD_INSTRUMENTO];
    Musico musico[CANTIDAD_MUSICO];

    valor1 = orq_Inicializar(orquesta, CANTIDAD_ORQUESTA);
    valor2 = ins_Inicializar(instrumento, CANTIDAD_INSTRUMENTO);
    valor3 = mus_Inicializar(musico, CANTIDAD_MUSICO);

    if (valor1 == 0 && valor2 == 0 && valor3 == 0)
    {
        printf("Sistema inicializado correctamente\n\n\n");
    }

    orquesta[0].idOrquesta=1;
    orquesta[0].isEmpty=0;
    strcpy(orquesta[0].nombre,"Metallica");
    strcpy(orquesta[0].lugar,"San Francisco");
    orquesta[0].tipo = 1;
    generadorCodigoOrquesta++;

    orquesta[1].idOrquesta=2;
    orquesta[1].isEmpty=0;
    strcpy(orquesta[1].nombre,"Grande");
    strcpy(orquesta[1].lugar,"Cordoba");
    orquesta[1].tipo = 2;
    generadorCodigoOrquesta++;

    orquesta[2].idOrquesta=3;
    orquesta[2].isEmpty=0;
    strcpy(orquesta[2].nombre,"Magnifica");
    strcpy(orquesta[2].lugar,"La Matanza");
    orquesta[2].tipo = 3;
    generadorCodigoOrquesta++;

    orquesta[3].idOrquesta=4;
    orquesta[3].isEmpty=0;
    strcpy(orquesta[3].nombre,"Callejera");
    strcpy(orquesta[3].lugar,"Boedo");
    orquesta[3].tipo = 1;
    generadorCodigoOrquesta++;

    instrumento[0].idInstrumento=1;
    instrumento[0].isEmpty=0;
    strcpy(instrumento[0].nombre,"Guitarra");
    instrumento[0].tipo = 1;
    generadorCodigoInstrumento++;

    instrumento[1].idInstrumento=2;
    instrumento[1].isEmpty=0;
    strcpy(instrumento[1].nombre,"Bateria");
    instrumento[1].tipo = 4;
    generadorCodigoInstrumento++;

    instrumento[2].idInstrumento=3;
    instrumento[2].isEmpty=0;
    strcpy(instrumento[2].nombre,"Flauta traverza");
    instrumento[2].tipo = 3;
    generadorCodigoInstrumento++;

    instrumento[3].idInstrumento=4;
    instrumento[3].isEmpty=0;
    strcpy(instrumento[3].nombre,"Violin");
    instrumento[3].tipo = 1;
    generadorCodigoInstrumento++;

    musico[0].idMusico=1;
    musico[0].isEmpty=0;
    strcpy(musico[0].nombre,"Fabian");
    strcpy(musico[0].apellido,"Rolon");
    musico[0].edad = 30;
    musico[0].idOrquesta = 1;
    musico[0].idInstrumento = 1;
    generadorCodigoMusico++;

    musico[1].idMusico=2;
    musico[1].isEmpty=0;
    strcpy(musico[1].nombre,"Marcelo");
    strcpy(musico[1].apellido,"Menendez");
    musico[1].edad = 52;
    musico[1].idOrquesta = 2;
    musico[1].idInstrumento = 4;
    generadorCodigoMusico++;

    musico[2].idMusico=3;
    musico[2].isEmpty=0;
    strcpy(musico[2].nombre,"Lucas");
    strcpy(musico[2].apellido,"Barua");
    musico[2].edad = 33;
    musico[2].idOrquesta = 3;
    musico[2].idInstrumento = 2;
    generadorCodigoMusico++;

    musico[3].idMusico=4;
    musico[3].isEmpty=0;
    strcpy(musico[3].nombre,"Leandro");
    strcpy(musico[3].apellido,"Gonzales");
    musico[3].edad = 27;
    musico[3].idOrquesta = 1;
    musico[3].idInstrumento = 3;
    generadorCodigoMusico++;

        while (seguir == 's')
        {
            printf("\t\t*MENU*");
            printf("\n\nORQUESTA");
            printf("\n\n1-Alta orquesta");
            printf("\n\n2-Baja orquesta");
            printf("\n\n3-Listar orquesta");
            printf("\n\nINSTRUMENTOS");
            printf("\n\n4-Alta instrumento");
            printf("\n\n5-Listar instrumentos");
            printf("\n\nMUSICO");
            printf("\n\n9-Alta Musico");
            printf("\n\n10-Baja Musico");
            printf("\n\n11-Modificar Musico");
            printf("\n\n12-Listar Musicos");
            printf("\n\n13-Informes");
            printf("\n\n14-Salir\n");

            utn_getUnsignedInt("\n\t\tIngrese opcion: ","Ingreso incorrecto\n",1,12,2,&opcion);
            system("clear");
            switch (opcion)
            {
            case 1:
                if(orq_buscarLibre(orquesta,CANTIDAD_ORQUESTA, &posicionLibreOrquesta) != 0)
                {
                    printf("LLENO\n\n");
                }
                else
                {
                    switch (orq_alta(orquesta, CANTIDAD_ORQUESTA, posicionLibreOrquesta, generadorCodigoOrquesta))
                    {
                    case 0:
                        printf("Dato ingresado correctamente\n\n");
                        generadorCodigoOrquesta++;
                        break;
                    case 1:
                        printf("Dato ingresado INCORRECTAMENTE\n\n");
                        break;
                    }
                }
                break;
            case 2:
                if (orq_baja(orquesta, musico, CANTIDAD_ORQUESTA, CANTIDAD_MUSICO) == 0)
                {
                    printf("Exito");
                }
                break;
            case 3:
                do
                {
                    orq_mostrarArray(orquesta, CANTIDAD_ORQUESTA);
                    utn_getChar("\n\tIngrese 's' para volver al menu anterior: ", "Ingreso incorrecto",1,2,2,&salirListaOrquesta);

                }while(salirListaOrquesta!='s');
                break;
            case 4:
                  if(ins_buscarLibre(instrumento,CANTIDAD_INSTRUMENTO, &posicionLibreInstrumento) != 0)
                    {
                        printf("LLENO\n\n");
                    }
                    else
                    {
                        switch (ins_alta(instrumento,CANTIDAD_INSTRUMENTO, posicionLibreInstrumento, generadorCodigoInstrumento))
                        {
                        case 0:
                            printf("Dato ingresado correctamente\n\n");
                            generadorCodigoInstrumento++;
                            break;
                        case 1:
                            printf("Dato ingresado INCORRECTAMENTE\n\n");
                            break;
                        case 2:
                            printf("El codigo de autor no existe\n\n");
                            break;
                        }
                    }
                break;
            case 5:
                do
                {
                    ins_mostrarArray(instrumento, CANTIDAD_INSTRUMENTO);
                    utn_getChar("\n\tIngrese 's' para volver al menu anterior: ", "Ingreso incorrecto",1,2,2,&salirListaInstrumento);

                }while(salirListaInstrumento!='s');
                break;
            case 9:
                if(mus_buscarLibre(musico,CANTIDAD_MUSICO, &posicionLibreMusico) != 0)
                {
                    printf("LLENO\n\n");
                }
                else
                {
                    switch (mus_alta(musico, instrumento, orquesta, CANTIDAD_MUSICO, CANTIDAD_INSTRUMENTO, CANTIDAD_ORQUESTA, posicionLibreMusico, generadorCodigoMusico))
                    {
                    case 0:
                        printf("Dato ingresado correctamente\n\n");
                        generadorCodigoMusico++;
                        break;
                    case 1:
                        printf("Dato ingresado INCORRECTAMENTE\n\n");
                        break;
                    }
                }
                break;
            case 10:
                if (mus_baja(musico, instrumento, CANTIDAD_MUSICO, CANTIDAD_INSTRUMENTO) == 0)
                    {
                        printf("Exito");
                    }
                break;
            case 11:
                mus_modificacion(musico, instrumento, orquesta, CANTIDAD_MUSICO, CANTIDAD_INSTRUMENTO, CANTIDAD_ORQUESTA);
                break;
            case 12:
                do
                {
                    mus_mostrarArray(musico,instrumento, CANTIDAD_MUSICO,CANTIDAD_INSTRUMENTO);
                    utn_getChar("\n\tIngrese 's' para volver al menu anterior: ", "Ingreso incorrecto",1,2,2,&salirListaMusicos);

                }while(salirListaMusicos!='s');
                break;
            case 13:
                do
                {
                    printf("\n1-Ordenar por nombre y apellido ascendente");
                    printf("\n2-Salir\n\n");

                    utn_getUnsignedInt("\n\t\tIngrese opcion: ","Ingreso incorrecto\n",1,3,2,&opcionInforme);
                    switch (opcionInforme)
                    {
                    case 1:
                        musico_ordenarPorDobleCriterio(musico, CANTIDAD_MUSICO,1,0);
                        break;
                    case 2:
                        salirListaInformes = 0;
                        break;
                    }
                }while(salirListaInformes);
                break;
            case 14:
                seguir = 'a';
                break;
            }
        }
    return 0;
}
