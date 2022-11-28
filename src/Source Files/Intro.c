#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

void desenhaIntro(ALLEGRO_BITMAP* img, ALLEGRO_FONT* fonte) {

	al_flip_display();

	al_draw_scaled_bitmap(img, 0, 0, 1280, 960, 0, 0, 1280, 960, 0);

	al_draw_text(fonte, al_map_rgb(255, 255, 255), 640, 580, ALLEGRO_ALIGN_CENTER, "Nosso personagem principal fulano, é um forte guerreiro do reino das Libras. Nesse mundo tudo é controlado e feito através da língua de sinais.");
	al_draw_text(fonte, al_map_rgb(255, 255, 255), 640, 580, ALLEGRO_ALIGN_CENTER, "O banco de dados central do reino foi roubado pelo líder separatista, Beltrano e Seu trabalho é atravessar o labirinto dele e encontrar todas as letras e formar as palavras para reinstaurar a banco do reino.");
	al_draw_text(fonte, al_map_rgb(255, 255, 255), 640, 580, ALLEGRO_ALIGN_CENTER, "Não esqueça de evitar os monstros, e, caso precise, poderes que te dão a habilidade de destruir os monstros foram espalhados pelo labirinto.");
	al_draw_text(fonte, al_map_rgb(255, 255, 255), 640, 580, ALLEGRO_ALIGN_CENTER, "Recupere as letras e fuja de beltrano!");
}