#ifndef MUSICO_H_INCLUDED
#define MUSICO_H_INCLUDED
#include "instrumento.h"
#include "orquesta.h"

typedef struct
{
    int idMusico;
    int isEmpty;
    char nombre[30];
    char apellido[30];
    int edad;
    int idOrquesta;
    int idInstrumento;
}Musico;

#endif // MUSICO_H_INCLUDED


int mus_Inicializar(Musico *arrayMusico, int cantidad);
int mus_buscarLibre(Musico *arrayMusico, int cantidad, int *devuelve);
int mus_buscarEnArrayPorId (Musico *arrayMusico, int cantidad, int *musuestaEncontrada,char *textoAMostrar);
int mus_alta(Musico *arrayMusico, Instrumento *arrayInstrumento, Orquesta *arrayOrquesta, int cantidadMusico, int cantidadInstrumento, int cantidadOrquesta, int posLibre, int id);
int mus_baja(Musico *arrayMusico, Instrumento *arrayInstrumento, int cantidadMusico, int cantidadInstrumento);
void mus_mostrarArray(Musico *arrayMusico, Instrumento *arrayInstrumento, int cantidadMusico, int cantidadInstrumento);
int mus_modificacion(Musico *arrayMusico, Instrumento *arrayInstrumento, Orquesta *arrayOrquesta, int cantidadMusico, int cantidadInstrumento, int cantidadOrquesta);
int mus_existeId (Musico *arrayMusico, int cantidad, int id);
void mus_mostrarArray2(Musico *arrayMusico, int cantidad);
int mus_buscarEnArrayPorId2 (Musico *arrayMusico, int cantidad, int *musicoEncontrado,char *textoAMostrar);
int orq_baja(Orquesta *arrayOrquesta, Musico *arrayMusico, int cantidadOrquesta, int cantidadMusico);
