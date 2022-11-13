#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "../Header Files/Electale.h"
#include "../Header Files/Personagem.h"

void removeComponentes(ALLEGRO_DISPLAY* display,Personagem* personagem,ALLEGRO_EVENT_QUEUE* queue,ALLEGRO_TIMER* timer, Mapa mapa) {
	al_uninstall_keyboard();
	al_destroy_display(display);
	al_destroy_bitmap(personagem->personagemCima);
	al_destroy_event_queue(queue);
	al_destroy_timer(timer);
	void liberaMapa(mapa);
}

void registraEventosNaFila(ALLEGRO_EVENT_QUEUE* queue, ALLEGRO_DISPLAY* display, ALLEGRO_TIMER* timer) {
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_timer_event_source(timer));
}

int main(){

	Personagem personagem;
	Mapa mapa;

	ALLEGRO_BITMAP* bitmapChao;
	ALLEGRO_BITMAP* bitmapParede;
	ALLEGRO_BITMAP* bitmapPorta;
	ALLEGRO_BITMAP* bitmapDica;
	ALLEGRO_BITMAP* bitmapPoder;
	ALLEGRO_BITMAP* bitmapPlacar;
	ALLEGRO_BITMAP* bitmapPlacarL;
	ALLEGRO_BITMAP* bitmapPlacarI;
	ALLEGRO_BITMAP* bitmapPlacarB;
	ALLEGRO_BITMAP* bitmapPlacarR;
	ALLEGRO_BITMAP* bitmapPlacarA;
	ALLEGRO_DISPLAY* display;
	ALLEGRO_EVENT_QUEUE * filaEventos;
	ALLEGRO_TIMER* timer;
	ALLEGRO_KEYBOARD_STATE keyboardState;

	ALLEGRO_BITMAP* personagemBaixo;
	ALLEGRO_BITMAP* personagemCima;
	ALLEGRO_BITMAP* personagemEsqueda;
	ALLEGRO_BITMAP* personagemDireita;
	
	al_init();
	al_init_image_addon();
	al_install_keyboard();

	display = al_create_display(1280, 960);

	filaEventos = al_create_event_queue();

	timer = al_create_timer(1 / 60.0);

	personagem.personagemBaixo= al_load_bitmap("../../assets/bitmaps/personagemBaixo.png");
	personagem.personagemCima = al_load_bitmap("../../assets/bitmaps/personagemCima.png");
	personagem.personagemEsquerda = al_load_bitmap("../../assets/bitmaps/personagemEsquerda.png");
	personagem.personagemDireita = al_load_bitmap("../../assets/bitmaps/personagemDireita.png");
	personagem.personagemPosicaoX = 40;
	personagem.personagemPosicaoY = 40;

	bitmapChao = al_load_bitmap("../../assets/bitmaps/chao.png");
	bitmapParede = al_load_bitmap("../../assets/bitmaps/parede.png");
	bitmapPorta = al_load_bitmap("../../assets/bitmaps/porta.png");
	bitmapDica = al_load_bitmap("../../assets/bitmaps/dica.png");
	bitmapPoder = al_load_bitmap("../../assets/bitmaps/poder.png");
	bitmapPlacar = al_load_bitmap("../../assets/bitmaps/placar.png");
	bitmapPlacarL = al_load_bitmap("../../assets/bitmaps/L.png");
	bitmapPlacarI = al_load_bitmap("../../assets/bitmaps/I.png");
	bitmapPlacarB = al_load_bitmap("../../assets/bitmaps/B.png");
	bitmapPlacarR = al_load_bitmap("../../assets/bitmaps/R.png");
	bitmapPlacarA = al_load_bitmap("../../assets/bitmaps/A.png");

	leMapa(&mapa);

	registraEventosNaFila(filaEventos, display, timer);

	desenhaMapa(&mapa, bitmapChao, bitmapParede, bitmapPorta, bitmapDica, bitmapPoder, bitmapPlacar, bitmapPlacarL, bitmapPlacarI, bitmapPlacarB, bitmapPlacarR, bitmapPlacarA);
	desenhaPersonagem(&personagem,personagem.personagemPosicaoX,personagem.personagemPosicaoY, 2);


	while (1) {

		al_flip_display();


		desenhaMapa(&mapa, bitmapChao, bitmapParede, bitmapPorta, bitmapDica, bitmapPoder, bitmapPlacar, bitmapPlacarL, bitmapPlacarI, bitmapPlacarB, bitmapPlacarR, bitmapPlacarA);

		ALLEGRO_EVENT evento;
		
		al_get_keyboard_state(&keyboardState);

		al_wait_for_event(filaEventos, &evento);

		if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			exit(1);
		}

		movimenta(&mapa, keyboardState, &personagem);
	}
	
	removeComponentes(display, &personagem, filaEventos, timer, mapa);
	
}

