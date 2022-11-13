#include <allegro5/allegro.h>
#include "../Header Files/Personagem.h"

void movimenta(Mapa* mapa, ALLEGRO_KEYBOARD_STATE keyboardState,Personagem* personagem ) {

	int pos = 0;

	if (al_key_down(&keyboardState, ALLEGRO_KEY_UP)) {

		//CODIGO PARA DEBUGAR A MOVIMENTACAO
		/*printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
		printf("Personagem: atualX:%d atualY:%d\nVai pra   : novoX:%d novoY:%d\n\n",
			personagem->personagemPosicaoX, personagem->personagemPosicaoY, personagem->personagemPosicaoX, personagem->personagemPosicaoY - 1);

		int x = (personagem->personagemPosicaoY - 1) / 40; 
		int y = personagem->personagemPosicaoX / 40;

		printf("Para o eh parede x=%d  e y=%d\n", x, y);

		printf("Na matriz=>%c\n", mapa->matriz[x][y]);

		printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");*/

		if (!ehParede(mapa, personagem->personagemPosicaoX, personagem->personagemPosicaoY - 1)) {
			personagem->personagemPosicaoY -= 10;
			pos = 1;
			desenhaPersonagem(personagem, personagem->personagemPosicaoX, personagem->personagemPosicaoY, pos);
		}
		else {
			pos = 1;
			desenhaPersonagem(personagem, personagem->personagemPosicaoX, personagem->personagemPosicaoY, pos);
		}

		ehDica(mapa, personagem->personagemPosicaoX, personagem->personagemPosicaoY);
		ehPoder(mapa, personagem->personagemPosicaoX, personagem->personagemPosicaoY);
	
	}

	else if (al_key_down(&keyboardState, ALLEGRO_KEY_DOWN)) {

		//CODIGO PARA DEBUGAR A MOVIMENTACAO
		/*printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
		printf("Personagem: atualX:%d atualY:%d\nVai pra   : novoX:%d novoY:%d\n\n",
			personagem->personagemPosicaoX, personagem->personagemPosicaoY, personagem->personagemPosicaoX, personagem->personagemPosicaoY + 41);

		int x = (personagem->personagemPosicaoY + 41) / 40;
		int y = personagem->personagemPosicaoX / 40;

		printf("Para o eh parede x=%d  e y=%d\n", x, y);

		printf("Na matriz=>%c\n", mapa->matriz[x][y]);
		printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");*/

		if (!ehParede(mapa, personagem->personagemPosicaoX, personagem->personagemPosicaoY + 41)) {
			personagem->personagemPosicaoY += 10;
			pos = 2;
			desenhaPersonagem(personagem, personagem->personagemPosicaoX, personagem->personagemPosicaoY, pos);
		}
		else {
			pos = 2;
			desenhaPersonagem(personagem, personagem->personagemPosicaoX, personagem->personagemPosicaoY, pos);
		}

		ehDica(mapa, personagem->personagemPosicaoX, personagem->personagemPosicaoY);
		ehPoder(mapa, personagem->personagemPosicaoX, personagem->personagemPosicaoY);

	}
	else if (al_key_down(&keyboardState, ALLEGRO_KEY_LEFT)) {

		//CODIGO PARA DEBUGAR A MOVIMENTACAO
		/*printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
		printf("Personagem: atualX:%d atualY:%d\nVai pra   : novoX:%d novoY:%d\n\n",
			personagem->personagemPosicaoX, personagem->personagemPosicaoY, personagem->personagemPosicaoX-1, personagem->personagemPosicaoY);

		int x = personagem->personagemPosicaoY / 40; 
		int y = (personagem->personagemPosicaoX - 1) / 40;

		printf("Para o eh parede x=%d  e y=%d\n", x, y);

		printf("Na matriz=>%c\n", mapa->matriz[x][y]);
		printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");*/

		if (!ehParede(mapa, personagem->personagemPosicaoX - 1, personagem->personagemPosicaoY)) {
			personagem->personagemPosicaoX -= 10;
			pos = 3;
			desenhaPersonagem(personagem, personagem->personagemPosicaoX, personagem->personagemPosicaoY, pos);
		}
		else {
			pos = 3;
			desenhaPersonagem(personagem, personagem->personagemPosicaoX, personagem->personagemPosicaoY, pos);
		}

		ehDica(mapa, personagem->personagemPosicaoX, personagem->personagemPosicaoY);
		ehPoder(mapa, personagem->personagemPosicaoX, personagem->personagemPosicaoY);

	}
	else if (al_key_down(&keyboardState, ALLEGRO_KEY_RIGHT)) {

		//CODIGO PARA DEBUGAR A MOVIMENTACAO
		/*printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
		printf("Personagem: atualX:%d atualY:%d\nVai pra   : novoX:%d novoY:%d\n\n",
			personagem->personagemPosicaoX, personagem->personagemPosicaoY, personagem->personagemPosicaoX + 41, personagem->personagemPosicaoY);

		int x = personagem->personagemPosicaoY / 40; 
		int y = (personagem->personagemPosicaoX + 41) / 40;

		printf("Para o eh parede x=%d  e y=%d\n", x, y);

		printf("Na matriz=>%c\n", mapa->matriz[x][y]);
		printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");*/

		if (!ehParede(mapa, personagem->personagemPosicaoX + 41, personagem->personagemPosicaoY)) {
			personagem->personagemPosicaoX += 10;
			pos = 4;
			desenhaPersonagem(personagem, personagem->personagemPosicaoX, personagem->personagemPosicaoY, pos);
		}
		else {
			pos = 4;
			desenhaPersonagem(personagem, personagem->personagemPosicaoX, personagem->personagemPosicaoY, pos);
		}

		ehDica(mapa, personagem->personagemPosicaoX, personagem->personagemPosicaoY);
		ehPoder(mapa, personagem->personagemPosicaoX, personagem->personagemPosicaoY);

	}
}

void desenhaPersonagem(Personagem * personagem, int posicaoX, int posicaoY, int pos) {

	switch (pos)
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