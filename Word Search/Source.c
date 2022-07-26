#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<allegro5/allegro.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_ttf.h>
#include<allegro5/allegro_primitives.h>
#include<allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include<allegro5/allegro_acodec.h>



int main() {
	int w = 600, h = 800;
	double x = 300, y = 400;
	double mx=0, my=0;
	int zaman = 100, score = 0;
	int sayac = 0,sayac2=0;
	int count = 0;
	
	int KELIME[12];
	int RENK[12];
	for (int i = 0;i < 12;i++) {
		KELIME[i] = 0;
		RENK[i] = 0;
	}
	int turba2 = 0, turba3 = 0, turba4 = 0, mahrum2 = 0, kubali2 = 0;

	al_init();
	al_init_image_addon();
	
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_audio();
	al_init_acodec_addon();
	al_init_primitives_addon();
	
	al_install_keyboard();
	al_install_mouse();


	ALLEGRO_SAMPLE *soundEffect = al_load_sample("Heartbeat.wav");
	ALLEGRO_SAMPLE *soundEffect2 = al_load_sample("tada.wav");
	ALLEGRO_SAMPLE *soundEffect3 = al_load_sample("tick.wav");
	ALLEGRO_SAMPLE *soundEffect4 = al_load_sample("gameover.wav");
	ALLEGRO_SAMPLE *soundEffect5 = al_load_sample("arka.wav");
	ALLEGRO_DISPLAY *display = al_create_display(w, h);
	ALLEGRO_EVENT_QUEUE*event_queue = al_create_event_queue();
	ALLEGRO_TIMER*timer = al_create_timer(1.0 / 60);
	ALLEGRO_BITMAP *background = al_load_bitmap("background.png");
	ALLEGRO_BITMAP *wordgame = al_load_bitmap("wordgame.png");
	ALLEGRO_BITMAP *wordgame2 = al_load_bitmap("wordgame2.png");
	ALLEGRO_BITMAP *gameover = al_load_bitmap("gameover.png");
	ALLEGRO_BITMAP *start = al_load_bitmap("start.png");
	ALLEGRO_BITMAP *winner = al_load_bitmap("winner.png");
	ALLEGRO_BITMAP *tekrar = al_load_bitmap("tekrar.png");
	ALLEGRO_BITMAP *image = al_load_bitmap("mouse2.png");
	ALLEGRO_FONT *font48 = al_load_font("arial.ttf", 48, 0);
	ALLEGRO_FONT *font20 = al_load_font("arial.ttf", 20, 0);
	
	
	al_reserve_samples(2);

	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_set_timer_speed(timer, 1);
	al_start_timer(timer);
	al_hide_mouse_cursor(display);
	

	time_t basla;
	time_t bit;
	
	
	
	
	
			while (sayac2==0) {                         // ----------------------------------ANAMENU ----------------------------------------------------
				ALLEGRO_EVENT ev;
				
				al_wait_for_event_timed(event_queue, &ev, 0.1);

				if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
					if (ev.mouse.button & 1) {
						mx = ev.mouse.x;
						my = ev.mouse.y;
					}
				}
				else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES) {
					x = ev.mouse.x;
					y = ev.mouse.y;
				}
				else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
					al_destroy_bitmap(image);
					al_destroy_bitmap(background);
					al_destroy_bitmap(wordgame);
					al_destroy_bitmap(wordgame2);
					al_destroy_bitmap(gameover);
					al_destroy_bitmap(start);
					al_destroy_bitmap(tekrar);
					al_destroy_bitmap(winner);
					al_destroy_event_queue(event_queue);
					al_destroy_timer(timer);
					al_destroy_font(font20);
					al_destroy_font(font48);
					al_destroy_sample(soundEffect);
					al_destroy_sample(soundEffect2);
					al_destroy_sample(soundEffect3);
					al_destroy_sample(soundEffect4);
					al_destroy_sample(soundEffect5);
					al_destroy_display(display);
					return 0;
				}                                                                   
				if (mx <= 367 && mx >= 229 && my <= 638 && my >= 588) {
					al_destroy_bitmap(image);
					al_destroy_bitmap(background);
					al_destroy_bitmap(wordgame);
					al_destroy_bitmap(wordgame2);
					al_destroy_bitmap(gameover);
					al_destroy_bitmap(start);
					al_destroy_bitmap(tekrar);
					al_destroy_bitmap(winner);
					al_destroy_event_queue(event_queue);
					al_destroy_timer(timer);
					al_destroy_font(font20);
					al_destroy_font(font48);
					al_destroy_sample(soundEffect);
					al_destroy_sample(soundEffect2);
					al_destroy_sample(soundEffect3);
					al_destroy_sample(soundEffect4);
					al_destroy_sample(soundEffect5);
					al_destroy_display(display);
					return 0;
				
				}
				
				if (count == 0) {
					al_play_sample(soundEffect5, 0.5, 0, 1, ALLEGRO_PLAYMODE_LOOP, NULL);
					count = 1;
				}
				if (mx <= 367 && mx >= 229 && my <= 538 && my >= 488) {
					al_stop_samples();
					sayac2 = 1;
					count = 0;
					time(&basla);
					mx = 0;
					my = 0;
					
				}
				
				al_draw_bitmap(background, 0, 0, 5);
				al_draw_bitmap(wordgame2, 145, 35, 0);
				al_draw_bitmap(wordgame, 210, 295, 0);
				
				
				al_draw_bitmap(start, 229, 488, 0);
				al_draw_textf(font20, al_map_rgb(0, 0, 0), 265, 500, 0, "BASLA");
                al_draw_bitmap(start, 229, 588, 0);
				al_draw_textf(font20, al_map_rgb(0, 0, 0), 270, 600, 0, "CIKIS");
				
				
				
				
				al_draw_bitmap(image, x-65, y-65, 5);
				al_flip_display();
				
				
					
				
				
				

			}                    //-----------------------------------------------------------------------------------------------------------------------------------------------------
		
			while (sayac2 == 1) {  // ------------------------------------------------------OYUN ----------------------------------------------------------------------------------------------
				time(&bit);

				ALLEGRO_EVENT ev;

				al_wait_for_event_timed(event_queue, &ev, 0.20);




				if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
					al_destroy_bitmap(image);
					al_destroy_bitmap(background);
					al_destroy_bitmap(wordgame);
					al_destroy_bitmap(wordgame2);
					al_destroy_bitmap(gameover);
					al_destroy_bitmap(start);
					al_destroy_bitmap(tekrar);
					al_destroy_bitmap(winner);
					al_destroy_event_queue(event_queue);
					al_destroy_timer(timer);
					al_destroy_font(font20);
					al_destroy_font(font48);
					al_destroy_sample(soundEffect);
					al_destroy_sample(soundEffect2);
					al_destroy_sample(soundEffect3);
					al_destroy_sample(soundEffect4);
					al_destroy_sample(soundEffect5);
					al_destroy_display(display);
					return 0;
				}
				if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
					if (ev.mouse.button & 1) {
						mx = ev.mouse.x;
						my = ev.mouse.y;
					}
				}
				else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES) {
					x = ev.mouse.x;
					y = ev.mouse.y;
				}

				else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
					if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
						al_destroy_bitmap(image);
						al_destroy_bitmap(background);
						al_destroy_bitmap(wordgame);
						al_destroy_bitmap(wordgame2);
						al_destroy_bitmap(gameover);
						al_destroy_bitmap(start);
						al_destroy_bitmap(tekrar);
						al_destroy_bitmap(winner);
						al_destroy_event_queue(event_queue);
						al_destroy_timer(timer);
						al_destroy_font(font20);
						al_destroy_font(font48);
						al_destroy_sample(soundEffect);
						al_destroy_sample(soundEffect2);
						al_destroy_sample(soundEffect3);
						al_destroy_sample(soundEffect4);
						al_destroy_sample(soundEffect5);
						al_destroy_display(display);
						return 0;
					}



				}
				if (mx <= 152 && mx >= 80 && my <= 440 && my >= 380) { //M 1x1

					if (ev.mouse.button & 1) {

						mx = 0;
						my = 0;

						for (int i = 0;i < 12;i++) {
							KELIME[i] = 0;
						}
						turba2 = 0, turba3 = 0, turba4 = 0, mahrum2 = 0, kubali2 = 0;
						mahrum2 = 1;
						KELIME[3] = 1;
					}

				}
				if (mx <= 150 && mx >= 80 && my <= 520 && my >= 460) { //A 2x1

					if (ev.mouse.button & 1) {

						mx = 0;
						my = 0;
						if (KELIME[3] == 1) {
							KELIME[3]++;
							mahrum2++;

						}
						else if (KELIME[0] == 1) {
							KELIME[0]++;
						}
						else if (KELIME[5] == 4) {
							KELIME[5] = 0;
							if (RENK[5] == 0) {
								score += 10;
								al_play_sample(soundEffect3, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
							}
							RENK[5] = 1;
							printf("TURBA\n");


						}
						else if (turba2 == 4) {
							turba2 = 0;
							if (RENK[5] == 0) {
								score += 10;
								al_play_sample(soundEffect3, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
							}
							RENK[5] = 1;
							printf("TURBA\n");
						}
						else if (KELIME[6] == 1) {
							KELIME[6]++;
						}
						else {
							for (int i = 0;i < 12;i++) {
								KELIME[i] = 0;
							}
							turba2 = 0, turba3 = 0, turba4 = 0, mahrum2 = 0, kubali2 = 0;
						}
					}

				}
				if (mx <= 150 && mx >= 80 && my <= 600 && my >= 540) { // I 3x1

					if (ev.mouse.button & 1) {

						mx = 0;
						my = 0;
						if (KELIME[0] == 7) {
							KELIME[0]++;
						}
						else if (KELIME[6] == 4) {
							KELIME[6] = 0;
							printf("HARLI\n");
							if (RENK[6] == 0) {
								score += 10;
								al_play_sample(soundEffect3, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
							}
							RENK[6] = 1;
						}
						else if (KELIME[7] == 3) {
							KELIME[7]++;
						}
						else if (KELIME[9] == 3) {
							KELIME[9] = 0;
							printf("RAKI\n");
							if (RENK[9] == 0) {
								score += 10;
								al_play_sample(soundEffect3, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
							}
							RENK[9] = 1;
						}
						else if (KELIME[11] == 5) {
							KELIME[11] = 0;
							printf("KUBALI\n");
							if (RENK[11] == 0) {
								score += 10;
								al_play_sample(soundEffect3, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
							}
							RENK[11] = 1;
						}
						else if (kubali2 == 5) {
							kubali2 = 0;
							if (RENK[11] == 0) {
								score += 10;
								al_play_sample(soundEffect3, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
							}
							printf("KUBALI\n");
							RENK[11] = 1;
						}
						else {
							for (int i = 0;i < 12;i++) {
								KELIME[i] = 0;
							}
							turba2 = 0, turba3 = 0, turba4 = 0, mahrum2 = 0, kubali2 = 0;
						}
					}

				}
				if (mx <= 150 && mx >= 80 && my <= 680 && my >= 620) { // L 4x1

					if (ev.mouse.button & 1) {

						mx = 0;
						my = 0;
						if (KELIME[0] == 6) {
							KELIME[0]++;
						}
						else if (KELIME[6] == 3) {
							KELIME[6]++;
						}
						else if (KELIME[7] == 2) {
							KELIME[7]++;
						}
						else if (KELIME[11] == 4) {
							KELIME[11]++;
						}
						else if (kubali2 == 4) {
							kubali2++;
						}
						else {
							for (int i = 0;i < 12;i++) {
								KELIME[i] = 0;
							}
							turba2 = 0, turba3 = 0, turba4 = 0, mahrum2 = 0, kubali2 = 0;
						}
					}

				}
				if (mx <= 150 && mx >= 80 && my <= 760 && my >= 700) { // R 5x1

					if (ev.mouse.button & 1) {

						mx = 0;
						my = 0;

						if (KELIME[0] == 5) {
							KELIME[0]++;
						}
						else {
							for (int i = 0;i < 12;i++) {
								KELIME[i] = 0;
							}
							turba2 = 0, turba3 = 0, turba4 = 0, mahrum2 = 0, kubali2 = 0;
							KELIME[9] = 1;
						}
					}

				}
				if (mx <= 244 && mx >= 172 && my <= 440 && my >= 380) { // H 1x2

					if (ev.mouse.button & 1) {

						mx = 0;
						my = 0;
						if (KELIME[3] == 2) {
							KELIME[3]++;
							mahrum2++;

						}
						else {
							for (int i = 0;i < 12;i++) {
								KELIME[i] = 0;
							}
							turba2 = 0, turba3 = 0, turba4 = 0, mahrum2 = 0, kubali2 = 0;
							KELIME[6] = 1;
						}
					}

				}
				if (mx <= 244 && mx >= 172 && my <= 520 && my >= 460) { // B 2x2

					if (ev.mouse.button & 1) {


						mx = 0;
						my = 0;

						if (KELIME[5] == 3) {
							KELIME[5]++;
						}
						else if (turba2 == 3) {
							turba2++;
						}
						else {
							for (int i = 0;i < 12;i++) {
								KELIME[i] = 0;
							}
							turba2 = 0, turba3 = 0, turba4 = 0, mahrum2 = 0, kubali2 = 0;
							KELIME[0] = 1;
						}

					}

				}
				if (mx <= 244 && mx >= 172 && my <= 600 && my >= 540) { // R 3x2

					if (ev.mouse.button & 1) {

						mx = 0;
						my = 0;
						if (KELIME[0] == 2) {
							KELIME[0]++;
						}
						else if (turba2 == 2) {
							turba2++;
							turba3++;
						}
						else if (KELIME[6] == 2) {
							KELIME[6]++;
						}

						else {
							for (int i = 0;i < 12;i++) {
								KELIME[i] = 0;
							}
							turba2 = 0, turba3 = 0, turba4 = 0, mahrum2 = 0, kubali2 = 0;
						}
					}

				}
				if (mx <= 244 && mx >= 172 && my <= 680 && my >= 620) { // K 4x2

					if (ev.mouse.button & 1) {

						mx = 0;
						my = 0;
						if (KELIME[0] == 8) {
							KELIME[0] = 0;
							if (RENK[0] == 0) {
								score += 10;
								al_play_sample(soundEffect3, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
							}
							RENK[0] = 1;
							printf("BARBARLIK\n");

						}
						else if (KELIME[7] == 4) {
							KELIME[7] = 0;
							if (RENK[7] == 0) {
								score += 10;
								al_play_sample(soundEffect3, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
							}
							printf("BALIK\n");
							RENK[7] = 1;
						}
						else if (KELIME[9] == 2) {
							KELIME[9]++;
						}
						else {

							for (int i = 0;i < 12;i++) {
								KELIME[i] = 0;
							}
							turba2 = 0, turba3 = 0, turba4 = 0, mahrum2 = 0, kubali2 = 0;
							KELIME[11] = 1;
							kubali2 = 1;
						}
					}

				}
				if (mx <= 244 && mx >= 172 && my <= 760 && my >= 700) { // A 5x2

					if (ev.mouse.button & 1) {

						mx = 0;
						my = 0;
						if (KELIME[0] == 4) {
							KELIME[0]++;
						}
						else if (turba3 == 4) {
							turba3 = 0;
							turba2 = 0;
							turba4 = 0;
							printf("TURBA\n");
							if (RENK[5] == 0) {
								score += 10;
								al_play_sample(soundEffect3, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
							}
							RENK[5] = 1;
						}
						else if (turba4 == 4) {
							turba4 = 0;
							turba3 = 0;
							turba2 = 0;
							printf("TURBA\n");
							if (RENK[5] == 0) {
								score += 10;
								al_play_sample(soundEffect3, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
							}
							RENK[5] = 1;
						}
						else if (KELIME[7] == 1) {
							KELIME[7]++;
						}
						else if (KELIME[11] == 3) {
							KELIME[11]++;
						}
						else if (KELIME[9] == 1) {
							KELIME[9]++;
						}
						else if (kubali2 == 3) {
							kubali2++;
						}
						else {
							for (int i = 0;i < 12;i++) {
								KELIME[i] = 0;
							}
							turba2 = 0, turba3 = 0, turba4 = 0, mahrum2 = 0, kubali2 = 0;
						}
					}

				}
				if (mx <= 334 && mx >= 264 && my <= 440 && my >= 380) { // R 1x3

					if (ev.mouse.button & 1) {

						mx = 0;
						my = 0;
						if (KELIME[3] == 3) {
							KELIME[3]++;
							mahrum2++;

						}
						else if (KELIME[5] == 2) {
							KELIME[5]++;
						}
						else {
							for (int i = 0;i < 12;i++) {
								KELIME[i] = 0;
							}
							turba2 = 0, turba3 = 0, turba4 = 0, mahrum2 = 0, kubali2 = 0;
						}
					}

				}
				if (mx <= 334 && mx >= 264 && my <= 520 && my >= 460) { // T 2x3

					if (ev.mouse.button & 1) {

						mx = 0;
						my = 0;
						if (KELIME[1] == 4) {
							KELIME[1] = 0;
							if (RENK[1] == 0) {
								score += 10;
								al_play_sample(soundEffect3, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
							}
							RENK[1] = 1;
							printf("ARMUT\n");
						}
						else {

							for (int i = 0;i < 12;i++) {
								KELIME[i] = 0;
							}
							turba2 = 0, turba3 = 0, turba4 = 0, mahrum2 = 0, kubali2 = 0;
							KELIME[5] = 1;
							turba2 = 1;
							turba3 = 1;
							turba4 = 1;
							KELIME[10] = 1;
						}
					}

				}
				if (mx <= 334 && mx >= 264 && my <= 600 && my >= 540) { // U 3x3

					if (ev.mouse.button & 1) {

						mx = 0;
						my = 0;
						if (turba2 == 1) {
							turba2++;
							turba3++;
							turba4++;
						}
						else if (KELIME[11] == 1) {
							KELIME[11]++;
						}

						else {
							for (int i = 0;i < 12;i++) {
								KELIME[i] = 0;
							}
							turba2 = 0, turba3 = 0, turba4 = 0, mahrum2 = 0, kubali2 = 0;
							KELIME[2] = 1;
						}

					}

				}
				if (mx <= 334 && mx >= 264 && my <= 680 && my >= 620) { // B 4x3

					if (ev.mouse.button & 1) {

						mx = 0;
						my = 0;
						if (KELIME[0] == 3) {
							KELIME[0]++;
						}
						else if (turba3 == 3) {
							turba3++;

						}
						else if (turba4 == 3) {
							turba4++;
						}
						else if (KELIME[11] == 2) {
							KELIME[11]++;
						}
						else if (kubali2 == 2) {
							kubali2++;
						}
						else {
							for (int i = 0;i < 12;i++) {
								KELIME[i] = 0;
							}
							turba2 = 0, turba3 = 0, turba4 = 0, mahrum2 = 0, kubali2 = 0;
							KELIME[7] = 1;
						}
					}

				}
				if (mx <= 334 && mx >= 264 && my <= 760 && my >= 700) { //U 5x3

					if (ev.mouse.button & 1) {

						mx = 0;
						my = 0;
						if (KELIME[2] == 2) {
							KELIME[2]++;
						}
						else if (kubali2 == 1) {
							kubali2++;
						}
						else {
							for (int i = 0;i < 12;i++) {
								KELIME[i] = 0;
							}
							turba2 = 0, turba3 = 0, turba4 = 0, mahrum2 = 0, kubali2 = 0;
						}
					}

				}
				if (mx <= 424 && mx >= 354 && my <= 440 && my >= 380) { // C 1x4

					if (ev.mouse.button & 1) {

						mx = 0;
						my = 0;
						for (int i = 0;i < 12;i++) {
							KELIME[i] = 0;
						}
						turba2 = 0, turba3 = 0, turba4 = 0, mahrum2 = 0, kubali2 = 0;
					}

				}
				if (mx <= 424 && mx >= 354 && my <= 520 && my >= 460) { // U 2x4

					if (ev.mouse.button & 1) {

						mx = 0;
						my = 0;
						if (KELIME[1] == 3) {
							KELIME[1]++;
						}
						else if (KELIME[3] == 4) {
							KELIME[3]++;
							mahrum2++;
						}
						else if (KELIME[5] == 1) {
							KELIME[5]++;
						}
						else {
							for (int i = 0;i < 12;i++) {
								KELIME[i] = 0;
							}
							turba2 = 0, turba3 = 0, turba4 = 0, mahrum2 = 0, kubali2 = 0;
							KELIME[4] = 1;
						}
					}

				}
				if (mx <= 424 && mx >= 354 && my <= 600 && my >= 540) { // E 3x4

					if (ev.mouse.button & 1) {

						mx = 0;
						my = 0;
						if (KELIME[8] == 3) {
							KELIME[8] = 0;
							printf("NAME\n");
							if (RENK[8] == 0) {
								score += 10;
								al_play_sample(soundEffect3, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
							}
							RENK[8] = 1;
						}
						else if (KELIME[10] == 1) {
							KELIME[10]++;

						}
						else {
							for (int i = 0;i < 12;i++) {
								KELIME[i] = 0;
							}
							turba2 = 0, turba3 = 0, turba4 = 0, mahrum2 = 0, kubali2 = 0;
						}
					}

				}
				if (mx <= 424 && mx >= 354 && my <= 680 && my >= 620) { // R 4x4

					if (ev.mouse.button & 1) {

						mx = 0;
						my = 0;
						if (KELIME[2] == 1) {
							KELIME[2]++;
						}
						else if (KELIME[1] == 1) {
							KELIME[1]++;
						}
						else if (turba4 == 2) {
							turba4++;
						}
						else if (KELIME[10] == 2) {
							KELIME[10]++;

						}

						else {
							for (int i = 0;i < 12;i++) {
								KELIME[i] = 0;
							}
							turba2 = 0, turba3 = 0, turba4 = 0, mahrum2 = 0, kubali2 = 0;

						}
					}

				}
				if (mx <= 424 && mx >= 354 && my <= 760 && my >= 700) { // N 5x4

					if (ev.mouse.button & 1) {

						mx = 0;
						my = 0;

						if (KELIME[2] == 3) {
							KELIME[2] = 0;
							printf("URUN\n");
							if (RENK[2] == 0) {
								score += 10;
								al_play_sample(soundEffect3, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
							}
							RENK[2] = 1;
						}
						else if (KELIME[4] == 4) {
							KELIME[4] = 0;
							if (RENK[4] == 0) {
								score += 10;
								al_play_sample(soundEffect3, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
							}
							RENK[4] = 1;
							printf("UMMAN\n");
						}
						else {
							for (int i = 0;i < 12;i++) {
								KELIME[i] = 0;
							}
							turba2 = 0, turba3 = 0, turba4 = 0, mahrum2 = 0, kubali2 = 0;
							KELIME[8] = 1;
						}
					}

				}
				if (mx <= 514 && mx >= 444 && my <= 440 && my >= 380) { // I 1x5

					if (ev.mouse.button & 1) {

						mx = 0;
						my = 0;
						for (int i = 0;i < 12;i++) {
							KELIME[i] = 0;
						}
						turba2 = 0, turba3 = 0, turba4 = 0, mahrum2 = 0, kubali2 = 0;
					}

				}
				if (mx <= 514 && mx >= 444 && my <= 520 && my >= 460) { // M 2x5

					if (ev.mouse.button & 1) {

						mx = 0;
						my = 0;
						if (KELIME[3] == 5) {
							KELIME[3] = 0;
							if (RENK[3] == 0) {
								score += 10;
								al_play_sample(soundEffect3, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
							}
							RENK[3] = 1;
							printf("MAHRUM\n");

						}
						else if (KELIME[4] == 1) {
							KELIME[4]++;

						}
						else {
							for (int i = 0;i < 12;i++) {
								KELIME[i] = 0;
							}
							turba2 = 0, turba3 = 0, turba4 = 0, mahrum2 = 0, kubali2 = 0;
						}
					}

				}
				if (mx <= 514 && mx >= 444 && my <= 600 && my >= 540) { // M 3x5

					if (ev.mouse.button & 1) {

						mx = 0;
						my = 0;
						if (KELIME[1] == 2) {
							KELIME[1]++;
						}
						else if (KELIME[4] == 2) {
							KELIME[4]++;

						}
						else if (mahrum2 == 5) {
							mahrum2 = 0;
							printf("MAHRUM\n");
							if (RENK[3] == 1) {
								score += 10;
								al_play_sample(soundEffect3, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
							}
							RENK[3] = 1;
						}
						else if (KELIME[8] == 2) {
							KELIME[8]++;
						}
						else if (KELIME[10] == 3) {
							KELIME[10]++;

						}
						else {
							for (int i = 0;i < 12;i++) {
								KELIME[i] = 0;
							}
							turba2 = 0, turba3 = 0, turba4 = 0, mahrum2 = 0, kubali2 = 0;
						}
					}

				}
				if (mx <= 514 && mx >= 444 && my <= 680 && my >= 620) { // A 4x5

					if (ev.mouse.button & 1) {

						mx = 0;
						my = 0;
						if (KELIME[4] == 3) {
							KELIME[4]++;
						}
						else if (KELIME[8] == 1) {
							KELIME[8]++;
						}
						else if (KELIME[10] == 4) {
							KELIME[10]++;

						}
						else {
							for (int i = 0;i < 12;i++) {
								KELIME[i] = 0;
							}
							turba2 = 0, turba3 = 0, turba4 = 0, mahrum2 = 0, kubali2 = 0;
							KELIME[1] = 1;
						}

					}

				}
				if (mx <= 514 && mx >= 444 && my <= 760 && my >= 700) { // L 5x5

					if (ev.mouse.button & 1) {

						mx = 0;
						my = 0;
						if (KELIME[10] == 5) {
							KELIME[10] = 0;
							printf("TERMAL\n");
							if (RENK[10] == 0) {
								score += 10;
								al_play_sample(soundEffect3, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
							}
							RENK[10] = 1;
						}
						else {
							for (int i = 0;i < 12;i++) {
								KELIME[i] = 0;
							}
							turba2 = 0, turba3 = 0, turba4 = 0, mahrum2 = 0, kubali2 = 0;
						}
					}

				}
				al_draw_bitmap(background, 0, 0, 5);

				al_draw_line(20, 355, 580, 355, al_map_rgb(255, 0, 0), 5);

				if (RENK[0] == 0) {
					al_draw_text(font20, al_map_rgb(0, 0, 0), 95, 150, 0, "BARBARLIK");

				}
				if (RENK[0] == 1) {
					al_draw_text(font20, al_map_rgb(0, 255, 0), 95, 150, 0, "BARBARLIK");
					al_draw_line(85, 160, 210, 160, al_map_rgb(0, 0, 0), 3);
				}
				if (RENK[1] == 0) {
					al_draw_text(font20, al_map_rgb(0, 0, 0), 95, 190, 0, "ARMUT");

				}
				if (RENK[1] == 1) {
					al_draw_text(font20, al_map_rgb(50, 205, 50), 95, 190, 0, "ARMUT");
					al_draw_line(85, 200, 185, 200, al_map_rgb(0, 0, 0), 3);

				}
				if (RENK[2] == 0) {
					al_draw_text(font20, al_map_rgb(0, 0, 0), 95, 230, 0, "URUN");

				}
				if (RENK[2] == 1) {
					al_draw_text(font20, al_map_rgb(50, 205, 50), 95, 230, 0, "URUN");
					al_draw_line(85, 240, 170, 240, al_map_rgb(0, 0, 0), 3);

				}

				if (RENK[3] == 0) {
					al_draw_text(font20, al_map_rgb(0, 0, 0), 95, 270, 0, "MAHRUM");

				}
				if (RENK[3] == 1) {
					al_draw_text(font20, al_map_rgb(50, 205, 50), 95, 270, 0, "MAHRUM");
					al_draw_line(85, 280, 210, 280, al_map_rgb(0, 0, 0), 3);

				}
				if (RENK[4] == 0) {
					al_draw_text(font20, al_map_rgb(0, 0, 0), 279, 150, 0, "UMMAN");

				}
				if (RENK[4] == 1) {
					al_draw_text(font20, al_map_rgb(50, 205, 50), 279, 150, 0, "UMMAN");
					al_draw_line(269, 160, 380, 160, al_map_rgb(0, 0, 0), 3);

				}
				if (RENK[5] == 0) {
					al_draw_text(font20, al_map_rgb(0, 0, 0), 279, 190, 0, "TURBA");

				}
				if (RENK[5] == 1) {
					al_draw_text(font20, al_map_rgb(50, 205, 50), 279, 190, 0, "TURBA");
					al_draw_line(269, 200, 370, 200, al_map_rgb(0, 0, 0), 3);

				}
				if (RENK[6] == 0) {
					al_draw_text(font20, al_map_rgb(0, 0, 0), 279, 230, 0, "HARLI");


				}
				if (RENK[6] == 1) {
					al_draw_text(font20, al_map_rgb(50, 205, 50), 279, 230, 0, "HARLI");
					al_draw_line(269, 240, 360, 240, al_map_rgb(0, 0, 0), 3);

				}
				if (RENK[7] == 0) {
					al_draw_text(font20, al_map_rgb(0, 0, 0), 279, 270, 0, "BALIK");


				}
				if (RENK[7] == 1) {
					al_draw_text(font20, al_map_rgb(50, 205, 50), 279, 270, 0, "BALIK");
					al_draw_line(269, 280, 360, 280, al_map_rgb(0, 0, 0), 3);

				}
				if (RENK[8] == 0) {
					al_draw_text(font20, al_map_rgb(0, 0, 0), 450, 150, 0, "NAME");


				}
				if (RENK[8] == 1) {
					al_draw_text(font20, al_map_rgb(50, 205, 50), 450, 150, 0, "NAME");
					al_draw_line(440, 160, 530, 160, al_map_rgb(0, 0, 0), 3);

				}
				if (RENK[9] == 0) {
					al_draw_text(font20, al_map_rgb(0, 0, 0), 450, 190, 0, "RAKI");


				}
				if (RENK[9] == 1) {
					al_draw_text(font20, al_map_rgb(50, 205, 50), 450, 190, 0, "RAKI");
					al_draw_line(440, 200, 520, 200, al_map_rgb(0, 0, 0), 3);

				}
				if (RENK[10] == 0) {
					al_draw_text(font20, al_map_rgb(0, 0, 0), 450, 230, 0, "TERMAL");

				}
				if (RENK[10] == 1) {
					al_draw_text(font20, al_map_rgb(50, 205, 50), 450, 230, 0, "TERMAL");
					al_draw_line(440, 240, 550, 240, al_map_rgb(0, 0, 0), 3);

				}
				if (RENK[11] == 0) {
					al_draw_text(font20, al_map_rgb(0, 0, 0), 450, 270, 0, "KUBALI");


				}
				if (RENK[11] == 1) {
					al_draw_text(font20, al_map_rgb(50, 205, 50), 450, 270, 0, "KUBALI");
					al_draw_line(440, 280, 540, 280, al_map_rgb(0, 0, 0), 3);

				}


				if ((zaman - difftime(bit, basla)) < 11) {
					if (count == 0) {
						al_play_sample(soundEffect, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
						count = 1;
					}
				}





				al_draw_filled_rounded_rectangle(80, 380, 152, 440, 5, 5, al_map_rgb(255, 0, 0));
				al_draw_text(font48, al_map_rgb(0, 0, 0), 95, 380, 0, "M");
				al_draw_filled_rounded_rectangle(172, 380, 244, 440, 5, 5, al_map_rgb(255, 0, 0));
				al_draw_text(font48, al_map_rgb(0, 0, 0), 187, 380, 0, "H");
				al_draw_filled_rounded_rectangle(264, 380, 334, 440, 5, 5, al_map_rgb(255, 0, 0));
				al_draw_text(font48, al_map_rgb(0, 0, 0), 279, 380, 0, "R");
				al_draw_filled_rounded_rectangle(354, 380, 424, 440, 5, 5, al_map_rgb(255, 0, 0));
				al_draw_text(font48, al_map_rgb(0, 0, 0), 369, 380, 0, "C");
				al_draw_filled_rounded_rectangle(444, 380, 514, 440, 5, 5, al_map_rgb(255, 0, 0));
				al_draw_text(font48, al_map_rgb(0, 0, 0), 474, 380, 0, "I");



				al_draw_filled_rounded_rectangle(80, 460, 152, 520, 5, 5, al_map_rgb(255, 0, 0));
				al_draw_text(font48, al_map_rgb(0, 0, 0), 95, 460, 0, "A");
				al_draw_filled_rounded_rectangle(172, 460, 244, 520, 5, 5, al_map_rgb(255, 0, 0));
				al_draw_text(font48, al_map_rgb(0, 0, 0), 187, 460, 0, "B");
				al_draw_filled_rounded_rectangle(264, 460, 334, 520, 5, 5, al_map_rgb(255, 0, 0));
				al_draw_text(font48, al_map_rgb(0, 0, 0), 279, 460, 0, "T");
				al_draw_filled_rounded_rectangle(354, 460, 424, 520, 5, 5, al_map_rgb(255, 0, 0));
				al_draw_text(font48, al_map_rgb(0, 0, 0), 369, 460, 0, "U");
				al_draw_filled_rounded_rectangle(444, 460, 514, 520, 5, 5, al_map_rgb(255, 0, 0));
				al_draw_text(font48, al_map_rgb(0, 0, 0), 459, 460, 0, "M");



				al_draw_filled_rounded_rectangle(80, 540, 152, 600, 5, 5, al_map_rgb(255, 0, 0));
				al_draw_text(font48, al_map_rgb(0, 0, 0), 110, 540, 0, "I");
				al_draw_filled_rounded_rectangle(172, 540, 244, 600, 5, 5, al_map_rgb(255, 0, 0));
				al_draw_text(font48, al_map_rgb(0, 0, 0), 187, 540, 0, "R");
				al_draw_filled_rounded_rectangle(264, 540, 334, 600, 5, 5, al_map_rgb(255, 0, 0));
				al_draw_text(font48, al_map_rgb(0, 0, 0), 279, 540, 0, "U");
				al_draw_filled_rounded_rectangle(354, 540, 424, 600, 5, 5, al_map_rgb(255, 0, 0));
				al_draw_text(font48, al_map_rgb(0, 0, 0), 369, 540, 0, "E");
				al_draw_filled_rounded_rectangle(444, 540, 514, 600, 5, 5, al_map_rgb(255, 0, 0));
				al_draw_text(font48, al_map_rgb(0, 0, 0), 460, 540, 0, "M");



				al_draw_filled_rounded_rectangle(80, 620, 152, 680, 5, 5, al_map_rgb(255, 0, 0));
				al_draw_text(font48, al_map_rgb(0, 0, 0), 95, 620, 0, "L");
				al_draw_filled_rounded_rectangle(172, 620, 244, 680, 5, 5, al_map_rgb(255, 0, 0));
				al_draw_text(font48, al_map_rgb(0, 0, 0), 187, 620, 0, "K");
				al_draw_filled_rounded_rectangle(264, 620, 334, 680, 5, 5, al_map_rgb(255, 0, 0));
				al_draw_text(font48, al_map_rgb(0, 0, 0), 279, 620, 0, "B");
				al_draw_filled_rounded_rectangle(354, 620, 424, 680, 5, 5, al_map_rgb(255, 0, 0));
				al_draw_text(font48, al_map_rgb(0, 0, 0), 369, 620, 0, "R");
				al_draw_filled_rounded_rectangle(444, 620, 514, 680, 5, 5, al_map_rgb(255, 0, 0));
				al_draw_text(font48, al_map_rgb(0, 0, 0), 460, 620, 0, "A");



				al_draw_filled_rounded_rectangle(80, 700, 152, 760, 5, 5, al_map_rgb(255, 0, 0));
				al_draw_text(font48, al_map_rgb(0, 0, 0), 95, 700, 0, "R");
				al_draw_filled_rounded_rectangle(172, 700, 244, 760, 5, 5, al_map_rgb(255, 0, 0));
				al_draw_text(font48, al_map_rgb(0, 0, 0), 187, 700, 0, "A");
				al_draw_filled_rounded_rectangle(264, 700, 334, 760, 5, 5, al_map_rgb(255, 0, 0));
				al_draw_text(font48, al_map_rgb(0, 0, 0), 279, 700, 0, "U");
				al_draw_filled_rounded_rectangle(354, 700, 424, 760, 5, 5, al_map_rgb(255, 0, 0));
				al_draw_text(font48, al_map_rgb(0, 0, 0), 369, 700, 0, "N");
				al_draw_filled_rounded_rectangle(444, 700, 514, 760, 5, 5, al_map_rgb(255, 0, 0));
				al_draw_text(font48, al_map_rgb(0, 0, 0), 460, 700, 0, "L");






				al_draw_rounded_rectangle(20, 20, 140, 80, 5, 5, al_map_rgb(255, 0, 0), 5);
				al_draw_rounded_rectangle(20, 20, 580, 780, 5, 5, al_map_rgb(255, 0, 0), 5);
				al_draw_rounded_rectangle(460, 20, 580, 80, 5, 5, al_map_rgb(255, 0, 0), 5);

				al_draw_line(20, 80, 580, 80, al_map_rgb(255, 0, 0), 5);

				al_draw_text(font48, al_map_rgb(0, 0, 0), 158, 22, 0, "Word Search");
				al_draw_textf(font20, al_map_rgb(0, 0, 0), 38, 40, 0, "SCORE:%i", score);
				al_draw_textf(font20, al_map_rgb(0, 0, 0), 480, 40, 0, "TIME:%.0f", (zaman - difftime(bit, basla)));
				al_draw_bitmap(image, x - 65, y - 65, 5);//mouse
				al_flip_display();

				al_draw_textf(font20, al_map_rgb(0, 0, 0), 160, 778, 0, "Cikis yapmak icin ESC basiniz");
				if ((zaman - difftime(bit, basla)) == 0)
				{
					al_stop_samples();
					count = 0;
					sayac = 1;
				}
				if (RENK[0] == 1 && RENK[1] == 1 && RENK[2] == 1 && RENK[3] == 1 && RENK[4] == 1 && RENK[5] == 1 && RENK[6] == 1 && RENK[7] == 1 && RENK[8] == 1 && RENK[9] == 1 && RENK[10] == 1 && RENK[11] == 1) {
				al_stop_samples();
				al_play_sample(soundEffect2, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
				
				while (true) {               //------------------------------------- KAZANDIN ---------------------------------------------
					
					al_wait_for_event_timed(event_queue, &ev, 0.1);

					if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
						if (ev.mouse.button & 1) {
							mx = ev.mouse.x;
							my = ev.mouse.y;
						}
					}
					else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES) {
						x = ev.mouse.x;
						y = ev.mouse.y;
					}
					else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
						al_destroy_bitmap(image);
						al_destroy_bitmap(background);
						al_destroy_bitmap(wordgame);
						al_destroy_bitmap(wordgame2);
						al_destroy_bitmap(gameover);
						al_destroy_bitmap(start);
						al_destroy_bitmap(tekrar);
						al_destroy_bitmap(winner);
						al_destroy_event_queue(event_queue);
						al_destroy_timer(timer);
						al_destroy_font(font20);
						al_destroy_font(font48);
						al_destroy_sample(soundEffect);
						al_destroy_sample(soundEffect2);
						al_destroy_sample(soundEffect3);
						al_destroy_sample(soundEffect4);
						al_destroy_sample(soundEffect5);
						al_destroy_display(display);
						return 0;
					}
					 if (mx <= 367 && mx >= 229 && my <= 638 && my >= 588) {
						al_destroy_bitmap(image);
						al_destroy_bitmap(background);
						al_destroy_bitmap(wordgame);
						al_destroy_bitmap(wordgame2);
						al_destroy_bitmap(gameover);
						al_destroy_bitmap(start);
						al_destroy_bitmap(tekrar);
						al_destroy_bitmap(winner);
						al_destroy_event_queue(event_queue);
						al_destroy_timer(timer);
						al_destroy_font(font20);
						al_destroy_font(font48);
						al_destroy_sample(soundEffect);
						al_destroy_sample(soundEffect2);
						al_destroy_sample(soundEffect3);
						al_destroy_sample(soundEffect4);
						al_destroy_sample(soundEffect5);
						al_destroy_display(display);
						return 0;
					}
					al_draw_bitmap(background, 0, 0, 5);
					al_draw_textf(font48, al_map_rgb(0, 0, 0), 190, 450, 0, "SCORE:%i", score);
					al_draw_bitmap(winner, 50, 150, 0);
					al_draw_bitmap(start, 229, 588, 0);
					al_draw_textf(font20, al_map_rgb(0, 0, 0), 270, 600, 0, "CIKIS");
					
					al_draw_bitmap(image, x - 65, y - 65, 5);
					
					al_flip_display();
					

				}                   //------------------------------------------- KAZANDIN SON ---------------------------------------------------------------------
			}
			while (sayac == 1) {     // -------------------------------------------GAME OVER----------------------------------------------------------------

				if (count == 0) {
					al_play_sample(soundEffect4, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
					count = 1;
				}
				al_wait_for_event(event_queue, &ev);
				al_draw_textf(font20, al_map_rgb(0, 0, 0), 460, 30, 0, "TIME:%i", (zaman - difftime(bit, basla)));

				if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
					if (ev.mouse.button & 1) {
						mx = ev.mouse.x;
						my = ev.mouse.y;
					}
				}
				else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES) {
					x = ev.mouse.x;
					y = ev.mouse.y;
				}
				else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
					al_destroy_bitmap(image);
					al_destroy_bitmap(background);
					al_destroy_bitmap(wordgame);
					al_destroy_bitmap(wordgame2);
					al_destroy_bitmap(gameover);
					al_destroy_bitmap(start);
					al_destroy_bitmap(tekrar);
					al_destroy_bitmap(winner);
					al_destroy_event_queue(event_queue);
					al_destroy_timer(timer);
					al_destroy_font(font20);
					al_destroy_font(font48);
					al_destroy_sample(soundEffect);
					al_destroy_sample(soundEffect2);
					al_destroy_sample(soundEffect3);
					al_destroy_sample(soundEffect4);
					al_destroy_sample(soundEffect5);
					al_destroy_display(display);
					return 0;
				}
				if (mx <= 367 && mx >= 229 && my <= 688 && my >= 638) {
					al_destroy_bitmap(image);
					al_destroy_bitmap(background);
					al_destroy_bitmap(wordgame);
					al_destroy_bitmap(wordgame2);
					al_destroy_bitmap(gameover);
					al_destroy_bitmap(start);
					al_destroy_bitmap(tekrar);
					al_destroy_bitmap(winner);
					al_destroy_event_queue(event_queue);
					al_destroy_timer(timer);
					al_destroy_font(font20);
					al_destroy_font(font48);
					al_destroy_sample(soundEffect);
					al_destroy_sample(soundEffect2);
					al_destroy_sample(soundEffect3);
					al_destroy_sample(soundEffect4);
					al_destroy_sample(soundEffect5);
					al_destroy_display(display);
					return 0;
				}
				if (mx <= 418 && mx >= 180 && my <= 588 && my >= 538) {
					sayac = 0;
					count = 0;
					al_stop_samples();
					for (int i = 0;i < 12;i++) {
						RENK[i] = 0;
						score = 0;
					}

					time(&basla);
					mx = 0;
					my = 0;

				}
				al_draw_bitmap(background, 0, 0, 5);
					
					al_draw_bitmap(gameover, 100, 200, 0);
					al_draw_bitmap(tekrar, 180, 538, 5);
					al_draw_textf(font20, al_map_rgb(0, 0, 0), 230, 550, 0, "TEKRAR  OYNA");
					al_draw_textf(font48, al_map_rgb(0, 0, 0), 190, 450, 0, "SCORE:%i", score);
					al_draw_bitmap(start, 229, 638, 0);
					al_draw_textf(font20, al_map_rgb(0, 0, 0), 270, 650, 0, "CIKIS");
					al_draw_bitmap(image, x - 65, y - 65, 5);
					al_flip_display();
					
					
				
			}        // ------------------------------------------------------GAME OVER SON----------------------------------------------------------------------



		} //--------------------------------------------------------------------OYUN SON----------------------------------------------------------------------------------------------------------------------

	

	
		al_destroy_bitmap(image);
		al_destroy_bitmap(background);
		al_destroy_bitmap(wordgame);
		al_destroy_bitmap(wordgame2);
		al_destroy_bitmap(gameover);
		al_destroy_bitmap(start);
		al_destroy_bitmap(tekrar);
		al_destroy_bitmap(winner);
		al_destroy_event_queue(event_queue);
		al_destroy_timer(timer);
		al_destroy_font(font20);
		al_destroy_font(font48);
		al_destroy_sample(soundEffect);
		al_destroy_sample(soundEffect2);
		al_destroy_sample(soundEffect3);
		al_destroy_sample(soundEffect4);
		al_destroy_sample(soundEffect5);
		al_destroy_display(display);


	return 0;
	

}                
