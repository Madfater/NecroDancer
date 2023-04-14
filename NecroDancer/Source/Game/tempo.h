#pragma once


#include "../Library/gameutil.h"

class tempo
{
	private:
		bool _has_moved = false; //only jump once this determine if player has jumped

	public:
		vector<game_framework::CMovingBitmap> beats_left;
		vector<game_framework::CMovingBitmap> beats_right;
		game_framework::CMovingBitmap heart;
		bool if_shouldjump();
		bool if_afterjump();
		void init();
		void beatspawn();
		void show();

};