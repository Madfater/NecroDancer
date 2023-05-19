#pragma once
#include "../Library/gameutil.h"
#include <cmath>
#include "img_path.h"

class Monster
{
	protected:
		vector<game_framework::CMovingBitmap> img;
		vector<game_framework::CMovingBitmap> hearts;

		bool is_faceright;
		bool is_falling;
		bool is_moving;
		bool is_damaged = false;

		int HP;
		int full_HP;
		int damage;
		int x;
		int y;

		int camera_x;
		int camera_y;

	public:
		Monster::Monster(int,int, vector<vector<string>>, COLORREF);
		virtual ~Monster() = default;

		bool get_faceright();
		bool get_is_moving();
		bool get_is_damaged();

		int get_hp();
		int get_damage();
		int get_x();
		int get_y();
		int get_camera_x();
		int get_camera_y();

		
		void set_position(int, int, int, int);
		void set_faceright(bool);
		void set_is_moving();

		virtual int move(int,int) = 0;
		void move_animation();
		void lose_HP(int);
		void show();
		void show_hp();
};

class bat :public Monster
{
	private:
		int step_cnt = 0;
	public:
		bat() : Monster(10, 1, img_monsters[0], RGB(0, 0, 0)) { };
		int move(int, int) override;
};

class slime :public Monster
{
	private:
		int step_cnt = 0;
	public:
		slime() : Monster(5, 1, img_monsters[1], RGB(0, 0, 0)) { };
		int move(int, int) override;
};

class minotaur :public Monster
{
	private:
		int is_stunned;
		bool is_rushing;
	public:
		minotaur() :Monster(5, 1, img_monsters[2], RGB(0, 0, 0)) {};
		int move(int, int) override;
};