#pragma once

typedef struct Personagem Personagem;

struct Personagem {
	ALLEGRO_BITMAP* personagemBitmap;
	int personagemPosicaoX;
	int personagemPosicaoY;
};

void movimenta(ALLEGRO_KEYBOARD_STATE keyboardState, Personagem* personagem);
void desenhaPersonagem(Personagem* personagem);