#pragma once

#include "../Library/gameutil.h"


class character
{
	protected:
		int HP;
		int x;
		int y;
		bool is_faceright;
		bool is_falling = false;
		bool is_moving = false;
		game_framework::CMovingBitmap img_left;
		game_framework::CMovingBitmap img_right;
		vector<game_framework::CMovingBitmap> img = { img_left ,img_right };
	public:
		character::character(int, vector<vector<string>>, COLORREF);
		int get_x();
		int get_y();
		void set_is_moving();
		bool get_is_moving();
		bool get_faceright();
		void show();
		void set_position_camera(int, int);
		void set_position_map(int, int);
		void set_faceright(bool);
		virtual void move() = 0;
		virtual ~character() = default;

};

class main_character : public character
{
	public:
		main_character(int HP, vector<vector<string>> files,  COLORREF color) : character(HP, files,color) {};
		void move();
};

class monster :public character
{
	public:
		monster(int HP, vector<vector<string>> files, COLORREF color) : character(HP, files, color) {};
		void move();
};
