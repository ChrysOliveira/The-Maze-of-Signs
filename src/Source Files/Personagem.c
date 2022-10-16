#include <allegro5/allegro.h>
#include "../Header Files/Personagem.h"

void movimenta(ALLEGRO_KEYBOARD_STATE keyboardState,Personagem* personagem) {

	if (al_key_down(&keyboardState, ALLEGRO_KEY_UP)) {	
		personagem->personagemPosicaoY -= 10;
		al_draw_scaled_bitmap(personagem->personagemBitmap, 50, 50, 40, 40, personagem->personagemPosicaoX, personagem->personagemPosicaoY, 40, 40, 0);
	}
	else if (al_key_down(&keyboardState, ALLEGRO_KEY_DOWN)) {
		personagem->personagemPosicaoY += 10;
		al_draw_scaled_bitmap(personagem->personagemBitmap, 50, 50, 40, 40, personagem->personagemPosicaoX, personagem->personagemPosicaoY, 40, 40, 0);

	}
	else if (al_key_down(&keyboardState, ALLEGRO_KEY_LEFT)) {
		personagem->personagemPosicaoX -= 10;
		al_draw_scaled_bitmap(personagem->personagemBitmap, 50, 50, 40, 40, personagem->personagemPosicaoX, personagem->personagemPosicaoY, 40, 40, 0);

	}
	else if (al_key_down(&keyboardState, ALLEGRO_KEY_RIGHT)) {
		personagem->personagemPosicaoX += 10;
		al_draw_scaled_bitmap(personagem->personagemBitmap, 50, 50, 40, 40, personagem->personagemPosicaoX, personagem->personagemPosicaoY, 40, 40, 0);
	}
}

void desenhaPersonagem(Personagem * personagem) {
	al_draw_scaled_bitmap(personagem->personagemBitmap, 50, 50, 50, 50, 0, 0, 50, 50, 0);
}