#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <stdlib.h>
#include <stdio.h>
#include "../Header Files/mapa.h"

void alocaMapa(MAPA* mapa) {

	mapa->matriz = (int*)malloc(sizeof(int*) * mapa->qntLinhas);

	for (int i = 0; i < mapa->qntLinhas; i++)
	{
		mapa->matriz[i] = (int*) malloc(sizeof(int*) * mapa->qntColunas + 1);
	}
}

void liberaMapa(MAPA* mapa) {
	for (int i = 0; i < mapa->qntLinhas; i++)
	{
		free(mapa->matriz[i]);
	}
	free(mapa->matriz);
}

void leMapa(MAPA* mapa) {
	
	FILE* f = fopen("mapa.txt", "r");
	
	if (f == 0) {
		printf("Nao foi possivel ler o arquivo do mapa!\n");
		exit(1);
	}

	fscanf(f, "%d %d", &mapa->qntColunas, &mapa->qntLinhas);

	alocaMapa(mapa);

	for (int i = 0; i < mapa->qntLinhas; i++)
	{
		fscanf(f, "%s", mapa->matriz[i]);
	}
	
	fclose(f);
}