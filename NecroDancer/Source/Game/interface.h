#pragma once

#include "../Library/gameutil.h"

class _interface
{
public:
	int lifepoint;
	int full;
	int half;
	int empty;
	int weapon_id = 0;
	vector<game_framework::CMovingBitmap> hearts;
	vector<game_framework::CMovingBitmap> weapon_icon;
	game_framework::CMovingBitmap slot_shovel;
	game_framework::CMovingBitmap slot_attack;
	game_framework::CMovingBitmap shovel_icon;
	game_framework::CMovingBitmap heart_half;
	//game_framework::CMovingBitmap heart_half;
	game_framework::CMovingBitmap money;
	void set_weapon_id(int);
	void init();
	void load_hp(int);
	void show();

};