#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#define CHAO '0'
#define PAREDE '1'
#define PAREDE2 '1'
#define MONSTRO 'M'

typedef struct mapa Mapa;

struct mapa {
	char** matriz;
	int qntColunas;
	int qntLinhas;
};

void alocaMapa(Mapa* mapa);
void liberaMapa(Mapa * mapa);
void leMapa(Mapa * mapa);
void desenhaMapa(Mapa* mapa, ALLEGRO_BITMAP* bitmap);
int ehParede(Mapa* mapa, int posicaoX, int posicaoY);

