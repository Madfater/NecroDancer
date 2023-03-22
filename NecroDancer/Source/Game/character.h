#pragma once

#include "../Library/gameutil.h"

class character
{
	public:
		character::character(int, int, int,vector<vector<string>>, COLORREF);
		int get_x();
		int get_y();
		bool get_faceright();
		void show();
		void set_faceright(bool _is_faceright);
		virtual bool move() = 0;
		virtual ~character() = default;
	protected:
		int HP;
		int x;
		int y;
		bool is_faceright;
		game_framework::CMovingBitmap img_left;
		game_framework::CMovingBitmap img_right;
		vector<game_framework::CMovingBitmap> img = { img_left ,img_right };

};

class main_character : public character
{
	public:
		main_character(int HP, int x, int y, vector<vector<string>> files,  COLORREF color) : character(HP, x, y, files,color) {};
		bool move();
	private:
		bool is_falling = false;
};
