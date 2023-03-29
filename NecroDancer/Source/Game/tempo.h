#pragma once


#include "../Library/gameutil.h"

class tempo
{
	public:
		vector<game_framework::CMovingBitmap> beats_left;
		vector<game_framework::CMovingBitmap> beats_right;
		game_framework::CMovingBitmap heart;
		bool _has_moved = false; //only jump once this determine if player has jumped
		bool if_shouldjump();
		void init();
		void beatspawn();
		void show();

};