#pragma once

#include "../Library/gameutil.h"


class character
{
	protected:
		int HP;
		int map_x;
		int map_y;
		int x, y;
		int move_position = -1;
		bool is_faceright;
		bool is_falling = false;
		bool is_moving = false;
		game_framework::CMovingBitmap img_left;
		game_framework::CMovingBitmap img_right;
		vector<game_framework::CMovingBitmap> img = { img_left ,img_right };
	public:
		character(int _HP, int _x, int _y, vector<vector<string>> files, COLORREF color);
		character(int, vector<vector<string>>, COLORREF);
		virtual ~character() = default;
		virtual void move() = 0;
		int get_x();
		int get_y();
		bool get_is_moving();
		bool get_faceright();
		void set_move_position(int);
		void set_position_camera(int, int);
		void set_position_map(int, int);
		void set_faceright(bool);
		void moving();
		void show();

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
