#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "mapa.h"

typedef struct Personagem Personagem;

struct Personagem {
	ALLEGRO_BITMAP* personagemBitmap;
	int personagemPosicaoX;
	int personagemPosicaoY;
};

void movimenta(Mapa* mapa, ALLEGRO_KEYBOARD_STATE keyboardState, Personagem* personagem, ALLEGRO_BITMAP * bitmapChao);
void desenhaPersonagem(Personagem* personagem, int posicaoX, int posicaoY);


