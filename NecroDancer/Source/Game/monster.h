#pragma once
#ifndef CLASS_monster_H
#define CLASS_monster_H
#include "../Library/gameutil.h"
#include "img_path.h"
#include "game_map.h"
#include <random>
#include <cmath>

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
		Monster::Monster(int,int, vector<vector<string>>);
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

		
		virtual void set_position(int, int, game_map*);
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
		bat() : Monster(2, 1, img_monsters[0]) { };
		int move(game_map*) override;
};

class slime :public Monster
{
	private:
		int step_cnt = 0;
	public:
		slime() : Monster(1, 1, img_monsters[1]) { };
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
		minotaur() :Monster(5, 1, img_minotaur) 
		{
			for (int i = 0; i < 2; i++)
			{
				img_stunned.push_back(game_framework::CMovingBitmap{});
				img_attacking.push_back(game_framework::CMovingBitmap{});
				img_stunned[i].LoadBitmapByString(img_minotaur_stunned[i], RGB(0, 0, 0));
				img_attacking[i].LoadBitmapByString(img_minotaur_attack[i], RGB(0, 0, 0));
				img_stunned[i].SetAnimation(100, false);
			}
		};
		void set_position(int, int, game_map*) override;
		void show() override;
		int move(game_map*) override;
		void move_animation() override;
};

class pawn :public Monster
{
	private:
		int step_cnt = 0;
		bool is_queen = false;
		bool is_attacking = false;
		game_framework::CMovingBitmap img_attacking;
	public:
		pawn() : Monster(1, 1, img_pawn) 
		{
			std::random_device rd;
			std::mt19937 rng(rd());
			std::uniform_int_distribution<int> distInt(0, 6);
			step_cnt = distInt(rng);

			img_attacking.LoadBitmapByString(img_pawn_attack, RGB(0, 0, 0));
		};
		int move(game_map*) override;
		void show() override;
		void set_position(int, int, game_map*) override;
};

class knight :public Monster
{
	private:
		int step_cnt = 0;
		bool is_attacking = false;
		game_framework::CMovingBitmap img_attacking;
	public:
		knight() : Monster(1, 1, img_knight) 
		{
			img_attacking.LoadBitmapByString(img_knight_attack, RGB(0, 0, 0));
		};
		int move(game_map*) override;
		void show() override;
		void set_position(int, int, game_map*) override;
};

class rook :public Monster
{
	private:
		int step_cnt = 0;
		bool is_attacking = false;
		game_framework::CMovingBitmap img_attacking;
	public:
		rook() : Monster(1, 1, img_rook) 
		{
			img_attacking.LoadBitmapByString(img_rook_attack, RGB(0, 0, 0));
		};
		int move(game_map*) override;
		void show() override;
		void set_position(int, int, game_map*) override;
};

class bishop :public Monster
{
	private:
		int step_cnt = 0;
		bool is_attacking = false;
		game_framework::CMovingBitmap img_attacking;
	public:
		bishop() : Monster(1, 1, img_bishop) 
		{
			img_attacking.LoadBitmapByString(img_bishop_attack, RGB(0, 0, 0));
		};
		int move(game_map*) override;
		void show() override;
		void set_position(int, int, game_map*) override;
};

class queen :public Monster
{
	private:
		int step_cnt = 0;
	public:
		queen() : Monster(1, 1, img_queen) { };
		int move(game_map*) override;
		void set_position(int, int, game_map*) override;
};

class king :public Monster
{
	private:
		int step_cnt = 0;
	public:
		king() : Monster(3, 2, img_king) { };
		int move(game_map*) override;
		void set_position(int, int, game_map*) override;
};
#endif