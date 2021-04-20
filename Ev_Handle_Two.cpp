#include "pch.h"
#include "player_info.h"
#include <iostream>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"

using namespace std;

//event handler for player two:  to player->animate_ready eipame einai h thesh ths maskas sto X. to player->ready_counter einai ta posa frames theloume gia to sequence
//ara mporoume na poume ama counter = 5 (dld to 5 frame)  player->animate_ready=1000 (dld h maska sto 1000 ston X aksona) ara aplws gia na metakiname thn maska aplos += step h ena stathero aritmo pou theloume.
void Event_Handler_Two(player_t *player, ALLEGRO_EVENT ev) {
	float tmp_pos_y = player->pos_y;
	if (ev.type == ALLEGRO_EVENT_TIMER) {
		//event handler for states
		if (player->player_state == dizzy) {
			for (int g = 0; g < 9; g++) {
				key_player_two[g] = false;
			}
			if (player->dizzy_counter <= 5) {
				player->dizzy_counter++;
				player->animate_dizzy += 51;
				player->step = 51;
			}
			else if (player->dizzy_counter == 6) {
				player->animate_dizzy = 1032;
				player->dizzy_counter = 0;
			}
			redraw = true;			
			return;
		}

		if (player->player_state == dead) {
			for (int g = 0; g < 9; g++) {
				key_player_two[g] = false;
			}
			if (player->dead_counter <= 6) {
				player->dead_counter++;
				player->animate_dead += 45;
				player->step = 51;
			}
			redraw = true;
			return;
		}
		player->player_state = ready;
		if (player->ready_counter == 0) {
			player->ready_counter++;
		}
		if (player->player_state == ready && player->ready_counter >=1 && player->ready_counter <= 6) {
			player->ready_counter++;     
			player->animate_ready += 102; 
			player->step = 102;
		}
		if (player->player_state == ready && player->ready_counter == 7) {
			player->ready_counter = 0;
			player->animate_ready = 89;
		}
		if (key_player_two[KEY_S-9] && player->pos_y <= SCREEN_H) {
			player->player_state = crouch;
			if (player->crouch_counter == 0) {
				player->crouch_counter++;
			}
			else if (player->crouch_counter == 1) {
				player->crouch_counter++;
				player->animate_crouch += 56;
				player->step = 56;
			}
			else if (player->crouch_counter == 2) {
				player->animate_crouch = 1263;
			}
			player->pos_y += 0;
		}
		if (key_player_two[KEY_W-9] && player->pos_y >= -100) {
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
				key_player_two[KEY_W-9] = false;
				if (key_player_two[KEY_D-9]) {
					key_player_two[KEY_D-9] = false;
				}
				if (key_player_two[KEY_A-9]) {
					key_player_two[KEY_A-9] = false;
				}
				player->jump_counter = 0;
				player->animate_jump = 525;
			}
		}

		if (key_player_two[KEY_A - 9] && player->pos_x >= 4.0) {
			player->player_state = farward;
			if (player->flip == 1) {
				if (player->farward_counter < 2){
					player->farward_counter++;
					player->animate_farward += 54;
					player->step = 54;
				}
				else if (player->farward_counter == 2) {
					player->farward_counter++;
					player->animate_farward += 50;
					player->step = 50;
				}
				else if (player->farward_counter == 3) {
					player->farward_counter++;
					player->animate_farward += 50;
					player->step = 50;
				}
				else if (player->farward_counter == 4) {
					player->farward_counter++;
					player->animate_farward += 44;
					player->step = 44;
				}
				else if (player->farward_counter == 5) {
					player->farward_counter++;
					player->animate_farward += 50;
					player->step = 50;
				}
				else if (player->farward_counter == 6) {
					player->farward_counter++;
					player->animate_farward += 50;
					player->step = 50;
				}
				else {
					player->farward_counter = 0;
					player->animate_farward = 20;
				}
			}
			else if (player->flip == 0) {
				if (player->farward_counter < 1) {
					player->farward_counter++;
					player->animate_farward -= 55;
					player->step = 55;
				}
				else if (player->farward_counter == 1) {
					player->farward_counter++;
					player->animate_farward -= 48;
					player->step = 48;
				}
				else if (player->farward_counter == 2) {
					player->farward_counter++;
					player->animate_farward -= 48;
					player->step = 48;
				}
				else if (player->farward_counter == 3) {
					player->farward_counter++;
					player->animate_farward -= 52;
					player->step = 52;
				}
				else if (player->farward_counter == 4) {
					player->farward_counter++;
					player->animate_farward -= 48;
					player->step = 48;
				}
				else if (player->farward_counter == 5) {
					player->farward_counter++;
					player->animate_farward -= 62;
					player->step = 62;
				}
				else if (player->farward_counter == 6) {
					player->farward_counter++;
					player->animate_farward -= 50;
					player->step = 50;
				}
				else {
					player->farward_counter = 0;
					player->animate_farward = 432;
				}
			}
			player->pos_x -= 20.0;
		}
		if (key_player_two[KEY_D -9] && player->pos_x <= SCREEN_W - 155) {
			player->player_state = back;
			if (player->flip == 1) {
				if (player->back_counter < 1) {
					player->back_counter++;
					player->animate_back -= 55;
					player->step = 55;
				}
				else if (player->back_counter == 1) {
					player->back_counter++;
					player->animate_back -= 48;
					player->step = 48;
				}
				else if (player->back_counter == 2) {
					player->back_counter++;
					player->animate_back -= 48;
					player->step = 48;
				}
				else if (player->back_counter == 3) {
					player->back_counter++;
					player->animate_back -= 52;
					player->step = 52;
				}
				else if (player->back_counter == 4) {
					player->back_counter++;
					player->animate_back -= 48;
					player->step = 48;
				}
				else if (player->back_counter == 5) {
					player->back_counter++;
					player->animate_back -= 62;
					player->step = 62;
				}
				else if (player->back_counter == 6) {
					player->back_counter++;
					player->animate_back -= 50;
					player->step = 50;
				}
				else {
					player->back_counter = 0;
					player->animate_back = 432;
				}
			}
			else if (player->flip == 0) {
				if (player->back_counter < 2) {
					player->back_counter++;
					player->animate_back += 55;
					player->step = 55;
				}
				else if (player->back_counter == 2) {
					player->back_counter++;
					player->animate_back += 50;
					player->step = 50;
				}
				else if (player->back_counter == 3) {
					player->back_counter++;
					player->animate_back += 50;
					player->step = 50;
				}
				else if (player->back_counter == 4) {
					player->back_counter++;
					player->animate_back += 44;
					player->step = 44;
				}
				else if (player->back_counter == 5) {
					player->back_counter++;
					player->animate_back += 50;
					player->step = 50;
				}
				else if (player->back_counter == 6) {
					player->back_counter++;
					player->animate_back += 50;
					player->step = 50;
				}
				else {
					player->back_counter = 0;
					player->animate_back = 20;
				}
			}
			player->pos_x += 20.0;
		}
		if (key_player_two[KEY_F - 9] && player->pos_x <= SCREEN_W) {
			player->player_state = block;
			if (player->block_counter == 0) {
				player->block_counter++;
			}
			else if (player->block_counter < 3) {
				player->animate_block += 55;
				player->block_counter++;
				player->step = 55;
			}
		}
		if (key_player_two[KEY_F - 9] && key_player_two[KEY_S - 9] && player->pos_x <= SCREEN_W) {
			player->player_state = low_block;
		}
		if (key_player_two[KEY_H - 9] && player->pos_x <= SCREEN_W) {
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
				key_player_two[KEY_H - 9] = false;
				player->animate_low_punch = 15;
				player->low_punch_counter = 0;
			}
		}
		if (key_player_two[KEY_U - 9] && player->pos_x <= SCREEN_W) {
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
				key_player_two[KEY_U - 9] = false;
				player->animate_high_punch = 15;
				player->high_punch_counter = 0;
			}
		}
		if (key_player_two[KEY_G - 9] && player->pos_x <= SCREEN_W) {
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
				key_player_two[KEY_G - 9] = false;
			}
		}
		if (key_player_two[KEY_Y - 9] && player->pos_x <= SCREEN_W) {
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
				key_player_two[KEY_Y - 9] = false;
			}
		}
		if (key_player_two[KEY_W-9] && key_player_two[KEY_D-9] && player->pos_x <= SCREEN_W && player->pos_x <= SCREEN_W - 155) {
			player->player_state = jump_forward;
			player->pos_x += 25;
			if (tmp_pos_y < player->pos_y && player->pos_y > SCREEN_H / 3.9) {
				player->pos_y = SCREEN_H / 2.2;
				player->animate_jump_forward = 722;
				player->jump_forward_counter = 0;
				key_player_two[KEY_D-9] = false;
				key_player_two[KEY_W-9] = false;
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
				player->animate_jump_forward = 777;
				player->jump_forward_counter = 1;
			}
		}

		if (key_player_two[KEY_W-9] && key_player_two[KEY_A-9] && player->pos_x >= 0 && player->pos_x <= SCREEN_W) {
			player->player_state = jump_backward;
			player->pos_x -= 25;
			if (tmp_pos_y < player->pos_y && player->pos_y > SCREEN_H / 3.9) {
				player->pos_y = SCREEN_H / 2.2;
				player->animate_jump_forward = 770;
				player->jump_forward_counter = 0;
				key_player_two[KEY_A-9] = false;
				key_player_two[KEY_W-9] = false;
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
	}
	else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
		doexit = true;
	}
	else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
	//key down press handler
		switch (ev.keyboard.keycode) {
		case ALLEGRO_KEY_W:
			key_player_two[KEY_W - 9] = true;
			break;

		case ALLEGRO_KEY_S:
			key_player_two[KEY_S - 9] = true;
			break;

		case ALLEGRO_KEY_A:
			key_player_two[KEY_A - 9] = true;
			break;

		case ALLEGRO_KEY_D:
			key_player_two[KEY_D -9] = true;
			break;

		case ALLEGRO_KEY_F:
			key_player_two[KEY_F - 9] = true;
			break;

		case ALLEGRO_KEY_H:
			key_player_two[KEY_H - 9] = true;
			break;

		case ALLEGRO_KEY_U:
			key_player_two[KEY_U - 9] = true;
			break;

		case ALLEGRO_KEY_Y:
			key_player_two[KEY_Y - 9] = true;
			break;

		case ALLEGRO_KEY_G:
			key_player_two[KEY_G - 9] = true;
			break;
		}
	}
	else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
	//key down press handler
		switch (ev.keyboard.keycode) {
		case ALLEGRO_KEY_W:
			if (player->player_state != jump) {
				if (player->jump_counter >= 9) {
					key_player_two[KEY_W-9] = false;
					player->jump_counter = 0;
				}
				else
				{
					key_player_two[KEY_W-9] = true;
				}
			}
			break;

		case ALLEGRO_KEY_S:
			player->animate_crouch = 1151;
			player->crouch_counter = 0;
			key_player_two[KEY_S - 9] = false;
			break;

		case ALLEGRO_KEY_A:
			if (player->player_state != jump_backward) {
				if (player->flip == 1) {
					player->animate_farward = 20;
					player->farward_counter = 0;
				}
				else if (player->flip == 0) {
					player->farward_counter = 0;
					player->animate_farward = 432;
				}
				key_player_two[KEY_A - 9] = false;
			}
			break;

		case ALLEGRO_KEY_D:
			if (player->player_state != jump_forward) {
				if (player->flip == 1) {
					player->back_counter = 0;
					player->animate_back = 432;
				}
				else if (player->flip == 0) {
					player->animate_back = 20;
					player->back_counter = 0;
				}
				key_player_two[KEY_D - 9] = false;
			}
			break;

		case ALLEGRO_KEY_F:
			player->animate_block = 970;
			player->block_counter = 0;
			player->animate_low_block = 1345; //den eixa pou allou na to valw
			key_player_two[KEY_F - 9] = false;
			break;

		case ALLEGRO_KEY_H:
			if (player->player_state != low_punch) {
				player->animate_low_punch = 15;
				player->low_punch_counter = 0;
				key_player_two[KEY_H - 9] = false;
			}
			break;

		case ALLEGRO_KEY_U:
			if (player->player_state != high_punch) {
				player->animate_high_punch = 15;
				player->high_punch_counter = 0;
				key_player_two[KEY_U - 9] = false;
			}
			break;

		case ALLEGRO_KEY_Y:
			if (player->player_state != high_kick) {
				player->animate_high_kick = 15;
				player->high_kick_counter = 0;
				key_player_two[KEY_Y - 9] = false;
			}
			break;

		case ALLEGRO_KEY_G:
			if (player->player_state != low_kick) {
				player->animate_low_kick = 425;
				player->low_kick_counter = 0;
				key_player_two[KEY_G - 9] = false;
			}
			break;
		}
	}
}