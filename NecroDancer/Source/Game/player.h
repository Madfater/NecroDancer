#pragma once
#include "../Library/gameutil.h"
#include "img_path.h"
#include "monster.h"

class Player
{
	private:
		vector<game_framework::CMovingBitmap> img;
		game_framework::CMovingBitmap atk_img;

		bool is_faceright = false;
		bool is_falling = false;
		bool is_moving = false;
		bool is_attacking = false;
		int attack_direction = 0;
		int attack_counter = 0;

		int HP;
		int weapon_id;
		int x;
		int y;
		
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
		int get_weapon_id();
		int get_x();
		int get_y();

		void set_moving();
		void set_position(int, int);
		void set_faceright(bool);

		void attack(Monster*,int);
		void move_animation();
		void attack_animation();
		void lose_HP(int);
		void show();
};