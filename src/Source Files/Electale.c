#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "../Header Files/Electale.h"
#include "../Header Files/Personagem.h"
#include "../Header Files/Monstro.h"

void removeComponentes(ALLEGRO_DISPLAY* display,Personagem* personagem,ALLEGRO_EVENT_QUEUE* queue,ALLEGRO_TIMER* timer, Mapa mapa, Monstro * monstros) {
	al_uninstall_keyboard();
	al_destroy_display(display);
	al_destroy_bitmap(personagem->personagemBitmap);
	al_destroy_event_queue(queue);
	al_destroy_timer(timer);
	liberaMapa(&mapa);
	desalocaMonstros(monstros);
}

void registraEventosNaFila(ALLEGRO_EVENT_QUEUE* queue, ALLEGRO_DISPLAY* display, ALLEGRO_TIMER* timer) {
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_timer_event_source(timer));
}

int main(){

	Personagem personagem;
	Mapa mapa;
	Monstro monstros;
	ALLEGRO_BITMAP* bitmapMapa;

	ALLEGRO_BITMAP* bitmapChao;
	ALLEGRO_BITMAP* bitmapParede;
	ALLEGRO_BITMAP* bitmapDica;
	ALLEGRO_BITMAP* bitmapSemDica;
	ALLEGRO_BITMAP* bitmapPoder;
	ALLEGRO_DISPLAY* display;
	ALLEGRO_EVENT_QUEUE * filaEventos;
	ALLEGRO_TIMER* timer;
	ALLEGRO_KEYBOARD_STATE keyboardState;
	
	al_init();
	al_init_image_addon();
	al_install_keyboard();

	srand(time(0));

	display = al_create_display(1280, 960);

	filaEventos = al_create_event_queue();

	timer = al_create_timer(1 / 15.0);
	al_start_timer(timer);

	personagem.personagemBitmap = al_load_bitmap("../../assets/bitmaps/abc.png");
	personagem.personagemPosicaoX = 40;
	personagem.personagemPosicaoY = 40;

	bitmapChao = al_load_bitmap("../../assets/bitmaps/chao.png");
	bitmapParede = al_load_bitmap("../../assets/bitmaps/parede.png");
	bitmapDica = al_load_bitmap("../../assets/bitmaps/dica.png");
	bitmapSemDica = al_load_bitmap("../../assets/bitmaps/semDica.png");
	bitmapPoder = al_load_bitmap("../../assets/bitmaps/poder.png");


	leMapa(&mapa);

	//pega a qnt de monstros no mapa
	int qntMonstros = quantidadeMonstros(&mapa);
	//grava as posicoes dos monstros
	alocaMonstros(&monstros, qntMonstros);
	localizaMonstros(&mapa,&monstros,qntMonstros);

	

	registraEventosNaFila(filaEventos, display, timer);

	desenhaMapa(&mapa, bitmapChao, bitmapParede, bitmapDica, bitmapPoder);
	desenhaPersonagem(&personagem,personagem.personagemPosicaoX,personagem.personagemPosicaoY);

	desenhaMonstros(&monstros, qntMonstros);
	
	while (1) {

		al_flip_display();


		desenhaMapa(&mapa, bitmapChao, bitmapParede, bitmapDica, bitmapPoder);

		ALLEGRO_EVENT evento;
		
		
		al_get_keyboard_state(&keyboardState);

		al_wait_for_event(filaEventos, &evento);

		if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			exit(1);
		}

		if(evento.type == ALLEGRO_EVENT_TIMER)
		{
			movimentaMonstros(&mapa,&monstros,qntMonstros);
		}
		movimenta(&mapa, keyboardState, &personagem);
	}
	
	removeComponentes(display, &personagem, filaEventos, timer, mapa, &monstros);
	
}
