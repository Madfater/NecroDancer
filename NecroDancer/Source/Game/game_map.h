#pragma once

#include "../Library/gameutil.h"
#include "character.h"
#include "img_path.h"
#include <string>


class camera
{
	public:
		void init();
		void show();
		void keydown(string key);
	private:
		game_framework::CMovingBitmap camera[9][15];
		int _map[9][15] = {
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,1,1,1,0,0,0,0,0,1},
							{1,0,0,0,0,0,1,0,1,0,0,0,0,0,1},
							{1,0,0,0,0,0,1,1,1,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
						 };
		character* player;
		character* bat;
		character* dragon;
		bool is_moving=false;
};