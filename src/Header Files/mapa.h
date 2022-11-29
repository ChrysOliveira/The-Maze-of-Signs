#pragma once
#include <allegro5/allegro.h>

#define CHAO '0'
#define PAREDE '1'
#define PLACAR '6'
#define PORTA 'P'
#define DICA_L 'L'
#define DICA_I 'I'
#define DICA_B 'B'
#define DICA_R 'R'
#define DICA_A 'A'
#define DICA_S 'S'
#define PLACAR_L '3'
#define PLACAR_I '4'
#define PLACAR_B '7'
#define PLACAR_R '8'
#define PLACAR_A '9'
#define PLACAR_S '2'
#define PODER '5'
#define MONSTRO 'M'
#define VERIFICAR 'V'



typedef struct mapa Mapa;

struct mapa {
	char** matriz;
	int qntColunas;
	int qntLinhas;
};

void alocaMapa(Mapa* mapa);
void liberaMapa(Mapa * mapa);
void leMapa(Mapa * mapa);
void desenhaMapa(Mapa*mapa, ALLEGRO_BITMAP *chao, ALLEGRO_BITMAP *parede, ALLEGRO_BITMAP*porta, ALLEGRO_BITMAP *dica, ALLEGRO_BITMAP *poder , ALLEGRO_BITMAP* Placar, ALLEGRO_BITMAP* PlacarL, ALLEGRO_BITMAP* PlacarI, ALLEGRO_BITMAP* PlacarB, ALLEGRO_BITMAP* PlacarR, ALLEGRO_BITMAP* PlacarA);
int ehParede(Mapa* mapa, int posicaoX, int posicaoY);
void ehDica(Mapa* mapa, int posicaoX, int posicaoY);
void ehPoder(Mapa* mapa, int posicaoX, int posicaoY);
int ehMonstro(Mapa* mapa, int posicaoX, int posicaoY);
