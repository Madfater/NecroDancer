#pragma once
#ifndef CLASSplayer_H
#define CLASSplayer_H
#include "../Library/gameutil.h"
#include "img_path.h"
#include "monster.h"

class Monster;

class Player
{
	private:
		vector<game_framework::CMovingBitmap> img;
		vector<vector<game_framework::CMovingBitmap>> shovel_img;
		vector<vector<game_framework::CMovingBitmap>> _atk_img;
		vector<game_framework::CMovingBitmap> atk_img;
		game_framework::CMovingBitmap being_atk_img;

		bool is_faceright = false;
		bool is_falling = false;
		bool is_moving = false;
		bool is_attacking = false;
		bool be_attacking = false;
		bool is_digging = false;
		int _direction = 0;
		int attack_counter = 0;
		int be_attack_counter = 0;
		int dig_counter = 0;

		int HP;
		int weapon_id = 2;
		int shovel_id = 0;
		int x;
		int y;

	public:

		Player::Player(int,int);
		virtual ~Player() = default;

		int get_is_moving();
		int get_is_attacking();
		int get_be_attacking();
		int get_is_digging();
		int get_hp();
		int get_weapon_id();
		int get_shovel_id();
		int get_x();
		int get_y();

		void set_moving();
		void set_position(int, int);
		void set_faceright(bool);
		void set_weapon_id(int);
		void dig(int);

		void attack(Monster*,int);
		void move_animation();
		void dig_animation();
		void attack_animation();
		void be_attack_animation();
		void lose_HP(int);
		void show();
};
#endif