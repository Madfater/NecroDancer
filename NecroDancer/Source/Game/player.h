#pragma once
#include "../Library/gameutil.h"
#include "img_path.h"
#include "character.h"

class Player
{
	private:
		int HP;
		int weapon_id;
		int map_x;
		int map_y;
		int attack_direction = 0;
		int attack_counter = 0;
		bool is_faceright = false;
		bool is_falling = false;
		bool is_moving = false;
		bool is_attacking = false;
		vector<game_framework::CMovingBitmap> img;
		vector<game_framework::CMovingBitmap> atk_img; 

	public:
		Player::Player(int,int);
		virtual ~Player() = default;
		int get_is_moving();
		int get_is_attacking();
		int get_map_x();
		int get_map_y();
		int get_hp();

		void set_moving();
		void set_map_position(int, int);
		void set_faceright(bool);

		void attack(character*, int);
		void move_animation();
		void attack_animation();
		void lose_HP(int);
		void show();
};