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


//Sound efect generator
void Hit_Sounds(int collision,player_t *player) {

	al_set_sample_instance_playmode(male_hit_sfx_inst, ALLEGRO_PLAYMODE_ONCE);
	al_attach_sample_instance_to_mixer(male_hit_sfx_inst, al_get_default_mixer());

	al_set_sample_instance_playmode(kick_sfx_inst, ALLEGRO_PLAYMODE_ONCE);
	al_attach_sample_instance_to_mixer(kick_sfx_inst, al_get_default_mixer());

	al_set_sample_instance_playmode(punch_sfx_inst, ALLEGRO_PLAYMODE_ONCE);
	al_attach_sample_instance_to_mixer(punch_sfx_inst, al_get_default_mixer());

	al_set_sample_instance_playmode(skeleton_sfx_inst, ALLEGRO_PLAYMODE_ONCE);
	al_attach_sample_instance_to_mixer(skeleton_sfx_inst, al_get_default_mixer());

	al_set_sample_instance_playmode(get_over_here_sfx_inst, ALLEGRO_PLAYMODE_ONCE);
	al_attach_sample_instance_to_mixer(get_over_here_sfx_inst, al_get_default_mixer());


	if (player->player_state == high_kick || player->player_state == low_kick) {
		if (player->high_kick_counter == 5 || player->low_kick_counter == 5) {
			al_play_sample_instance(male_hit_sfx_inst);

			if (collision) {
				al_play_sample_instance(kick_sfx_inst);
			}
		}

	}
	else if (player->player_state == low_punch || player->player_state == high_punch) {
		if (player->high_punch_counter == 5 || player->low_punch_counter == 4) {
			al_play_sample_instance(male_hit_sfx_inst);
			if (collision) {
				al_play_sample_instance(punch_sfx_inst);
			}
		}
	}
	else if (player->player_state == dragon && player->skeleton->player_state == dead) {
			if (collision&&player->fire_counter<=4) {
				al_play_sample_instance(skeleton_sfx_inst);
		}
	}
	else if (player->player_state == spear && player->throw_spear_counter==5) {
			al_play_sample_instance(get_over_here_sfx_inst);
	}
}