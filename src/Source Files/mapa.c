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

void desenhaMapa(Mapa* mapa, ALLEGRO_BITMAP* chao, ALLEGRO_BITMAP* parede, ALLEGRO_BITMAP* porta, ALLEGRO_BITMAP* dica, ALLEGRO_BITMAP* poder, ALLEGRO_BITMAP* Placar, ALLEGRO_BITMAP* PlacarL, ALLEGRO_BITMAP* PlacarI, ALLEGRO_BITMAP* PlacarB, ALLEGRO_BITMAP* PlacarR, ALLEGRO_BITMAP* PlacarA) {

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
			case MONSTRO:
				al_draw_scaled_bitmap(chao, 0, 0, 40, 40, destinoX, destinoY, 40, 40, 0);
				break;
			case PAREDE:
				al_draw_scaled_bitmap(parede, 0, 0, 40, 40, destinoX, destinoY, 40, 40, 0);
			break;
			case PORTA:
				al_draw_scaled_bitmap(porta, 0, 0, 40, 40, destinoX, destinoY, 40, 40, 0);
			break;
			case DICA_L:
				al_draw_scaled_bitmap(dica, 0, 0, 40, 40, destinoX, destinoY, 40, 40, 0);
			break;
			case DICA_I:
				al_draw_scaled_bitmap(dica, 0, 0, 40, 40, destinoX, destinoY, 40, 40, 0);
			break;
			case DICA_B:
				al_draw_scaled_bitmap(dica, 0, 0, 40, 40, destinoX, destinoY, 40, 40, 0);
			break;
			case DICA_R:
				al_draw_scaled_bitmap(dica, 0, 0, 40, 40, destinoX, destinoY, 40, 40, 0);
			break;
			case DICA_A:
				al_draw_scaled_bitmap(dica, 0, 0, 40, 40, destinoX, destinoY, 40, 40, 0);
			break;
			case PLACAR_L:
				al_draw_scaled_bitmap(PlacarL, 0, 0, 40, 40, destinoX, destinoY, 40, 40, 0);
			break;
			case PLACAR_I:
				al_draw_scaled_bitmap(PlacarI, 0, 0, 40, 40, destinoX, destinoY, 40, 40, 0);
			break;
			case PLACAR_B:
				al_draw_scaled_bitmap(PlacarB, 0, 0, 40, 40, destinoX, destinoY, 40, 40, 0);
			break;
			case PLACAR_R:
				al_draw_scaled_bitmap(PlacarR, 0, 0, 40, 40, destinoX, destinoY, 40, 40, 0);
			break;
			case PLACAR_A:
				al_draw_scaled_bitmap(PlacarA, 0, 0, 40, 40, destinoX, destinoY, 40, 40, 0);
			break;
			case PODER:
				al_draw_scaled_bitmap(poder, 0, 0, 40, 40, destinoX, destinoY, 40, 40, 0);
			break;
			case PLACAR:
				al_draw_scaled_bitmap(Placar, 0, 0, 40, 40, destinoX, destinoY, 40, 40, 0);
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

	if (mapa->matriz[x][y] != PAREDE && mapa->matriz[x][y] != PORTA && mapa->matriz[x][y] != PLACAR && mapa->matriz[x][y] != PLACAR_L && mapa->matriz[x][y] != PLACAR_I && mapa->matriz[x][y] != PLACAR_B && mapa->matriz[x][y] != PLACAR_R && mapa->matriz[x][y] != PLACAR_A) {
		return 0;
	}
	
	return 1;
}
//assim que o personagem passar, ir� trocar o valor na matriz de 3 para 0
void ehDica(Mapa* mapa, int posicaoX, int posicaoY) {
	int x = posicaoY / 40;
	int y = posicaoX / 40;
	int aux = 0; 


	switch (mapa->matriz[x][y]) {

	case DICA_L:
		mapa->matriz[x][y] = CHAO;
		for (int i = 0; i < mapa->qntLinhas; i++) {
			for (int j = 0; j < mapa->qntColunas; j++) {
				if (mapa->matriz[i][j] == PLACAR) {
					mapa->matriz[i][j] = PLACAR_L;
					aux = 1;
					break;
				}
			}
			if (aux == 1) {
				break;
			}
		}
		break;
				

	case DICA_I:
		mapa->matriz[x][y] = CHAO;
		for (int i = 0; i < mapa->qntLinhas; i++) {
			for (int j = 0; j < mapa->qntColunas; j++) {
				if (mapa->matriz[i][j] == PLACAR) {
					mapa->matriz[i][j] = PLACAR_I;
					aux = 1;
					break;
				}
			}
			if (aux == 1) {
				break;
			}
		}
		break;

	case DICA_B:
		mapa->matriz[x][y] = CHAO;
		for (int i = 0; i < mapa->qntLinhas; i++) {
			for (int j = 0; j < mapa->qntColunas; j++) {
				if (mapa->matriz[i][j] == PLACAR) {
					mapa->matriz[i][j] = PLACAR_B;
					aux = 1;
					break;
				}
			}
			if (aux == 1) {
				break;
			}
		}
		break;

	case DICA_R:
		mapa->matriz[x][y] = CHAO;
		for (int i = 0; i < mapa->qntLinhas; i++) {
			for (int j = 0; j < mapa->qntColunas; j++) {
				if (mapa->matriz[i][j] == PLACAR) {
					mapa->matriz[i][j] = PLACAR_R;
					aux = 1;
					break;
				}
			}
			if (aux == 1) {
				break;
			}
		}
		break;

	case DICA_A:
		mapa->matriz[x][y] = CHAO;
		for (int i = 0; i < mapa->qntLinhas; i++) {
			for (int j = 0; j < mapa->qntColunas; j++) {
				if (mapa->matriz[i][j] == PLACAR) {
					mapa->matriz[i][j] = PLACAR_A;
					aux = 1;
					break;
				}
			}
			if (aux == 1) {
				break;
			}
		}
		break;
	}
}

//assim que o personagem passar, ir� trocar o valor na matriz de 5 para 0
void ehPoder(Mapa* mapa, int posicaoX, int posicaoY) {
	int x = posicaoY / 40;
	int y = posicaoX / 40;

	if (mapa->matriz[x][y] == PODER) {
		mapa->matriz[x][y] = CHAO;

	}
}

int ehMonstro(Mapa* mapa, int posicaoX, int posicaoY) {
	int x = posicaoY / 40;
	int y = posicaoX / 40;

	if (mapa->matriz[x][y] == MONSTRO) {
		return 1;
	}

	return 0;
}