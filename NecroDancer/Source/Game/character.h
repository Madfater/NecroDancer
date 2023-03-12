#pragma once

#include "../Library/gameutil.h"

class  character
{
	public:
		character(int HP,int x,int y, game_framework::CMovingBitmap img);
		int get_x();
		int get_y();
		void show();
		virtual ~character();
	private:
		int HP;
		int x;
		int y;
		game_framework::CMovingBitmap img;
};

class main_character : character
{
	public:
		main_character(int HP, int x, int y, game_framework::CMovingBitmap img) : character(HP, x, y, img) {};
		void move();
	private:
		int jump = 0;
		int isfalling = 0;


};
