#pragma once
#ifndef CLASS_monster_H
#define CLASS_monster_H

#include "../Library/gameutil.h"
#include <cmath>
#include "img_path.h"
#include "game_map.h"


class game_map;

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

		
		virtual void set_position(int, int, int, int);
		void set_faceright(bool);
		void set_is_moving();

		virtual int move(game_map*) = 0;
		virtual void move_animation();
		void lose_HP(int);
		virtual void show();
		void show_hp();
};

class bat :public Monster
{
	private:
		int step_cnt = 0;
	public:
		bat() : Monster(2, 1, img_monsters[0], RGB(0, 0, 0)) { };
		int move(game_map*) override;
};

class slime :public Monster
{
	private:
		int step_cnt = 0;
	public:
		slime() : Monster(1, 1, img_monsters[1], RGB(0, 0, 0)) { };
		int move(game_map*) override;
};

class minotaur :public Monster
{
	private:
		int Status = normal;
		int cnt_stun = 0;
		int direction = 0;
		vector<game_framework::CMovingBitmap> img_stunned;
		vector<game_framework::CMovingBitmap> img_attacking;
	public:
		minotaur() :Monster(5, 1, img_minotaur[0], RGB(0, 0, 0)) {
			
			for (int i = 0; i < 2; i++)
			{
				img_stunned.push_back(game_framework::CMovingBitmap{});
				img_attacking.push_back(game_framework::CMovingBitmap{});
				img_stunned[i].LoadBitmapByString(img_minotaur[2][i], RGB(0, 0, 0));
				img_attacking[i].LoadBitmapByString(img_minotaur[1][i], RGB(0, 0, 0));
				img_stunned[i].SetAnimation(100, false);
			}
		};
		void set_position(int, int, int, int) override;
		void show() override;
		int move(game_map*) override;
		void move_animation() override;
};
#endif