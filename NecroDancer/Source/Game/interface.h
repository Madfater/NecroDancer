#pragma once


#include "../Library/gameutil.h"

class _interface
{
public:
	int lifepoint;
	int full;
	int half;
	int empty;
	vector<game_framework::CMovingBitmap> hearts;
	game_framework::CMovingBitmap heart_half;
	//game_framework::CMovingBitmap heart_half;
	game_framework::CMovingBitmap money;
	void init();
	void show();

};