#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
typedef struct
{
    int idOrquesta;
    int cantMusico;
}ContadorMusicos;

int musico_ordenarPorDobleCriterio(Musico *arrayMusico,int size, int orderFirst, int orderSecond);

int inf_contadorMusicosOrquesta(ContadorMusicos *arrayContadorMusicos, Orquesta *arrayOrquesta, Musico *arrayMusico, int cantidadMusico, int cantidadOrquesta);

#endif // INFORMES_H_INCLUDED
