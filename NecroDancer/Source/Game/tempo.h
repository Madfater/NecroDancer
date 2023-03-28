#pragma once


#include "../Library/gameutil.h"

class tempo
{
	public:
		vector<game_framework::CMovingBitmap> beats_left;
		vector<game_framework::CMovingBitmap> beats_right;
		game_framework::CMovingBitmap heart;
		bool _is_touched = true;
		bool _is_jumped = false;
		bool is_touched();
		void init();
		void beatspawn();
		void show();

};