#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <stdlib.h>
#include <stdio.h>
#include "../Header Files/mapa.h"


void alocaMapa(Mapa* mapa) {

	mapa->matriz = (char**)malloc(sizeof(char*) * mapa->qntLinhas);

	for (int i = 0; i < mapa->qntLinhas; i++)
	{
		mapa->matriz[i] = (char*) malloc(sizeof(char*) * mapa->qntColunas + 1);
	}
}

void liberaMapa(Mapa* mapa) {
	for (int i = 0; i < mapa->qntLinhas; i++)
	{
		free(mapa->matriz[i]);
	}
	free(mapa->matriz);
}

void leMapa(Mapa* mapa) {
	
	FILE* f = fopen("../../assets/mapasEmTxt/mapaGrazi.txt", "r");
	
	if (f == 0) {
		printf("Nao foi possivel ler o arquivo do mapa!\n");
		exit(1);
	}

	fscanf(f, "%d %d", &mapa->qntLinhas, &mapa->qntColunas);

	alocaMapa(mapa);

	for (int i = 0; i < mapa->qntLinhas; i++)
	{
		fscanf(f, "%s", mapa->matriz[i]);
	}

	fclose(f);
}

void desenhaMapa(Mapa*mapa, ALLEGRO_BITMAP *chao, ALLEGRO_BITMAP*parede, ALLEGRO_BITMAP *dica, ALLEGRO_BITMAP *poder) {

	int destinoX = 0;
	int destinoY = 0;

	for (int i = 0; i < mapa->qntLinhas; i++)
	{
		for (int j = 0; j < mapa->qntColunas; j++)
		{
			switch (mapa->matriz[i][j]) {
			case CHAO:
				al_draw_scaled_bitmap(chao, 0, 0, 40, 40, destinoX, destinoY, 40, 40, 0);
			break;
			case PAREDE:
				al_draw_scaled_bitmap(parede, 0, 0, 40, 40, destinoX, destinoY, 40, 40, 0);
			break;
			case DICA:
				al_draw_scaled_bitmap(dica, 0, 0, 40, 40, destinoX, destinoY, 40, 40, 0);
			break;
			case PODER:
				al_draw_scaled_bitmap(poder, 0, 0, 40, 40, destinoX, destinoY, 40, 40, 0);
			
				break;
			}
			destinoX += 40;
		}
		destinoX = 0;
		destinoY += 40;
	}
}

int ehParede(Mapa * mapa, int posicaoX, int posicaoY) {

	int x =  posicaoY / 40;
	int y = posicaoX / 40;

	if (mapa->matriz[x][y] != PAREDE && mapa->matriz[x][y] != PORTA) {
		return 0;
	}
	
	return 1;
}
//assim que o personagem passar, irá trocar o valor na matriz de 3 para 0
void ehDica(Mapa* mapa, int posicaoX, int posicaoY) {
	int x = posicaoY / 40;
	int y = posicaoX / 40;

	if (mapa->matriz[x][y] == DICA) {
		mapa->matriz[x][y] = CHAO;
	}
}

//assim que o personagem passar, irá trocar o valor na matriz de 5 para 0
void ehPoder(Mapa* mapa, int posicaoX, int posicaoY) {
	int x = posicaoY / 40;
	int y = posicaoX / 40;

	if (mapa->matriz[x][y] == PODER) {
		mapa->matriz[x][y] = CHAO;
	}
}

