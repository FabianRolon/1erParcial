#ifndef INSTRUMENTO_H_INCLUDED
#define INSTRUMENTO_H_INCLUDED


typedef struct
{
    int idInstrumento;
    int isEmpty;
    char nombre[30];
    int tipo;
}Instrumento;

#endif


int ins_Inicializar(Instrumento *arrayInstrumento, int cantidad);
int ins_buscarLibre(Instrumento *arrayInstrumento, int cantidad, int *devuelve);
int ins_buscarEnArrayPorId (Instrumento *arrayInstrumento, int idInstrumento, int cantidad, int *instrumentoEncontrado);
int ins_alta(Instrumento *arrayInstrumento, int cantidad, int posLibre, int id);
void ins_mostrarArray(Instrumento *arrayInstrumento, int cantidad);
int ins_existeId (Instrumento *arrayInstrumento, int cantidad, int id);
