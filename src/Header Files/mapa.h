#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

typedef struct mapa MAPA;

struct mapa {
	char** matriz;
	int qntColunas;
	int qntLinhas;
};

