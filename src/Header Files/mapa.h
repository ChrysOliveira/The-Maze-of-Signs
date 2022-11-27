#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#define CHAO '0'
#define PAREDE '1'
#define PORTA '2'
#define DICA '3'
#define PODER '5'

typedef struct mapa Mapa;

struct mapa {
	char** matriz;
	int qntColunas;
	int qntLinhas;
};

void alocaMapa(Mapa* mapa);
void liberaMapa(Mapa * mapa);
void leMapa(Mapa * mapa);
void desenhaMapa(Mapa*mapa, ALLEGRO_BITMAP *chao, ALLEGRO_BITMAP *parede, ALLEGRO_BITMAP *dica, ALLEGRO_BITMAP *poder);
int ehParede(Mapa* mapa, int posicaoX, int posicaoY);
void ehDica(Mapa* mapa, int posicaoX, int posicaoY);
void ehPoder(Mapa* mapa, int posicaoX, int posicaoY);