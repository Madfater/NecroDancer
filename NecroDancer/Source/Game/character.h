#pragma once

#include "../Library/gameutil.h"

class character
{
	public:
		character::character(int, int, int, vector<string>, COLORREF);
		int get_x();
		int get_y();
		void show();
		virtual bool move() = 0;
		virtual ~character() = default;
	protected:
		int HP;
		int x;
		int y;
		game_framework::CMovingBitmap img;
};

class main_character : public character
{
	public:
		main_character(int HP, int x, int y, vector<string> files, COLORREF color) : character(HP, x, y, files,color) {};
		bool move();
	private:
		bool is_falling = false;
};
