#pragma once

#include "../Library/gameutil.h"
#include "character.h"
#include "img_path.h"


class camera
{
	public:
		void init();
		void show();
	private:
		game_framework::CMovingBitmap view[9][15];
		int _map[9][15] = {
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,1,1,1,0,0,0,0,0,1},
							{1,0,0,0,0,0,1,0,1,0,0,0,0,0,1},
							{1,0,0,0,0,0,1,0,1,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
						 };
		character player;
};