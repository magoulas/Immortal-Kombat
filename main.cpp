// ImmortalKombat project 
//All Rights Reserved 
//Credits
//Creators: Stratos Sikelis csd3151 / Andreas Pattakos csd3085
#include "pch.h"
#include "player_info.h"
#include <iostream>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_color.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"

using namespace std;
//framerate
const float FPS =13;
const float frameFPS = 15;
const int SCREEN_W = 640;
const int SCREEN_H = 460;

ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_TIMER *timer = NULL;
ALLEGRO_TIMER *frameTimer = NULL;
ALLEGRO_BITMAP *arena = NULL;
ALLEGRO_SAMPLE_INSTANCE *sample_inst = NULL;
ALLEGRO_SAMPLE_INSTANCE *fight_sfx_inst = NULL;
ALLEGRO_SAMPLE *fight_sample = NULL;

ALLEGRO_SAMPLE_INSTANCE *arena_sfx_inst = NULL;
ALLEGRO_SAMPLE *arena_sample = NULL;

//arrays for player keys
bool key_player_one[9] = { false, false, false, false, false, false, false, false, false };
bool key_player_two[9] = { false, false, false, false, false, false, false, false, false };
//arrays for test your luck mode
bool luck_player_one[8] = { false, false, false, false, false, false, false, false, };
bool luck_player_two[8] = { false, false, false, false, false, false, false, false, };

ALLEGRO_SAMPLE_INSTANCE *male_hit_sfx_inst = NULL;
ALLEGRO_SAMPLE *male_sample = NULL;

ALLEGRO_SAMPLE_INSTANCE *kick_sfx_inst = NULL;
ALLEGRO_SAMPLE *kick_sample = NULL;

ALLEGRO_SAMPLE_INSTANCE *punch_sfx_inst = NULL;
ALLEGRO_SAMPLE *punch_sample = NULL;

ALLEGRO_SAMPLE_INSTANCE *skeleton_sfx_inst = NULL;
ALLEGRO_SAMPLE *skeleton_sample = NULL;

ALLEGRO_SAMPLE_INSTANCE *get_over_here_sfx_inst = NULL;
ALLEGRO_SAMPLE *get_over_here_sample = NULL;

//draw and exit booleans
bool redraw = true;
bool doexit = false;

void test_your_luck(player_t *player_one, player_t *player_two) {

}

