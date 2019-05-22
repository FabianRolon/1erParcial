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
    char opcionInforme = '1';
    int valor1;
    int valor2;
    int valor3;
    int valor4;
    int posicionLibreOrquesta;
    int posicionLibreInstrumento;
    int posicionLibreMusico;

    Orquesta orquesta[CANTIDAD_ORQUESTA];
    Instrumento instrumento[CANTIDAD_INSTRUMENTO];
    Musico musico[CANTIDAD_MUSICO];
    ContadorMusicos contadorMusico[CANTIDAD_ORQUESTA];

    valor1 = orq_Inicializar(orquesta, CANTIDAD_ORQUESTA);
    valor2 = ins_Inicializar(instrumento, CANTIDAD_INSTRUMENTO);
    valor3 = mus_Inicializar(musico, CANTIDAD_MUSICO);
    inf_Inicializar(contadorMusico, CANTIDAD_ORQUESTA);
    valor4 = inf_InicializarCantidadMusico(contadorMusico, CANTIDAD_MUSICO);

    if (valor1 == 0 && valor2 == 0 && valor3 == 0 && valor4 == 0)
    {
        printf("Sistema inicializado correctamente\n\n\n");
    }

    harcodeo(orquesta, instrumento, musico);

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
                    printf("\na)-Buscar orquestas por lugar");
                    printf("\nb)-Lista de musicos menores de 25 años");
                    printf("\nc)-Orquesta con menos de 6 musicos");
                    printf("\nf)-Orquesta con menos musicos");
                    printf("\ng)-Promedio de instrumentos por orquesta");
                    printf("\ni)-Salir\n\n");


                    utn_getChar("\n\t\tIngrese opcion: ", "Ingreso incorrecto",1,2,2,&opcionInforme);
                    switch (opcionInforme)
                    {
                    case 'a':
                        inf_orquestasDeUnLugar(orquesta, CANTIDAD_ORQUESTA);
                        break;
                    case 'b':
                        inf_contadorMusicosOrquesta(contadorMusico, orquesta,musico, CANTIDAD_MUSICO, CANTIDAD_ORQUESTA);
                        inf_menosDe25(musico, orquesta, instrumento, CANTIDAD_MUSICO,CANTIDAD_ORQUESTA,CANTIDAD_INSTRUMENTO);
                        inf_mostrarArrayContadorMusico(contadorMusico, CANTIDAD_ORQUESTA);
                        break;
                    case 'c':
                        inf_contadorMusicosOrquesta(contadorMusico, orquesta,musico, CANTIDAD_MUSICO, CANTIDAD_ORQUESTA);
                        menosDe6musicos(contadorMusico,orquesta, CANTIDAD_ORQUESTA);
                        break;
                    case 'f':
                        inf_contadorMusicosOrquesta(contadorMusico, orquesta,musico, CANTIDAD_MUSICO, CANTIDAD_ORQUESTA);
                        menosMusicos(contadorMusico,orquesta,CANTIDAD_ORQUESTA);
                        break;
                    case 'g':
                        inf_contadorMusicosOrquesta(contadorMusico, orquesta,musico, CANTIDAD_MUSICO, CANTIDAD_ORQUESTA);
                        promedioInstrumentoPorOrquesta(contadorMusico, musico, CANTIDAD_ORQUESTA, CANTIDAD_MUSICO);
                        break;
                    case 'i':
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
