#pragma once

#include "../Library/gameutil.h"

class  character
{
	public:
		character::character() = default;
		character::character(int, int, int, vector<string>);
		character::character(int, int, int, vector<string>, COLORREF);
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

class main_character : public character
{
	public:
		main_character(int HP, int x, int y, vector<string> files) : character(HP, x, y, files) {};
		main_character(int HP, int x, int y, vector<string> files, COLORREF color) : character(HP, x, y, files,color) {};
		void move();
	private:
		bool is_falling = false;
};
