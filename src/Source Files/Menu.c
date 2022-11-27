#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

void desenhaMenu(ALLEGRO_BITMAP *fundo, ALLEGRO_FONT *fonte) {
        
        al_flip_display();

        al_draw_scaled_bitmap(fundo, 0, 0, 1280, 960, 0, 0, 1280, 960, 0);

        al_draw_text(fonte, al_map_rgb(255, 255, 255), 640, 580, ALLEGRO_ALIGN_CENTER, "Press Enter to start");
        al_draw_text(fonte, al_map_rgb(255, 255, 255), 640, 680, ALLEGRO_ALIGN_CENTER, "Press E to exit");

}