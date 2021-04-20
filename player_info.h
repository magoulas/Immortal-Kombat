//STRUCT for every player
#pragma once
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"
#include <windows.h>
#include <conio.h>

using namespace std;


extern const float FPS;
extern const float frameFPS;
extern const int SCREEN_W;
extern const int SCREEN_H;
extern bool doexit;

extern ALLEGRO_DISPLAY *display;
extern ALLEGRO_EVENT_QUEUE *event_queue;
extern ALLEGRO_TIMER *timer;
extern ALLEGRO_TIMER *frameTimer;
extern ALLEGRO_BITMAP *arena;

extern ALLEGRO_SAMPLE_INSTANCE *arena_sfx_inst;
extern ALLEGRO_SAMPLE *arena_sample;

extern ALLEGRO_SAMPLE_INSTANCE *male_hit_sfx_inst;
extern ALLEGRO_SAMPLE *male_sample;

extern ALLEGRO_SAMPLE_INSTANCE *kick_sfx_inst;
extern ALLEGRO_SAMPLE *kick_sample;

extern ALLEGRO_SAMPLE_INSTANCE *punch_sfx_inst;
extern ALLEGRO_SAMPLE *punch_sample;

extern ALLEGRO_SAMPLE_INSTANCE *skeleton_sfx_inst;
extern ALLEGRO_SAMPLE *skeleton_sample;

extern ALLEGRO_SAMPLE_INSTANCE *get_over_here_sfx_inst;
extern ALLEGRO_SAMPLE *get_over_here_sample;


extern bool key_player_one[9];
extern bool key_player_two[9];
extern bool luck_player_one[8];
extern bool luck_player_two[8];
extern bool redraw;
extern bool doexit;
//player 1 controls:
//M: low_punch/K: high_punch/B: Block/N: low_kick/J: high_kick
//player 2 controls:
//S: crouch/A: farward/F: Block/H: low_punch/U: high_punch/Y: high_kick/G: low_kick
	enum MYKEYS {
		KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_M, KEY_B, KEY_K, KEY_N, KEY_J, KEY_S, KEY_A, KEY_D, KEY_F, KEY_H, KEY_U, KEY_Y, KEY_G, KEY_W
	};
//player states
	enum PLAYER_STATE {
		ready, crouch, farward, back, movement, low_punch, high_punch, low_kick, high_kick, low_block, block, jump, jump_forward, jump_backward, get_hit, dizzy, dead, dragon, spear
	};
//test your luck MODE
	enum LUCK {
		PD, KD, JD, CD, BD, VT, DA, BL
	};




	struct player_t {
		int player_number=0;
		float pos_x=0;
		float pos_y=0;
		PLAYER_STATE player_state= ready;
		ALLEGRO_BITMAP *player_bmp = NULL;
		//for animation purposes
		int flip=0;
		float step=0;
		int hit_points=30;
		int hit_points_max = 270;
		float animate_ready=0;
		int ready_counter=0;
		float animate_movement=0;
		int movement_counter=0;
		float animate_farward=0;
		int farward_counter=0;
		float animate_back=0;
		int back_counter=0;
		float animate_crouch=0;
		int crouch_counter=0;
		float animate_low_punch=0;
		int low_punch_counter=0;
		float animate_high_punch=0;
		int high_punch_counter=0;
		float animate_low_kick=0;
		int low_kick_counter=0;
		float animate_high_kick=0;
		int high_kick_counter=0;
		float animate_block=0;
		int block_counter=0;
		float animate_low_block=0;
		int low_block_counter=0;
		float animate_jump=0;
		int jump_counter=0;
		float animate_jump_forward=0;
		int jump_forward_counter=0;
		float animate_jump_backward=0;
		int jump_backward_counter=0;
		float animate_dizzy = 0;
		int dizzy_counter = 0;
		float animate_dead = 0;
		int dead_counter = 0;
		float animate_get_hit = 0;
		int get_hit_counter = 0;
		float animate_dragon = 0;
		int dragon_counter = 0;
		float fire_animate = 0;
		int fire_counter = 0;
		player_t *skeleton;
		float throw_spear_animate = 0;
		int throw_spear_counter = 0;
		float rope_spear_animate = 0;
		int rope_spear_counter = 0;
		float drag_spear_animate = 0;
		int drag_spear_counter = 0;
		float fly_spear_animate = 0;
		int fly_spear_counter = 0;
		float spear_pos_x = 0;
	};



	extern void Player_Draw(player_t *);
	extern void Event_Handler_One(player_t *, ALLEGRO_EVENT);
	extern void Event_Handler_Two(player_t *, ALLEGRO_EVENT);
	extern bool Collision(player_t *, player_t *);
	extern void Damage_Counter(player_t *, player_t *);
	extern void Hit_Sounds(int, player_t *);


