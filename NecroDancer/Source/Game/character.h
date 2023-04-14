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
		int camera_x;
		int camera_y;
		bool is_faceright;
		bool is_falling = false;
		bool is_moving = false;
		int move_step = 0;
		vector<int> move_direction;
		vector<game_framework::CMovingBitmap> img;
	public:
		character::character(int,int, vector<vector<string>>, COLORREF);
		virtual ~character() = default;

		int get_map_x();
		int get_map_y();
		int get_camera_x();
		int get_camera_y();
		bool get_is_moving();
		bool get_faceright();
		virtual int get_move_direction();

		void set_moving();
		virtual void set_camera_position(int,int);
		void set_map_position(int, int);
		void set_faceright(bool);

		virtual void attack(character*) ;
		virtual void move_animation();
		void move_step_increase();
		void lose_HP(int);
		void show();
};

class main_character : public character
{
	public:
		main_character(int HP, int damage) : character(HP, damage, img_player, RGB(0, 0, 0)) {};
};

class bat :public character
{
	public:
		bat() : character(1, 1, img_monsters[0], RGB(0, 0, 0)) { move_direction = { 4,4,0,4,4,2 }; };
};

class slime :public character
{
	public:
		slime() : character(1, 1, img_monsters[1], RGB(0, 0, 0)) { move_direction = { 4,4, 1,4,4,3}; };
};

class dragon :public character
{
	public:
		dragon() : character(2, 3, img_monsters[2], RGB(0, 0, 0)) {};
		void set_camera_position(int, int) override;
		void move_animation() override;
		int get_move_direction() override;
};