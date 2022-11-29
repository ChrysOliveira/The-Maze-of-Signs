#include <allegro5/allegro.h>
#include "../Header Files/Personagem.h"

void movimenta(Mapa* mapa, ALLEGRO_KEYBOARD_STATE keyboardState, Personagem* personagem, ALLEGRO_BITMAP * bitmapChao) {
	
	if (al_key_down(&keyboardState, ALLEGRO_KEY_UP)) {
		
		if (!ehParede(mapa, personagem->personagemPosicaoX, personagem->personagemPosicaoY - 1)) {
			personagem->personagemPosicaoY -= 10;
			personagem->direcaoBitmap = 1;
			desenhaPersonagem(personagem, personagem->personagemPosicaoX, personagem->personagemPosicaoY, personagem->direcaoBitmap);
		}
		else {
			personagem->direcaoBitmap = 1;
			desenhaPersonagem(personagem, personagem->personagemPosicaoX, personagem->personagemPosicaoY, personagem->direcaoBitmap);
		}


		ehDica(mapa, personagem->personagemPosicaoX, personagem->personagemPosicaoY);
		ehPoder(mapa, personagem->personagemPosicaoX, personagem->personagemPosicaoY);
	
	}
	else if (al_key_down(&keyboardState, ALLEGRO_KEY_DOWN)) {
		
		if (!ehParede(mapa, personagem->personagemPosicaoX, personagem->personagemPosicaoY + 41)) {
			personagem->personagemPosicaoY += 10;
			personagem->direcaoBitmap = 2;
			desenhaPersonagem(personagem, personagem->personagemPosicaoX, personagem->personagemPosicaoY, personagem->direcaoBitmap);
		}
		else {
			personagem->direcaoBitmap = 2;
			desenhaPersonagem(personagem, personagem->personagemPosicaoX, personagem->personagemPosicaoY, personagem->direcaoBitmap);
		}

		ehDica(mapa, personagem->personagemPosicaoX, personagem->personagemPosicaoY);
		ehPoder(mapa, personagem->personagemPosicaoX, personagem->personagemPosicaoY);
	}
	else if (al_key_down(&keyboardState, ALLEGRO_KEY_LEFT)) {

		if (!ehParede(mapa, personagem->personagemPosicaoX - 1, personagem->personagemPosicaoY)) {
			personagem->personagemPosicaoX -= 10;
			personagem->direcaoBitmap = 3;
			desenhaPersonagem(personagem, personagem->personagemPosicaoX, personagem->personagemPosicaoY, personagem->direcaoBitmap);
		}
		else {
			personagem->direcaoBitmap = 3;
			desenhaPersonagem(personagem, personagem->personagemPosicaoX, personagem->personagemPosicaoY, personagem->direcaoBitmap);
		}

		ehDica(mapa, personagem->personagemPosicaoX, personagem->personagemPosicaoY);
		ehPoder(mapa, personagem->personagemPosicaoX, personagem->personagemPosicaoY);
	}
	else if (al_key_down(&keyboardState, ALLEGRO_KEY_RIGHT)) {

		if (!ehParede(mapa, personagem->personagemPosicaoX + 41, personagem->personagemPosicaoY)) {
			personagem->personagemPosicaoX += 10;
			personagem->direcaoBitmap = 4;
			desenhaPersonagem(personagem, personagem->personagemPosicaoX, personagem->personagemPosicaoY, personagem->direcaoBitmap);
		}
		else {
			personagem->direcaoBitmap = 4;
			desenhaPersonagem(personagem, personagem->personagemPosicaoX, personagem->personagemPosicaoY, personagem->direcaoBitmap);
		}

		ehDica(mapa, personagem->personagemPosicaoX, personagem->personagemPosicaoY);
		ehPoder(mapa, personagem->personagemPosicaoX, personagem->personagemPosicaoY);
	}else
	{
		ehDica(mapa, personagem->personagemPosicaoX, personagem->personagemPosicaoY);
		ehPoder(mapa, personagem->personagemPosicaoX, personagem->personagemPosicaoY);
	}

}

void desenhaPersonagem(Personagem * personagem, int posicaoX, int posicaoY, int direcao) {

	switch (direcao)
	{
	case 1:
		al_draw_scaled_bitmap(personagem->personagemCima, 0, 0, 40, 40, posicaoX, posicaoY, 40, 40, 0);
	break;

	case 2:
		al_draw_scaled_bitmap(personagem->personagemBaixo, 0, 0, 40, 40, posicaoX, posicaoY, 40, 40, 0);
	break;

	case 3:
		al_draw_scaled_bitmap(personagem->personagemDireita, 0, 0, 40, 40, posicaoX, posicaoY, 40, 40, 0);
	break;

	case 4:
		al_draw_scaled_bitmap(personagem->personagemEsquerda, 0, 0, 40, 40, posicaoX, posicaoY, 40, 40, 0);
	break;
		
	}	
}