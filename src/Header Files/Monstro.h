#pragma once
#include <allegro5/allegro.h>
#define MONSTRO 'M'
typedef struct monstro Monstro;

struct monstro
{
    ALLEGRO_BITMAP * monstroBitmap;
    int posicaoX;
    int posicaoY;
    int direcao;
};

int quantidadeMonstros(Mapa * mapa);
void localizaMonstros(Mapa * mapa, Monstro * monstros, int qntMonstros);
void desenhaMonstros(Monstro * monstros, int qntMonstros);
void alocaMonstros(Monstro * monstros, int qntMonstros);
void desalocaMonstros(Monstro * monstros);
void movimentaMonstros(Mapa * mapa, Monstro * monstros, int qntMonstros);
void marcaMonstros(Mapa * mapa , Monstro * monstros, int qntMonstros);