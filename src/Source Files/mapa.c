#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <stdlib.h>
#include <stdio.h>
#include "../Header Files/mapa.h"

void alocaMapa(Mapa* mapa) {

	mapa->matriz = (int*)malloc(sizeof(int*) * mapa->qntLinhas);

	for (int i = 0; i < mapa->qntLinhas; i++)
	{
		mapa->matriz[i] = (int*) malloc(sizeof(int*) * mapa->qntColunas + 1);
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
	
	FILE* f = fopen("../../assets/mapasEmTxt/mapa1.txt", "r");
	
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

void desenhaMapa(Mapa*mapa, ALLEGRO_BITMAP *bitmap) {

	int destinoX = 0;
	int destinoY = 0;

	for (int i = 0; i < mapa->qntLinhas; i++)
	{
		for (int j = 0; j < mapa->qntColunas; j++)
		{
			switch (mapa->matriz[i][j]) {
			case CHAO:
				al_draw_scaled_bitmap(bitmap, 0, 0, 40, 40, destinoX, destinoY, 40, 40, 0);
			}
			destinoX += 40;
		}
		destinoX = 0;
		destinoY += 40;
	}
}