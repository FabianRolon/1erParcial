#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
typedef struct
{
    int idOrquesta;
    int cantMusico = 0;
}ContadorMusicos;

int musico_ordenarPorDobleCriterio(Musico *arrayMusico,int size, int orderFirst, int orderSecond);

int inf_contadorMusicosOrquesta();

#endif // INFORMES_H_INCLUDED
