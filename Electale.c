#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

int main()
{
	al_init();
	al_init_image_addon();

	ALLEGRO_DISPLAY* display;
	ALLEGRO_BITMAP* bitmap;

	display = al_create_display(800, 640);
	bitmap = al_load_bitmap("./bitmaps/abc.png");

	al_draw_scaled_bitmap(bitmap, 50, 50, 400,400,0,0,800,640,0);

	while (1) {
		al_flip_display();
	}

	al_destroy_display(display);
	al_destroy_bitmap(bitmap);

}

