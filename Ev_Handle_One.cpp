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



//event handler for the first player:  to player->animate_ready eipame einai h thesh ths maskas sto X. to player->ready_counter einai ta posa frames theloume gia to sequence
//ara mporoume na poume ama counter = 5 (dld to 5 frame)  player->animate_ready=1000 (dld h maska sto 1000 ston X aksona) ara aplws gia na metakiname thn maska aplos += step h ena stathero aritmo pou theloume.
void Event_Handler_One(player_t *player, ALLEGRO_EVENT ev) {
	//player tmp position
	float tmp_pos_y = player->pos_y;
	//event handler for every state
	if (ev.type == ALLEGRO_EVENT_TIMER) {
		if (player->player_state == dizzy ){
			for (int g = 0; g < 9; g++) {
				key_player_one[g] = false;
			}
			if (player->dizzy_counter <= 5) {
				player->dizzy_counter++;
				player->animate_dizzy += 51;
				player->step = 51;
			}
			else if (player->dizzy_counter == 6) {
				player->animate_dizzy = 1043;
				player->dizzy_counter = 0;
			}
			redraw = true;
			return;
		}
		
		player->player_state = ready;

		if (key_player_one[KEY_M] && key_player_one[KEY_LEFT]) {
			player->player_state = spear;
			if (player->throw_spear_counter == 0) {
				player->throw_spear_counter++;
			}
			else if (player->throw_spear_counter >= 1 && player->throw_spear_counter < 3) {
				player->throw_spear_animate += 70;
				player->throw_spear_counter++;
			}
			else if (player->throw_spear_counter == 3) {
				player->fly_spear_counter ++;
				if (player->fly_spear_counter >= 2 && player->fly_spear_counter<4) {
					player->fly_spear_animate += 220;
				}
				else if (player->fly_spear_counter == 4) {
					player->fly_spear_animate = 0;
					player->fly_spear_counter = 0;
				}
				player->spear_pos_x += 35;
				if (player->spear_pos_x >= player->skeleton->pos_x-370) {
					player->throw_spear_counter++;					
				}
			}
			if (player->throw_spear_counter >= 4 && player->throw_spear_counter<8) {
				player->throw_spear_animate += 80;
				player->throw_spear_counter++;
				player->drag_spear_animate = 880;
				if (player->rope_spear_counter == 0) {
					player->rope_spear_counter++;
					player->rope_spear_animate = 1040;
					if (player->pos_x < player->skeleton->pos_x-150) {
						player->skeleton->pos_x -= 35;
						player->spear_pos_x -= 35;
					}
				}
				else if (player->rope_spear_counter == 1) {
					player->rope_spear_counter = 0;
					player->rope_spear_animate = 1080;
					if (player->pos_x < player->skeleton->pos_x-150) {
						player->skeleton->pos_x -= 35;
						player->spear_pos_x -= 35;
					}
				}
			}
			else if (player->throw_spear_counter == 8) {
				if (player->rope_spear_counter == 0) {
					player->rope_spear_counter++;
					player->rope_spear_animate = 1040;
					if (player->pos_x < player->skeleton->pos_x - 150) {
						player->skeleton->pos_x -= 35;
						player->spear_pos_x -= 35;
					}
				}
				else if (player->rope_spear_counter == 1) {
					player->rope_spear_counter = 0;
					player->rope_spear_animate = 1080;
					if (player->pos_x < player->skeleton->pos_x - 150) {
						player->skeleton->pos_x -= 35;
						player->spear_pos_x -= 35;
					}
				}
			}
			if (player->pos_x > player->skeleton->pos_x - 150) { 
				player->throw_spear_animate = 15;
				player->throw_spear_counter = 0;
				player->drag_spear_animate = 0;
				player->drag_spear_counter = 0;
				player->rope_spear_animate = 1040;
				player->rope_spear_counter = 0;
				player->fly_spear_animate = 0;
				player->fly_spear_counter = 0;
				player->spear_pos_x = -500;
			}
			redraw = true;
			return;
		}


		if (key_player_one[KEY_UP] && key_player_one[KEY_B]) {
			player->player_state = dragon;
			if (player->dragon_counter == 0) {
				player->dragon_counter++;
			}
			else if (player->dragon_counter <= 5) {
				player->animate_dragon += 50;
				player->dragon_counter++;
			}
			else if (player->dragon_counter == 6 || player->dragon_counter == 7) {
				player->animate_dragon += 65;
				player->dragon_counter++;
			}
			if (player->dragon_counter == 8) {
				if (player->fire_counter == 0) {
					player->fire_counter++;
				}
				else if (player->fire_counter == 1) {
					player->fire_animate += 35;
					player->fire_counter++;
				}
				else if (player->fire_counter == 2) {
					player->fire_animate += 25;
					player->fire_counter++;
				}
				else if (player->fire_counter == 3) {
					player->fire_animate += 25;
					player->fire_counter++;
				}
				else if (player->fire_counter == 4) {
					player->fire_animate += 55;
					player->step = 300;
					player->fire_counter++;
				}
				else if (player->fire_counter == 5) {
					player->fire_animate += 75;
					player->fire_counter++;
				}
				else if (player->fire_counter == 6) {
					player->fire_animate += 75;
					player->fire_counter++;
				}
				else if (player->fire_counter == 7) {
					player->fire_animate += 65;
					player->fire_counter++;
				}
				else if (player->fire_counter == 8) {
					player->fire_animate += 65;
					player->fire_counter++;
				}
				else if (player->fire_counter == 9) {
					player->fire_animate += 38;
					player->fire_counter++;
				}
				else if (player->fire_counter == 10) {
					player->fire_animate += 38;
					player->fire_counter++;
				}
				else if (player->fire_counter == 11) {
					player->fire_counter++;
				}
				else if (player->fire_counter == 12) {
					player->fire_counter = 0;
					player->fire_animate = 440;
					player->animate_dragon = 15;
					player->dragon_counter = 0;
					key_player_one[KEY_UP] = false;
					key_player_one[KEY_B] = false;
				}
			}
			redraw = true;
			return;
		}

		if (player->player_state == ready && player->ready_counter <= 6) {
			player->ready_counter++;     
			player->animate_ready += 58.4; 
			player->step = 58.4;
		}
		if (player->player_state == ready && player->ready_counter == 7) {
			player->ready_counter = 0;
			player->animate_ready = 89;
		}

		if (key_player_one[KEY_UP] && player->pos_y >= -100) {
			player->player_state = jump;
			if (player->jump_counter < 6) {
				player->pos_y -= 40;
				player->jump_counter++;
			}
			else if (player->jump_counter >= 6 && player->jump_counter < 12)
			{
				player->jump_counter++;
				player->pos_y += 40;
				if (player->jump_counter == 11) {
					player->pos_y += 40;
					player->animate_jump += 55;
					player->jump_counter++;
					player->step = 55;
				}
			}
			else if (player->jump_counter == 12) {
				player->animate_jump += 55;
				player->jump_counter++;
				player->step = 55;
			}
			else if (player->jump_counter == 13) {
				player->player_state = ready;
				key_player_one[KEY_UP] = false;
				if (key_player_one[KEY_RIGHT]) {
					key_player_one[KEY_RIGHT] = false;
				}
				if (key_player_one[KEY_LEFT]) {
					key_player_one[KEY_LEFT] = false;
				}
				player->jump_counter = 0;
				player->animate_jump = 580;
			}
		}

		if (key_player_one[KEY_DOWN] && player->pos_y <= SCREEN_H) {
			player->player_state = crouch;
			if (player->crouch_counter == 0) {
				player->crouch_counter++;
			}
			else if (player->crouch_counter == 1) {
				player->crouch_counter++;
				player->animate_crouch += 60;
				player->step = 60;
			}
			else if (player->crouch_counter == 2) {
				player->animate_crouch = 1126;
			}
			player->pos_y += 0;
		}

		if (key_player_one[KEY_LEFT] && player->pos_x >= 4.0) {
			player->player_state = back;
			if (player->flip == 0) {
				if (player->back_counter <= 6) {
					player->back_counter++;
					player->animate_back -= 58;
					player->step = 58;
				}
				else {
					player->back_counter = 0;
					player->animate_back = 421;
				}
			}
			else if (player->flip == 1) {
				if (player->back_counter == 0){
					player->back_counter = 0;
					player->animate_back = 15;
					player->back_counter++;
				}
				else if (player->back_counter >= 1 && player->back_counter <= 6) {
					player->back_counter++;
					player->animate_back += 58;
					player->step = 58;
				}
				else {
					player->back_counter = 0;
					player->animate_back = 15;
				}
			}
			player->pos_x -= 20.0;
		}

		if (key_player_one[KEY_RIGHT] && player->pos_x <= SCREEN_W - 155) {
			player->player_state = farward;
			if (player->flip == 0) {
				if (player->farward_counter <= 6) {
					player->farward_counter++;
					player->animate_farward += 58;
					player->step = 58;
				}
				else {
					player->farward_counter = 0;
					player->animate_farward = 15;
				}
			}
			else if (player->flip == 1) {
				if (player->farward_counter <= 6) {
					player->farward_counter++;
					player->animate_farward -= 58;
					player->step = 58;
				}
				else {
					player->farward_counter = 0;
					player->animate_farward = 421;
				}
			}
			player->pos_x += 20.0;
		}

		if (key_player_one[KEY_M] && player->pos_x <= SCREEN_W) {
			player->player_state = low_punch;
			if (player->low_punch_counter == 0) {
			}
			else if (player->low_punch_counter == 1) {
				player->animate_low_punch += 55;
				player->step = 55;
			}
			else if (player->low_punch_counter == 2) {
				player->animate_low_punch += 103;
				player->step = 103;
			}
			else if (player->low_punch_counter == 3) {
				player->animate_low_punch += 50;
				player->step = 50;
			}
			else if (player->low_punch_counter == 4) {
				player->animate_low_punch += 70;
				player->step = 70;
			}
			else if (player->low_punch_counter == 5) {
				key_player_one[KEY_M] = false;
				player->animate_low_punch = 15;
				player->low_punch_counter = 0;
			}

		}

		if (key_player_one[KEY_K] && player->pos_x <= SCREEN_W) {
			player->player_state = high_punch;
			if (player->high_punch_counter == 0) {
			}
			else if (player->high_punch_counter == 1) {
				player->animate_high_punch += 55;
				player->step = 55;
			}
			else if (player->high_punch_counter == 2) {
				player->animate_high_punch += 65;
				player->step = 65;
			}
			else if (player->high_punch_counter == 3) {
				player->animate_high_punch += 103;
				player->step = 103;
			}
			else if (player->high_punch_counter == 4) {
				player->animate_high_punch += 55;
				player->step = 55;
			}
			else if (player->high_punch_counter == 5) {
				player->animate_high_punch += 70;
				player->step = 70;
			}
			else if (player->high_punch_counter == 6) {
				key_player_one[KEY_K] = false;
				player->animate_high_punch = 15;
				player->high_punch_counter = 0;
			}

		}

		if (key_player_one[KEY_B] && player->pos_x <= SCREEN_W) {
			player->player_state = block;
			if (player->block_counter < 2) {
				player->animate_block += 55;
				player->block_counter++;
				player->step = 55;
			}
		}

		if (key_player_one[KEY_B] && key_player_one[KEY_DOWN] && player->pos_x <= SCREEN_W) {
			player->player_state = low_block;
		}

		if (key_player_one[KEY_UP] && key_player_one[KEY_RIGHT] && player->pos_x <= SCREEN_W && player->pos_x <= SCREEN_W - 155) {
			player->player_state = jump_forward;
			player->pos_x += 25;
			if (tmp_pos_y < player->pos_y && player->pos_y > SCREEN_H / 3.9) {
				player->pos_y = SCREEN_H / 2.2;
				player->animate_jump_forward = 770;
				player->jump_forward_counter = 0;
				key_player_one[KEY_RIGHT] = false;
				key_player_one[KEY_UP] = false;
				player->jump_counter = 0;
				player->animate_jump = 580;
			}
			else if (player->jump_forward_counter == 0) {
				player->jump_forward_counter++;
			}
			else if (player->jump_forward_counter < 7) {
				player->animate_jump_forward += 50;
				player->jump_forward_counter++;
				player->step = 50;
			}
			else if (player->jump_forward_counter >= 7) {
				player->animate_jump_forward = 820;
				player->jump_forward_counter = 1;
			}
		}

		if (key_player_one[KEY_UP] && key_player_one[KEY_LEFT] && player->pos_x >= 0 && player->pos_x <= SCREEN_W) {
			player->player_state = jump_backward;
			player->pos_x -= 25;
			if (tmp_pos_y < player->pos_y && player->pos_y > SCREEN_H / 3.9) {
				player->pos_y = SCREEN_H / 2.2;
				player->animate_jump_forward = 770;
				player->jump_forward_counter = 0;
				key_player_one[KEY_LEFT] = false;
				key_player_one[KEY_UP] = false;
				player->jump_counter = 0;
				player->animate_jump = 580;
			}
			else if (player->jump_forward_counter == 0) {
				player->jump_forward_counter++;
			}
			else if (player->jump_forward_counter == 1) {
				player->jump_forward_counter++;
				player->animate_jump_forward = 1070;
			}
			else if (player->jump_forward_counter > 1 && player->jump_forward_counter < 7) {
				player->animate_jump_forward -= 50;
				player->jump_forward_counter++;
				player->step = 50;
			}
			else if (player->jump_forward_counter >= 7) {
				player->animate_jump_forward = 1070;
				player->jump_forward_counter = 1;
			}
		}

		if (key_player_one[KEY_N] && player->pos_x <= SCREEN_W) {
			player->player_state = low_kick;
			if (player->low_kick_counter == 0) {
			}
			else if (player->low_kick_counter >= 1 && player->low_kick_counter < 2) {
				player->animate_low_kick += 55;
				player->step = 55;
			}
			else if (player->low_kick_counter == 2) {
				player->animate_low_kick += 52;
				player->step = 52;
			}
			else if (player->low_kick_counter == 3) {
				player->animate_low_kick += 55;
				player->step = 55;
			}
			else if (player->low_kick_counter == 4) {
				player->animate_low_kick += 60;
				player->step = 60;
			}
			else if (player->low_kick_counter == 5) {
				player->animate_low_kick += 90;
				player->step = 90;
			}
			else if (player->low_kick_counter == 6) {
				player->low_kick_counter = 0;
				player->animate_low_kick = 425;
				key_player_one[KEY_N] = false;
			}
		}
		if (key_player_one[KEY_J] && player->pos_x <= SCREEN_W) {
			player->player_state = high_kick;
			if (player->high_kick_counter == 0) {
			}
			else if (player->high_kick_counter == 1) {
				player->animate_high_kick += 51;
				player->step = 51;
			}
			else if (player->high_kick_counter == 2) {
				player->animate_high_kick += 55;
				player->step = 55;
			}
			else if (player->high_kick_counter == 3) {
				player->animate_high_kick += 50;
				player->step = 50;
			}
			else if (player->high_kick_counter == 4) {
				player->animate_high_kick += 70;
				player->step = 70;
			}
			else if (player->high_kick_counter == 5) {
				player->animate_high_kick += 80;
				player->step = 80;
			}
			else if (player->high_kick_counter == 6) {
				player->high_kick_counter = 0;
				player->animate_high_kick = 15;
				key_player_one[KEY_J] = false;
			}
		}

		redraw = true;
	}

	else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
		doexit = true;
	}
	else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
		//key down press handler
		switch (ev.keyboard.keycode) {
		case ALLEGRO_KEY_UP:
			key_player_one[KEY_UP] = true;
			break;

		case ALLEGRO_KEY_DOWN:
			key_player_one[KEY_DOWN] = true;
			break;

		case ALLEGRO_KEY_LEFT:
			key_player_one[KEY_LEFT] = true;
			break;

		case ALLEGRO_KEY_RIGHT:
			key_player_one[KEY_RIGHT] = true;
			break;

		case ALLEGRO_KEY_M:
			key_player_one[KEY_M] = true;
			break;

		case ALLEGRO_KEY_K:
			key_player_one[KEY_K] = true;
			break;

		case ALLEGRO_KEY_B:
			key_player_one[KEY_B] = true;
			break;

		case ALLEGRO_KEY_N:
			key_player_one[KEY_N] = true;
			break;

		case ALLEGRO_KEY_J:
			key_player_one[KEY_J] = true;
			break;
		}
	}
	else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
	//key up handler
		switch (ev.keyboard.keycode) {
		case ALLEGRO_KEY_UP:
			/*
			if (player->player_state != jump && player->player_state!=dragon) {
				if (player->jump_counter >= 9) {
					key_player_one[KEY_UP] = false;
					player->jump_counter = 0;
				}
				else
				{
					key_player_one[KEY_UP] = true;
				}
			}
			break;
			*/
		case ALLEGRO_KEY_DOWN:
			player->animate_crouch = 982;
			player->crouch_counter = 0;
			key_player_one[KEY_DOWN] = false;
			break;

		case ALLEGRO_KEY_LEFT:
			if (player->player_state != jump_backward) {
				if (player->flip == 0) {
					player->back_counter = 0;
					player->animate_back = 421;
				}
				else if (player->flip == 1) {
					player->animate_back = 15;
					player->back_counter = 0;
				}
				key_player_one[KEY_LEFT] = false;
			}
			break;

		case ALLEGRO_KEY_RIGHT:
			if (player->player_state != jump_forward) {
				if (player->flip == 0) {
					player->animate_farward = 15;
					player->farward_counter = 0;
				}
				else if (player->flip == 1) {
					player->back_counter = 0;
					player->animate_back = 421;
				}
				key_player_one[KEY_RIGHT] = false;
			}
			break;

		case ALLEGRO_KEY_M:
			if (player->player_state != low_punch) {
				player->animate_low_punch = 15;
				player->low_punch_counter = 0;
				key_player_one[KEY_M] = false;
			}
			break;

		case ALLEGRO_KEY_K:
			if (player->player_state!=high_punch) {
				player->animate_high_punch = 15;
				player->high_punch_counter = 0;
				key_player_one[KEY_K] = false;
			}
			break;

		case ALLEGRO_KEY_B:
			if (player->player_state != dragon) {
				player->animate_block = 800;
				player->block_counter = 0;
				player->animate_low_block = 1210;
				key_player_one[KEY_B] = false;
			}
			break;

		case ALLEGRO_KEY_N:
			if (player->player_state != low_kick) {
				player->animate_low_kick = 425;
				player->low_kick_counter = 0;
				key_player_one[KEY_N] = false;
			}
			break;

		case ALLEGRO_KEY_J:
			if (player->player_state != high_kick) {
				player->animate_high_kick = 15;
				player->high_kick_counter = 0;
				key_player_one[KEY_J] = false;
			}
			break;

		case ALLEGRO_KEY_ESCAPE:
			doexit = true;
			break;
		}
	}
}