int main(int argc, char **argv)
{
	bool collision = false;
	//Init for player one
	player_t aplayer;
	player_t *player1 = &aplayer;
	player1->player_number = 1;
	player1->pos_x = 0;
	player1->pos_y = SCREEN_H / 2.2;
	player1->flip = 0;
	player1->player_state = ready;
	player1->animate_ready = 89;
	player1->ready_counter = 0;
	player1->animate_movement = 15;
	player1->movement_counter = 0;
	player1->animate_farward = 15;
	player1->farward_counter = 0;
	player1->animate_back = 421;
	player1->back_counter = 0;
	player1->animate_crouch = 982;
	player1->crouch_counter = 0;
	player1->animate_low_punch = 15;
	player1->low_punch_counter = 0;
	player1->animate_block = 800;
	player1->block_counter = 0;
	player1->animate_low_block = 1210;
	player1->animate_high_punch = 15;
	player1->high_punch_counter = 0;
	player1->animate_low_kick = 425;
	player1->low_kick_counter = 0;
	player1->animate_high_kick = 15;
	player1->high_kick_counter = 0;
	player1->animate_jump = 580;
	player1->jump_counter = 0;
	player1->animate_jump_forward = 770;
	player1->jump_forward_counter = 0;
	player1->animate_jump_backward = 770;
	player1->jump_backward_counter = 0;
	player1->animate_dizzy = 1043;
	player1->dizzy_counter = 0;
	player1->animate_dead = 1032;
	player1->dead_counter = 0;
	player1->animate_get_hit = 15;
	player1->get_hit_counter = 0;
	player1->animate_dragon = 15;
	player1->dragon_counter = 0;
	player1->fire_animate = 440;
	player1->fire_counter = 0;
	player1->throw_spear_animate = 15;
	player1->throw_spear_counter = 0;
	player1->drag_spear_animate = 0;
	player1->drag_spear_counter = 0;
	player1->rope_spear_animate = 0;
	player1->rope_spear_counter = 0;
	player1->fly_spear_animate = 0;
	player1->fly_spear_counter = 0;
	player1->spear_pos_x = -500;

	//Init for player two
	player_t bplayer;
	player_t *player2 = &bplayer;

	player1->skeleton = player2;
	player2->step = 51;
	player2->player_number = 2;
	player2->pos_x = SCREEN_W /1.3;
	player2->pos_y = SCREEN_H / 2.2;
	player2->skeleton = player1;
	player2->flip = 1;
	player2->player_state = ready;
	player2->animate_ready = 88;
	player2->ready_counter = 0;
	player2->animate_crouch = 1151;
	player2->crouch_counter = 0;
	player2->animate_farward = 20;
	player2->farward_counter = 0;
	player2->animate_back = 432;
	player2->back_counter = 0;
	player2->animate_block = 970;
	player2->block_counter = 0;
	player2->animate_low_block = 1345;
	player2->animate_low_punch = 15;
	player2->low_punch_counter = 0;
	player2->animate_high_punch = 15;
	player2->high_punch_counter = 0;
	player2->animate_low_kick = 425;
	player2->low_kick_counter = 0;
	player2->animate_high_kick = 15;
	player2->high_kick_counter = 0;
	player2->animate_jump = 525;
	player2->jump_counter = 0;
	player2->animate_jump_forward = 722;
	player2->jump_forward_counter = 0;
	player2->animate_jump_backward = 722;
	player2->jump_backward_counter = 0;
	player2->animate_dizzy = 1032;
	player2->dizzy_counter = 0;
	player2->animate_dead = 60;
	player2->dead_counter = 0;

	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}

	if (!al_install_keyboard()) {
		fprintf(stderr, "failed to initialize the keyboard!\n");
		return -1;
	}

	timer = al_create_timer(1.0 / FPS);
	if (!timer) {
		fprintf(stderr, "failed to create timer!\n");
		return -1;
	}

	frameTimer = al_create_timer(1.0 / frameFPS);
	if (!frameTimer) {
		fprintf(stderr, "failed to create timer!\n");
		return -1;
	}

	al_init_font_addon();
	al_init_ttf_addon();

	ALLEGRO_FONT *font = al_load_ttf_font("mk1.ttf", 30, NULL);

	display = al_create_display(SCREEN_W, SCREEN_H);
	if (!display) {
		fprintf(stderr, "failed to create display!\n");
		al_destroy_timer(timer);
		return -1;
	}
	if (!al_init_image_addon()) {
		al_show_native_message_box(display, "Error", "Error", "Failed to initialize al_init_image_addon!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return 0;
	}

	if (!al_init_primitives_addon()) {
		al_show_native_message_box(display, "Error", "Error", "Failed to initialize al_init_primitives_addon!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return 0;
	}

	player1->player_bmp = al_load_bitmap("scorpion.png");
	if (!player1->player_bmp) {
		al_show_native_message_box(display, "Error", "Error", "Failed to load image!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		return 0;
	}

	player2->player_bmp = al_load_bitmap("subzero.png");
	if (!player2->player_bmp) {
		al_show_native_message_box(display, "Error", "Error", "Failed to load image!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		return 0;
	}

	arena = al_load_bitmap("arena.jpg");
	if (!arena) {
		al_show_native_message_box(display, "Error", "Error", "Failed to load image!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		return 0;
	}
	if (!al_install_audio()) {
		fprintf(stderr, "failed to initialize audio!\n");
		return -1;
	}

	if (!al_init_acodec_addon()) {
		fprintf(stderr, "failed to initialize audio codecs!\n");
		return -1;
	}

	if (!al_reserve_samples(1)) {
		fprintf(stderr, "failed to reserve samples!\n");
		return -1;
	}

	ALLEGRO_SAMPLE *sample = al_load_sample("theme.wav");

	if (!sample) {
		printf("Audio clip sample not loaded!\n");
		return -1;
	}



	al_set_target_bitmap(player1->player_bmp);
	al_set_target_bitmap(al_get_backbuffer(display));

	event_queue = al_create_event_queue();
	if (!event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");
		al_destroy_bitmap(player1->player_bmp);
		al_destroy_bitmap(arena);
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_register_event_source(event_queue, al_get_timer_event_source(frameTimer));

	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();

	al_start_timer(timer);

	bool exit = false;
	int l = 0;
	sample_inst = al_create_sample_instance(sample);
	al_set_sample_instance_playmode(sample_inst, ALLEGRO_PLAYMODE_LOOP);
	al_attach_sample_instance_to_mixer(sample_inst, al_get_default_mixer());
	al_play_sample_instance(sample_inst);


	//Start screen loop
	while (!exit) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		al_draw_text(font, al_map_rgb(255, 255, 255), SCREEN_W / 2, SCREEN_H / 50, ALLEGRO_ALIGN_CENTER, "University of Crete/Department of Computer Science");
		al_draw_text(font, al_map_rgb(255, 255, 255), SCREEN_W / 2, SCREEN_H / 10, ALLEGRO_ALIGN_CENTER, "CS-454 Development of Intelligent Interfaces and Games");
		al_draw_text(font, al_map_rgb(255, 255, 255), SCREEN_W / 2, SCREEN_H / 5, ALLEGRO_ALIGN_CENTER, "Term Project, Fall Semester 2018");
		al_draw_text(font, al_map_rgb(255, 0, 255), SCREEN_W / 2, SCREEN_H / 2.5, ALLEGRO_ALIGN_CENTER, "MORTAL KOMBAT");
		al_draw_text(font, al_map_rgb(255, 0, 255), SCREEN_W / 2, SCREEN_H / 1.1, ALLEGRO_ALIGN_CENTER, "Created by: CSD3151, CSD3085");
		al_draw_text(font, al_map_rgb(255, 0, 255), SCREEN_W / 2, SCREEN_H / 2, ALLEGRO_ALIGN_CENTER, "GHETTO EDITION");
		if (l==0) {
			l++;
			al_draw_text(font, al_map_rgb(255, 0, 255), SCREEN_W / 2, SCREEN_H / 1.3, ALLEGRO_ALIGN_CENTER, "PRESS ANY KEY TO CONTINUE");
		}
		else if (l == 1) {
			l--;
			al_draw_text(font, al_map_rgb(255, 255, 255), SCREEN_W / 2, SCREEN_H / 1.3, ALLEGRO_ALIGN_CENTER, "PRESS ANY KEY TO CONTINUE");
		}
		if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			al_stop_sample_instance(sample_inst);
			exit = true;
		}
		
		
		al_flip_display();
	}

	int i = 0;

	arena_sample = al_load_sample("arena.wav");
	arena_sfx_inst = al_create_sample_instance(arena_sample);
	al_set_sample_instance_playmode(arena_sfx_inst, ALLEGRO_PLAYMODE_LOOP);
	al_attach_sample_instance_to_mixer(arena_sfx_inst, al_get_default_mixer());

	fight_sample = al_load_sample("fight-sample.wav");
	fight_sfx_inst = al_create_sample_instance(fight_sample);
	al_set_sample_instance_playmode(fight_sfx_inst, ALLEGRO_PLAYMODE_ONCE);
	al_attach_sample_instance_to_mixer(fight_sfx_inst, al_get_default_mixer());
	int fight_counter = 0;

	 male_sample = al_load_sample("hit-sfx.wav");
	 male_hit_sfx_inst = al_create_sample_instance(male_sample);

	 kick_sample = al_load_sample("kick-hit-sfx.wav");
	 kick_sfx_inst = al_create_sample_instance(kick_sample);

	 punch_sample = al_load_sample("punch-hit-sfx.wav");
	 punch_sfx_inst = al_create_sample_instance(punch_sample);

	 skeleton_sample = al_load_sample("skeleton-sfx.wav");
	 skeleton_sfx_inst = al_create_sample_instance(skeleton_sample);

	 get_over_here_sample = al_load_sample("get-over-here.wav");
	 get_over_here_sfx_inst = al_create_sample_instance(get_over_here_sample);

	 al_play_sample_instance(arena_sfx_inst);


	//main game loop
	while (!doexit)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		//COUNTERS GIA TO ANIMATION KAI MOVEMENT EVENT HANDLER SUNARTISH ME TA EVENT SUMFWNA TO TIMER CALL H BUTTON
		Event_Handler_One(player1, ev);
		Event_Handler_Two(player2, ev);


		if (fight_counter >0 && fight_counter < 10) {
			fight_counter++;
		}
		if (fight_counter == 0) {
			fight_counter++;
			al_unregister_event_source(event_queue, al_get_keyboard_event_source());
			al_play_sample_instance(fight_sfx_inst);
		}
		else if (fight_counter == 10) {
			al_register_event_source(event_queue, al_get_keyboard_event_source());
			fight_counter++;
		}
		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;
			collision = false;
			al_clear_to_color(al_map_rgb(0, 0, 0));

			al_draw_bitmap(arena, 0, 0, 0);

			//EMFANISH XARAKTHRWN
			if (player1->pos_x > player2->pos_x) {
				player1->flip = 1;
				if (i == 0) {
					player1->animate_farward = 421;
					player1->animate_back = 15;
					player2->animate_farward = 432;
					player2->animate_back = 20;
					i++;
				}
				player2->flip = 0;
			}
			else if (player1->pos_x < player2->pos_x) {
				player1->flip = 0;
				if (i == 1) {
					player1->animate_farward = 15;
					player1->animate_back = 421;
					player2->animate_farward = 20;
					player2->animate_back = 432;
					i--;
				}
				player2->flip = 1;
			}
			collision = Collision(player1, player2);

			if (collision) {
				Damage_Counter(player1, player2);
			}
			if (player1->player_state != ready) {
				if (player1->player_state == spear) {
				}
				Hit_Sounds(collision, player1);
			}
			if (player2->player_state != ready) {
				Hit_Sounds(collision, player2);
			}
			Player_Draw(player2);
			Player_Draw(player1);

			al_draw_filled_rectangle( 370,  10,  600,  30, al_map_rgb(0,255,0));
			al_draw_filled_rectangle(370, 10, 340+player2->hit_points, 30, al_map_rgb(255, 0, 0));

			al_draw_filled_rectangle(30, 10, 260, 30, al_map_rgb(0, 255, 0));
			al_draw_filled_rectangle(30, 10, player1->hit_points, 30, al_map_rgb(255, 0, 0));



			al_flip_display();
		}
	}
	al_destroy_sample_instance(male_hit_sfx_inst);
	al_destroy_sample(male_sample);
	al_destroy_sample_instance(punch_sfx_inst);
	al_destroy_sample(punch_sample);
	al_destroy_sample_instance(skeleton_sfx_inst);
	al_destroy_sample(skeleton_sample);
	al_destroy_sample_instance(kick_sfx_inst);
	al_destroy_sample(kick_sample);
	al_destroy_sample_instance(fight_sfx_inst);
	al_destroy_sample(fight_sample);
	al_destroy_sample_instance(sample_inst);
	al_destroy_sample(sample);
	al_destroy_font(font);
	al_destroy_bitmap(player1->player_bmp);
	al_destroy_bitmap(arena);
	al_destroy_timer(timer);
	al_destroy_timer(frameTimer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);


	return 0;
}

