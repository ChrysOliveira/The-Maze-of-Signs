#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "../Header Files/Electale.h"
#include "../Header Files/Personagem.h"

void removeComponentes(ALLEGRO_DISPLAY* display,Personagem* personagem,ALLEGRO_EVENT_QUEUE* queue,ALLEGRO_TIMER* timer) {
	al_uninstall_keyboard();
	al_destroy_display(display);
	al_destroy_bitmap(personagem->personagemBitmap);
	al_destroy_event_queue(queue);
	al_destroy_timer(timer);
}

void registraEventosNaFila(ALLEGRO_EVENT_QUEUE* queue, ALLEGRO_DISPLAY* display, ALLEGRO_TIMER* timer) {
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_timer_event_source(timer));
}

int main(){

	Personagem personagem;
	ALLEGRO_DISPLAY* display;
	ALLEGRO_EVENT_QUEUE * filaEventos;
	ALLEGRO_TIMER* timer;
	ALLEGRO_KEYBOARD_STATE keyboardState;
	
	al_init();
	al_init_image_addon();
	al_install_keyboard();

	display = al_create_display(800, 640);

	filaEventos = al_create_event_queue();

	timer = al_create_timer(1 / 60.0);

	personagem.personagemBitmap = al_load_bitmap("../../assets/bitmaps/abc.png");
	personagem.personagemPosicaoX = 0;
	personagem.personagemPosicaoY = 0;
	
	registraEventosNaFila(filaEventos, display, timer);

	desenhaPersonagem(&personagem);


	while (1) {

		al_flip_display();

		al_clear_to_color(al_map_rgb(0, 0, 0));

		ALLEGRO_EVENT evento;
		
		al_get_keyboard_state(&keyboardState);

		al_wait_for_event(filaEventos, &evento);

		if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			exit(1);
		}

		movimenta(keyboardState, &personagem);
	}
	
	removeComponentes(display, &personagem, filaEventos, timer);
	
}

