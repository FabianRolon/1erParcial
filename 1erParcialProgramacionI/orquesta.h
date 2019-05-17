#ifndef ORQUESTA_H_INCLUDED
#define ORQUESTA_H_INCLUDED

typedef struct
{
    int idOrquesta;
    int isEmpty;
    char nombre[30];
    int tipo;
    char lugar[30];

}Orquesta;

#endif


int orq_Inicializar(Orquesta *arrayOrquesta, int cantidad);
int orq_buscarLibre(Orquesta *arrayOrquesta, int cantidad, int *devuelve);
int orq_buscarEnArrayPorId (Orquesta *arrayOrquesta, int cantidad, int *orquestaEncontrada,char *textoAMostrar);
int orq_alta(Orquesta *arrayOrquesta, int cantidad, int posLibre, int id);
int orq_baja(Orquesta *arrayOrquesta, int cantidad);
void orq_mostrarArray(Orquesta *arrayOrquesta, int cantidad);
int orq_modificacion(Orquesta *arrayOrquesta, int cantidad);
int orq_existeId (Orquesta *arrayOrquesta, int cantidad, int id);


