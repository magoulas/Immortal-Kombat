#include "pch.h"
#include "player_info.h"
#include <iostream>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"

using namespace std;
//colision ditection for both players
bool Collision(player_t *player_one, player_t *player_two) {
	if ( (player_one->pos_x + 2.3*player_one->step >=  player_two->pos_x) && (player_one->pos_x + 0.5 * player_one->step <= player_two->pos_x + 2.3*player_two->step) ) {
		return true;
	}
	
	return false;
}
//Damage culculation and get hit state handler
void Damage_Counter(player_t *player_one, player_t *player_two) {
	if ((player_one->player_state == ready || player_one->player_state == get_hit) && player_two->player_state == low_punch) {
		if (player_one->player_state == ready) {
			player_one->player_state = get_hit;
		}
		if (player_two->low_punch_counter == 4) {
			player_one->player_state = ready;
			player_one->get_hit_counter = 0;
			player_one->hit_points += 15;
			cout << "p1 ready vs p2 low_punch\n";
		}
		if (player_one->hit_points >= player_one->hit_points_max) {
			cout << "player1 dead\n";
			player_one->hit_points = player_one->hit_points_max-10;
			player_one->player_state = dizzy;
		}
		
	}
	else if ((player_one->player_state == ready || player_one->player_state == get_hit) && player_two->player_state == high_punch) {
		if (player_one->player_state == ready) {
			player_one->player_state = get_hit;
		}
		if (player_two->high_punch_counter == 4) {
			player_one->player_state = ready;
			player_one->get_hit_counter = 0;
			player_one->hit_points += 15;
			cout << "p1 ready vs p2 high_punch\n";
		}
		if (player_one->hit_points >= player_one->hit_points_max) {
			cout << "player1 dead\n";
			player_one->hit_points = player_one->hit_points_max;
			player_one->player_state = dizzy;
		}
		
	}
	else if ((player_one->player_state == ready || player_one->player_state == get_hit) && player_two->player_state == low_kick) {
		if (player_one->player_state == ready) {
			player_one->player_state = get_hit;
		}
		if (player_two->low_kick_counter == 4) {
			player_one->player_state = ready;
			player_one->get_hit_counter = 0;
			player_one->hit_points += 25;
			cout << "p1 ready vs p2 low_kick\n";
		}
		}
		if (player_one->hit_points >= player_one->hit_points_max) {
			cout << "player1 dead\n";
			player_one->hit_points = player_one->hit_points_max;
			player_one->player_state = dizzy;
		}
		
	else if ((player_one->player_state == ready || player_one->player_state == get_hit) && player_two->player_state == high_kick) {
		if (player_one->player_state == ready) {
			player_one->player_state = get_hit;
		}
		if (player_two->high_kick_counter == 4) {
			player_one->player_state = ready;
			player_one->get_hit_counter = 0;
			player_one->hit_points += 25;
			cout << "p1 ready vs p2 high_kick\n";
		}
		if (player_one->hit_points >= player_one->hit_points_max) {
			cout << "player1 dead\n";
			player_one->hit_points = player_one->hit_points_max;
			player_one->player_state = dizzy;
		}
		
	}
	else if ((player_two->player_state == ready || player_two->player_state == get_hit) && player_one->player_state == low_punch) {
		if (player_two->player_state == ready) {
			player_two->player_state = get_hit;
		}
		if (player_one->low_punch_counter == 4) {
			player_two->player_state = ready;
			player_two->get_hit_counter = 0;
			player_two->hit_points += 15;
			cout << "p2 ready vs p1 low_punch\n";
		}
		if (player_two->hit_points >= player_two->hit_points_max) {
			cout << "player2 dead\n";
			player_two->hit_points = player_two->hit_points_max;
			player_two->player_state = dizzy;
		}
	}
	else if ((player_two->player_state == ready || player_two->player_state == get_hit) && player_one->player_state == high_punch) {
		if (player_two->player_state == ready) {
			player_two->player_state = get_hit;
		}
		if (player_one->high_punch_counter == 5) {
			player_two->player_state = ready;
			player_two->get_hit_counter = 0;
			player_two->hit_points += 15;
			cout << "p2 ready vs p1 high_punch\n";
		}
		if (player_two->hit_points >= player_two->hit_points_max) {
			cout << "player2 dead\n";
			player_two->hit_points = player_two->hit_points_max;
			player_two->player_state = dizzy;
		}
	}
	else if ((player_two->player_state == ready || player_two->player_state == get_hit) && player_one->player_state == low_kick) {
		if (player_two->player_state == ready) {
			player_two->player_state = get_hit;
		}
		if (player_one->low_kick_counter == 5) {
			player_two->player_state = ready;
			player_two->get_hit_counter = 0;
			player_two->hit_points += 25;
			cout << "p2 ready vs p1 low_kick\n";
		}
		if (player_two->hit_points >= player_two->hit_points_max) {
			cout << "player2 dead\n";
			player_two->hit_points = player_two->hit_points_max;
			player_two->player_state = dizzy;
		}
	}
	else if ((player_two->player_state == ready || player_two->player_state == get_hit) && player_one->player_state == high_kick) {
		if (player_two->player_state == ready) {
			player_two->player_state = get_hit;
		}
		if (player_one->high_kick_counter == 5) {
			player_two->player_state = ready;
			player_two->get_hit_counter = 0;
			player_two->hit_points += 25;
			cout << "p2 ready vs p1 high_kick\n";
		}
		if (player_two->hit_points >= player_two->hit_points_max) {
			cout << "player2 dead\n";
			player_two->hit_points = player_two->hit_points_max;
			player_two->player_state = dizzy;
		}
	}
	else if (player_two->player_state == dizzy && player_one->player_state == dragon) {
		if (player_one->fire_counter == 11) {
			player_two->player_state = dead;
			cout << "p2 dizzy vs p1 dragon\n";
		}
		
	}
}