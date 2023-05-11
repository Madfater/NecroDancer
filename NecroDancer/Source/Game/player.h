#pragma once
#include "../Library/gameutil.h"
#include "img_path.h"
#include "monster.h"

class Player
{
	private:
		vector<game_framework::CMovingBitmap> img;

		bool is_faceright = false;
		bool is_falling = false;
		bool is_moving = false;

		int HP;
		int weapon_id;
		int x;
		int y;

	public:

		Player::Player(int,int);
		virtual ~Player() = default;

		int get_is_moving();
		int get_hp();
		int get_weapon_id();
		int get_x();
		int get_y();

		void set_moving();
		void set_position(int, int);
		void set_faceright(bool);

		void attack(Monster*);
		void move_animation();
		void lose_HP(int);
		void show();
};