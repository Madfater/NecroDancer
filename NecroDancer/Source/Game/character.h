#pragma once

#include "../Library/gameutil.h"

class  character
{
	public:
		character::character(int, int, int, vector<string>, COLORREF = CLR_INVALID);
		int get_x();
		int get_y();
		void show();
		virtual ~character();
	protected:
		int HP;
		int x;
		int y;
		game_framework::CMovingBitmap img;
};

class main_character : character
{
	public:
		main_character(int HP, int x, int y, vector<string> files, COLORREF color) : character(HP, x, y, files,color) {};
		void move();
	private:
		bool is_jumping = 0;
		bool is_falling = 0;
};
