#pragma once
#include "../Library/gameutil.h"
#include "img_path.h"

class character
{
	protected:
		int HP;
		int damage;
		int map_x;
		int map_y;
		bool is_faceright;
		int move_step = 0;
		vector<int> move_direction;
		vector<game_framework::CMovingBitmap> img;
	public:
		character::character(int,int, vector<vector<string>>, COLORREF);
		virtual ~character() = default;
		int get_map_x();
		int get_map_y();
		int get_hp();
		int get_damage();;
		bool get_faceright();
		virtual int get_move_direction();

		virtual void set_show_position(int,int);
		void set_map_position(int, int);
		void set_faceright(bool);

		void move_step_increase();
		void lose_HP(int);
		void show();
};

class bat :public character
{
	public:
		bat() : character(5, 1, img_monsters[0], RGB(0, 0, 0)) { move_direction = { 0,0,1,1,2,2,3,3 }; };
};

class slime :public character
{
	public:
		slime() : character(5, 1, img_monsters[1], RGB(0, 0, 0)) { move_direction = { 0,0,1,1,2,2,3,3}; };
};