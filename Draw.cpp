#include "pch.h"
#include "player_info.h"
#include <iostream>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"

using namespace std;



void Player_Draw(player_t *player) {
	//for flipping characters
	int i = 1;	
	int k = 0;
	//for fatality animation (not good names i know)
	int w = 0;
	int o = 0;
	int l = 0;
	int oo = 0;
	int ll = 0;
	int ooo = 0;
	int lll = 0;
	int g = 0;
	int gg = 0;
	//player one animations
	if (player->player_number == 1) {
		//player one fatitality animation
		if (player->player_state == spear) {
			if (player->throw_spear_counter < 3) {
				al_draw_scaled_bitmap(player->player_bmp, player->throw_spear_animate, 1170, 68, 115, player->pos_x + k, player->pos_y + 20, i * 180, 240, player->flip);
			}
			else if (player->throw_spear_counter == 3) {
				al_draw_scaled_bitmap(player->player_bmp, player->throw_spear_animate, 1170, 68, 115, player->pos_x + k, player->pos_y + 20, i * 180, 240, player->flip);
				al_draw_scaled_bitmap(player->player_bmp, player->fly_spear_animate, 1280, 210, 70, player->spear_pos_x + k, player->pos_y + 20, i * 520, 200, player->flip);
			}
			else if (player->throw_spear_counter >= 4) {
				al_draw_scaled_bitmap(player->player_bmp, player->throw_spear_animate, 1170, 68, 115, player->pos_x + k, player->pos_y + 20, i * 180, 240, player->flip);
				al_draw_scaled_bitmap(player->player_bmp, player->drag_spear_animate, 1270, 160, 40, player->spear_pos_x + k, player->pos_y-20, i * 470, 130, player->flip);
				al_draw_scaled_bitmap(player->player_bmp, player->rope_spear_animate, 1270, 50, 100, player->pos_x + k+30, player->pos_y-10, i * 180, 350, player->flip);
			}
		}

		if (player->player_state == dragon) {
			if (player->flip) {
				i = -1;
				player->flip = 0;
				k = 130;

				w = -10;
				o = -90;
				l = -130;
				oo = -120;
				ll = -145;
				ooo = -150;
				lll = -180;
				g = -200;
				gg = -250;
			}
			if (player->dragon_counter <= 7) {
				al_draw_scaled_bitmap(player->player_bmp, player->animate_dragon, 1350, 55, 120, player->pos_x+k, player->pos_y, i*150, 250, player->flip);
			}
			else if (player->dragon_counter == 8) {
				al_draw_scaled_bitmap(player->player_bmp, player->animate_dragon, 1350, 60, 120, player->pos_x+k, player->pos_y, i * 150, 250, player->flip);
			}
			if (player->dragon_counter == 8) {
				if (player->fire_counter == 1) {
					al_draw_scaled_bitmap(player->player_bmp, player->fire_animate, 1450, 40, 40, player->pos_x+w + 70, player->pos_y + 65, i * 100, 150, player->flip);
				}
				else if (player->fire_counter == 2) {
					al_draw_scaled_bitmap(player->player_bmp, player->fire_animate, 1450, 27, 38, player->pos_x+o + 110, player->pos_y + 85, i * 100, 150, player->flip);
				}
				else if (player->fire_counter == 3) {
					al_draw_scaled_bitmap(player->player_bmp, player->fire_animate, 1450, 36, 46, player->pos_x+l + 130, player->pos_y + 110, i * 100, 150, player->flip);
				}
				else if (player->fire_counter == 4) {
					al_draw_scaled_bitmap(player->player_bmp, player->fire_animate, 1420, 50, 70, player->pos_x+oo + 125, player->pos_y + 100, i * 100, 150, player->flip);
				}
				else if (player->fire_counter == 5) {
					al_draw_scaled_bitmap(player->player_bmp, player->fire_animate, 1380, 60, 90, player->pos_x+ll + 140, player->pos_y + 65, i * 120, 180, player->flip);
				}
				else if (player->fire_counter == 6) {
					al_draw_scaled_bitmap(player->player_bmp, player->fire_animate, 1380, 65, 90, player->pos_x+ooo + 140, player->pos_y + 67, i * 130, 180, player->flip);
				}
				else if (player->fire_counter == 7) {
					al_draw_scaled_bitmap(player->player_bmp, player->fire_animate, 1380, 65, 90, player->pos_x+lll + 155, player->pos_y + 67, i * 130, 180, player->flip);
				}
				else if (player->fire_counter == 8) {
					al_draw_scaled_bitmap(player->player_bmp, player->fire_animate, 1380, 65, 90, player->pos_x+g + 155, player->pos_y + 67, i * 130, 180, player->flip);
				}
				else if (player->fire_counter == 9) {
					al_draw_scaled_bitmap(player->player_bmp, player->fire_animate, 1320, 45, 250, player->pos_x+gg + 185, player->pos_y - 55, i * 100, 500, player->flip);
				}
				else if (player->fire_counter == 10) {
					al_draw_scaled_bitmap(player->player_bmp, player->fire_animate, 1320, 40, 250, player->pos_x+gg + 185, player->pos_y - 55, i * 110, 500, player->flip);
				}
				else if (player->fire_counter == 11) {
					al_draw_scaled_bitmap(player->player_bmp, player->fire_animate, 1320, 40, 250, player->pos_x+gg + 185, player->pos_y - 55, i * 110, 500, player->flip);
				}
			}
		}
		//player one dizzy animation
		if (player->player_state == dizzy) {
			al_draw_scaled_bitmap(player->player_bmp, player->animate_dizzy, 845, 55, 120, player->pos_x, player->pos_y, 150, 250, player->flip); //ALLEGRO_FLIP_HORIZONTALY gia flip tou xarakthra
		}
		//player one ready animation
		if (player->player_state == ready) {
			al_draw_scaled_bitmap(player->player_bmp, player->animate_ready, 0, 55, 120, player->pos_x, player->pos_y, 150, 250, player->flip); //ALLEGRO_FLIP_HORIZONTALY gia flip tou xarakthra
		}
		//player one farward animation
		if (player->player_state == farward) {
			al_draw_scaled_bitmap(player->player_bmp, player->animate_farward, 130, 60, 120, player->pos_x, player->pos_y, 150, 250, player->flip);
		}
		//player one back animation
		if (player->player_state == back) {
			al_draw_scaled_bitmap(player->player_bmp, player->animate_back, 130, 60, 120, player->pos_x, player->pos_y, 150, 250, player->flip);
		}
		//player one crouch animation
		if (player->player_state == crouch) {
			al_draw_scaled_bitmap(player->player_bmp, player->animate_crouch, 0, 55, 120, player->pos_x, player->pos_y, 150, 250, player->flip);
		}
		//player one low punch animation
		if (player->player_state == low_punch) {
			if (player->flip) {
				i = -1;
				player->flip = 0;
				k = 130;
			}
			if (player->low_punch_counter == 0) {
				al_draw_scaled_bitmap(player->player_bmp, player->animate_low_punch, 366, 55, 114, player->pos_x+k, player->pos_y, i*150, 250, player->flip);
				player->low_punch_counter++;
			}
			else if (player->low_punch_counter == 1) {
				player->low_punch_counter++;
				al_draw_scaled_bitmap(player->player_bmp, player->animate_low_punch, 366, 80, 114, player->pos_x+k, player->pos_y, i*220, 250, player->flip);
			}
			else if (player->low_punch_counter == 2) {
				player->low_punch_counter++;
				al_draw_scaled_bitmap(player->player_bmp, player->animate_low_punch, 366, 55, 114, player->pos_x+k, player->pos_y, i*150, 250, player->flip);
			}
			else if (player->low_punch_counter == 3) {
				player->low_punch_counter++;
				al_draw_scaled_bitmap(player->player_bmp, player->animate_low_punch, 366, 70, 114, player->pos_x+k, player->pos_y, i*200, 250, player->flip);
			}
			else if (player->low_punch_counter == 4) {
				player->low_punch_counter++;
				al_draw_scaled_bitmap(player->player_bmp, player->animate_low_punch, 366, 80, 114, player->pos_x+k, player->pos_y, i*220, 250, player->flip);
			}
		}
		//player one high punch animation
		if (player->player_state == high_punch) {
			if (player->flip) {
				i = -1;
				player->flip = 0;
				k = 130;
			}
			if (player->high_punch_counter == 0) {
				al_draw_scaled_bitmap(player->player_bmp, player->animate_high_punch, 250, 55, 114, player->pos_x + k, player->pos_y, i * 150, 250, player->flip);
				player->high_punch_counter++;
			}
			else if (player->high_punch_counter == 1) {
				player->high_punch_counter++;
				al_draw_scaled_bitmap(player->player_bmp, player->animate_high_punch, 250, 70, 114, player->pos_x + k, player->pos_y, i * 210, 250, player->flip);
			}
			else if (player->high_punch_counter == 2) {
				player->high_punch_counter++;
				al_draw_scaled_bitmap(player->player_bmp, player->animate_high_punch, 250, 80, 114, player->pos_x + k, player->pos_y, i * 220, 250, player->flip);
			}
			else if (player->high_punch_counter == 3) {
				player->high_punch_counter++;
				al_draw_scaled_bitmap(player->player_bmp, player->animate_high_punch, 250, 55, 114, player->pos_x + k, player->pos_y, i * 150, 250, player->flip);
			}
			else if (player->high_punch_counter == 4) {
				player->high_punch_counter++;
				al_draw_scaled_bitmap(player->player_bmp, player->animate_high_punch, 250, 70, 114, player->pos_x + k, player->pos_y, i * 200, 250, player->flip);
			}
			else if (player->high_punch_counter == 5) {
				player->high_punch_counter++;
				al_draw_scaled_bitmap(player->player_bmp, player->animate_high_punch, 250, 80, 114, player->pos_x + k, player->pos_y, i * 220, 250, player->flip);
			}
		}
		//player one low kick animation
		if (player->player_state == low_kick) {
			if (player->flip) {
				i = -1;
				player->flip = 0;
				k = 130;
			}
			if (player->low_kick_counter == 0) {
				al_draw_scaled_bitmap(player->player_bmp, player->animate_low_kick, 480, 55, 114, player->pos_x + k, player->pos_y, i * 150, 250, player->flip);
				player->low_kick_counter++;
			}
			else if (player->low_kick_counter == 1) {
				al_draw_scaled_bitmap(player->player_bmp, player->animate_low_kick, 480, 55, 114, player->pos_x + k, player->pos_y, i * 150, 250, player->flip);
				player->low_kick_counter++;
			}
			else if (player->low_kick_counter == 2) {
				al_draw_scaled_bitmap(player->player_bmp, player->animate_low_kick, 480, 55, 114, player->pos_x + k, player->pos_y, i * 150, 250, player->flip);
				player->low_kick_counter++;
			}
			else if (player->low_kick_counter == 3) {
				al_draw_scaled_bitmap(player->player_bmp, player->animate_low_kick, 480, 55, 114, player->pos_x + k, player->pos_y, i * 150, 250, player->flip);
				player->low_kick_counter++;
			}
			else if (player->low_kick_counter == 4) {
				al_draw_scaled_bitmap(player->player_bmp, player->animate_low_kick, 480, 90, 114, player->pos_x + k, player->pos_y, i * 240, 250, player->flip);
				player->low_kick_counter++;
			}
			else if (player->low_kick_counter == 5) {
				al_draw_scaled_bitmap(player->player_bmp, player->animate_low_kick, 480, 80, 114, player->pos_x + k, player->pos_y, i * 220, 250, player->flip);
				player->low_kick_counter++;
			}
		}
		//player one high kick animation
		if (player->player_state == high_kick) {
			if (player->flip) {
				i = -1;
				player->flip = 0;
				k = 130;
			}
			if (player->high_kick_counter == 0) {
				al_draw_scaled_bitmap(player->player_bmp, player->animate_high_kick, 480, 55, 114, player->pos_x + k, player->pos_y, i * 150, 250, player->flip);
				player->high_kick_counter++;
			}
			else if (player->high_kick_counter == 1) {
				al_draw_scaled_bitmap(player->player_bmp, player->animate_high_kick, 480, 55, 114, player->pos_x + k, player->pos_y, i * 150, 250, player->flip);
				player->high_kick_counter++;
			}
			else if (player->high_kick_counter == 2) {
				al_draw_scaled_bitmap(player->player_bmp, player->animate_high_kick, 480, 55, 114, player->pos_x + k, player->pos_y, i * 150, 250, player->flip);
				player->high_kick_counter++;
			}
			else if (player->high_kick_counter == 3) {
				al_draw_scaled_bitmap(player->player_bmp, player->animate_high_kick, 480, 60, 114, player->pos_x + k, player->pos_y, i * 180, 250, player->flip);
				player->high_kick_counter++;
			}
			else if (player->high_kick_counter == 4) {
				al_draw_scaled_bitmap(player->player_bmp, player->animate_high_kick, 480, 80, 114, player->pos_x + k, player->pos_y, i * 220, 250, player->flip);
				player->high_kick_counter++;
			}
			else if (player->high_kick_counter == 5) {
				al_draw_scaled_bitmap(player->player_bmp, player->animate_high_kick, 480, 80, 114, player->pos_x + k, player->pos_y, i * 220, 250, player->flip);
				player->high_kick_counter++;
			}
		}
		//player one block animation
		if (player->player_state == block) {
			if (player->flip) {
				i = -1;
				player->flip = 0;
				k = 130;
			}
			al_draw_scaled_bitmap(player->player_bmp, player->animate_block, 0, 55, 120, player->pos_x + k, player->pos_y, i * 150, 250, player->flip);
		}
		//player one jump animation
		if (player->player_state == jump) {
			if (player->jump_counter <= 11) {
				al_draw_scaled_bitmap(player->player_bmp, player->animate_jump, 130, 55, 120, player->pos_x, player->pos_y, 150, 250, player->flip);
			}
			else if (player->jump_counter == 12 || player->jump_counter == 13) {
				al_draw_scaled_bitmap(player->player_bmp, player->animate_jump, 130, 55, 120, player->pos_x, player->pos_y, 150, 250, player->flip);
			}
		}
		//player one jump farward and jump backwards animation
		if (player->player_state == jump_forward || player->player_state == jump_backward) {
			al_draw_scaled_bitmap(player->player_bmp, player->animate_jump_forward, 130, 55, 120, player->pos_x, player->pos_y, 150, 250, player->flip);
		}
		if (player->player_state == low_block) {
			if (player->flip) {
				i = -1;
				player->flip = 0;
				k = 130;
			}
			al_draw_scaled_bitmap(player->player_bmp, player->animate_low_block, 0, 55, 120, player->pos_x + k, player->pos_y, i * 150, 250, player->flip);
		}
		//player one get hit animation
		if (player->player_state == get_hit) {
			if (player->get_hit_counter == 0) {
				player->get_hit_counter++;
				al_draw_scaled_bitmap(player->player_bmp, 15, 844, 55, 120, player->pos_x, player->pos_y, 150, 250, player->flip);
			}
			else if (player->get_hit_counter == 1) {
				player->get_hit_counter++;
				al_draw_scaled_bitmap(player->player_bmp, 70, 844, 55, 120, player->pos_x, player->pos_y, 150, 250, player->flip);
			}
			else if (player->get_hit_counter == 2) {
				al_draw_scaled_bitmap(player->player_bmp, 125, 844, 55, 120, player->pos_x, player->pos_y, 150, 250, player->flip);
			}
			else {
				player->get_hit_counter = 0;
			}
			
		}
	}
	//player two animations
	if (player->player_number == 2) {
		//player two dizzy animation
		if (player->player_state == dizzy) {
			al_draw_scaled_bitmap(player->player_bmp, player->animate_dizzy, 845, 55, 114, player->pos_x, player->pos_y, 150, 250, player->flip);
		}
		//player two dead animation
		if (player->player_state == dead) {
			al_draw_scaled_bitmap(player->skeleton->player_bmp, player->animate_dead, 1485, 55, 90, player->pos_x, player->pos_y, 150, 250, player->flip); 
		}
		//player two ready animation
		if (player->player_state == ready) {
			al_draw_scaled_bitmap(player->player_bmp, player->animate_ready, 0, 55, 120, player->pos_x, player->pos_y, 150, 250, player->flip);
		}
		//player two crouch animation
		if (player->player_state == crouch) {
			al_draw_scaled_bitmap(player->player_bmp, player->animate_crouch, 0, 55, 120, player->pos_x, player->pos_y, 150, 250, player->flip);
		}
		//player two farward animation
		if (player->player_state == farward) {
			if (player->farward_counter < 6) {
				al_draw_scaled_bitmap(player->player_bmp, player->animate_farward, 130, 50, 120, player->pos_x, player->pos_y, 140, 250, player->flip);
			}
			else {
				al_draw_scaled_bitmap(player->player_bmp, player->animate_farward, 130, 60, 120, player->pos_x, player->pos_y, 160, 250, player->flip);
			}
		}
		//player two back animation
		if (player->player_state == back) {
			if (player->back_counter < 6) {
				al_draw_scaled_bitmap(player->player_bmp, player->animate_back, 130, 50, 120, player->pos_x, player->pos_y, 140, 250, player->flip);
			}
			else {
				al_draw_scaled_bitmap(player->player_bmp, player->animate_back, 130, 60, 120, player->pos_x, player->pos_y, 160, 250, player->flip);
			}
		}
		//player two block animation
		if (player->player_state == block) {
			al_draw_scaled_bitmap(player->player_bmp, player->animate_block, 0, 55, 120, player->pos_x, player->pos_y, 150, 250, player->flip);
		}
		//player two low block animation
		if (player->player_state == low_block) {
			al_draw_scaled_bitmap(player->player_bmp, player->animate_low_block, 0, 55, 120, player->pos_x, player->pos_y, 150, 250, player->flip);
		}
		//player two low punch animation
		if (player->player_state == low_punch) {
			if (player->flip) {
				i = -1;
				player->flip = 0;
				k = 140;
			}
			else {
				i = 1;
				k = 0;
			}
			if (player->low_punch_counter == 0) {
				al_draw_scaled_bitmap(player->player_bmp, player->animate_low_punch, 365, 55, 110, player->pos_x + k, player->pos_y, i * 150, 250, player->flip);
				player->low_punch_counter++;
			}
			else if (player->low_punch_counter == 1) {
				player->low_punch_counter++;
				al_draw_scaled_bitmap(player->player_bmp, player->animate_low_punch, 365, 80, 110, player->pos_x + k, player->pos_y, i * 220, 250, player->flip);
			}
			else if (player->low_punch_counter == 2) {
				player->low_punch_counter++;
				al_draw_scaled_bitmap(player->player_bmp, player->animate_low_punch, 365, 55, 110, player->pos_x + k, player->pos_y, i * 150, 250, player->flip);
			}
			else if (player->low_punch_counter == 3) {
				player->low_punch_counter++;
				al_draw_scaled_bitmap(player->player_bmp, player->animate_low_punch, 365, 70, 110, player->pos_x + k, player->pos_y, i * 200, 250, player->flip);
			}
			else if (player->low_punch_counter == 4) {
				player->low_punch_counter++;
				al_draw_scaled_bitmap(player->player_bmp, player->animate_low_punch, 365, 80, 110, player->pos_x + k, player->pos_y, i * 220, 250, player->flip);
			}
		}
		//player two high punch animation
		if (player->player_state == high_punch) {
			if (player->flip) {
				i = -1;
				player->flip = 0;
				k = 140;
			}
			else {
				i = 1;
				k = 0;
			}
			if (player->high_punch_counter == 0) {
				al_draw_scaled_bitmap(player->player_bmp, player->animate_high_punch, 252, 55, 110, player->pos_x + k, player->pos_y, i * 150, 250, player->flip);
				player->high_punch_counter++;
			}
			else if (player->high_punch_counter == 1) {
				player->high_punch_counter++;
				al_draw_scaled_bitmap(player->player_bmp, player->animate_high_punch, 252, 70, 110, player->pos_x + k, player->pos_y, i * 210, 250, player->flip);
			}
			else if (player->high_punch_counter == 2) {
				player->high_punch_counter++;
				al_draw_scaled_bitmap(player->player_bmp, player->animate_high_punch, 252, 80, 110, player->pos_x + k, player->pos_y, i * 220, 250, player->flip);
			}
			else if (player->high_punch_counter == 3) {
				player->high_punch_counter++;
				al_draw_scaled_bitmap(player->player_bmp, player->animate_high_punch, 252, 55, 110, player->pos_x + k, player->pos_y, i * 150, 250, player->flip);
			}
			else if (player->high_punch_counter == 4) {
				player->high_punch_counter++;
				al_draw_scaled_bitmap(player->player_bmp, player->animate_high_punch, 252, 70, 110, player->pos_x + k, player->pos_y, i * 200, 250, player->flip);
			}
			else if (player->high_punch_counter == 5) {
				player->high_punch_counter++;
				al_draw_scaled_bitmap(player->player_bmp, player->animate_high_punch, 252, 80, 110, player->pos_x + k, player->pos_y, i * 220, 250, player->flip);
			}
		}
		//player two low kick animation
		if (player->player_state == low_kick) {
			if (player->flip) {
				i = -1;
				player->flip = 0;
				k = 140;
			}
			else {
				i = 1;
				k = 0;
			}
			if (player->low_kick_counter == 0) {
				al_draw_scaled_bitmap(player->player_bmp, player->animate_low_kick, 480, 55, 110, player->pos_x + k, player->pos_y, i * 150, 250, player->flip);
				player->low_kick_counter++;
			}
			else if (player->low_kick_counter == 1) {
				al_draw_scaled_bitmap(player->player_bmp, player->animate_low_kick, 480, 55, 110, player->pos_x + k, player->pos_y, i * 150, 250, player->flip);
				player->low_kick_counter++;
			}
			else if (player->low_kick_counter == 2) {
				al_draw_scaled_bitmap(player->player_bmp, player->animate_low_kick, 480, 55, 110, player->pos_x + k, player->pos_y, i * 150, 250, player->flip);
				player->low_kick_counter++;
			}
			else if (player->low_kick_counter == 3) {
				al_draw_scaled_bitmap(player->player_bmp, player->animate_low_kick, 480, 55, 110, player->pos_x + k, player->pos_y, i * 150, 250, player->flip);
				player->low_kick_counter++;
			}
			else if (player->low_kick_counter == 4) {
				al_draw_scaled_bitmap(player->player_bmp, player->animate_low_kick, 480, 90, 110, player->pos_x + k, player->pos_y, i * 240, 250, player->flip);
				player->low_kick_counter++;
			}
			else if (player->low_kick_counter == 5) {
				al_draw_scaled_bitmap(player->player_bmp, player->animate_low_kick, 480, 80, 110, player->pos_x + k, player->pos_y, i * 220, 250, player->flip);
				player->low_kick_counter++;
			}
		}
		//player two high kick animation
		if (player->player_state == high_kick) {
			if (player->flip) {
				i = -1;
				player->flip = 0;
				k = 140;
			}
			else {
				i = 1;
				k = 0;
			}
			if (player->high_kick_counter == 0) {
				al_draw_scaled_bitmap(player->player_bmp, player->animate_high_kick, 480, 55, 110, player->pos_x + k, player->pos_y, i * 150, 250, player->flip);
				player->high_kick_counter++;
			}
			else if (player->high_kick_counter == 1) {
				al_draw_scaled_bitmap(player->player_bmp, player->animate_high_kick, 480, 55, 110, player->pos_x + k, player->pos_y, i * 150, 250, player->flip);
				player->high_kick_counter++;
			}
			else if (player->high_kick_counter == 2) {
				al_draw_scaled_bitmap(player->player_bmp, player->animate_high_kick, 480, 55, 110, player->pos_x + k, player->pos_y, i * 150, 250, player->flip);
				player->high_kick_counter++;
			}
			else if (player->high_kick_counter == 3) {
				al_draw_scaled_bitmap(player->player_bmp, player->animate_high_kick, 480, 60, 110, player->pos_x + k, player->pos_y, i * 180, 250, player->flip);
				player->high_kick_counter++;
			}
			else if (player->high_kick_counter == 4) {
				al_draw_scaled_bitmap(player->player_bmp, player->animate_high_kick, 480, 80, 110, player->pos_x + k, player->pos_y, i * 220, 250, player->flip);
				player->high_kick_counter++;
			}
			else if (player->high_kick_counter == 5) {
				al_draw_scaled_bitmap(player->player_bmp, player->animate_high_kick, 480, 80, 110, player->pos_x + k, player->pos_y, i * 220, 250, player->flip);
				player->high_kick_counter++;
			}
		}
		//player two jump animation
		if (player->player_state == jump) {
			if (player->jump_counter <= 11) {
				al_draw_scaled_bitmap(player->player_bmp, player->animate_jump, 130, 55, 120, player->pos_x, player->pos_y, 150, 250, player->flip);
			}
			else if (player->jump_counter == 12 || player->jump_counter == 13) {
				al_draw_scaled_bitmap(player->player_bmp, player->animate_jump, 130, 55, 120, player->pos_x, player->pos_y, 150, 250, player->flip);
			}
		}
		//player two jump farward and jump backward animation
		if (player->player_state == jump_forward || player->player_state == jump_backward) {
			al_draw_scaled_bitmap(player->player_bmp, player->animate_jump_forward, 130, 55, 120, player->pos_x, player->pos_y, 150, 250, player->flip);
		}
		//player two get hit animation
		if (player->player_state == get_hit) {
			if (player->get_hit_counter == 0) {
				player->get_hit_counter++;
				al_draw_scaled_bitmap(player->player_bmp, 20, 844, 55, 114, player->pos_x, player->pos_y, 150, 250, player->flip);
			}
			else if (player->get_hit_counter == 1) {
				player->get_hit_counter++;
				al_draw_scaled_bitmap(player->player_bmp, 75, 844, 55, 114, player->pos_x, player->pos_y, 150, 250, player->flip);
			}
			else if (player->get_hit_counter == 2) {
				al_draw_scaled_bitmap(player->player_bmp, 130, 844, 55, 114, player->pos_x, player->pos_y, 150, 250, player->flip);
			}
			else {
				player->get_hit_counter = 0;
			}
		}
	}

}