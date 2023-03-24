#pragma once

#include "../Library/gameutil.h"
#include "character.h"
#include "img_path.h"
#include <string>
#include <vector>

class camera
{
	public:
		void init();
		void show();
		void keydown(UINT key);
	private:
		game_map _map;
		game_framework::CMovingBitmap camera[9][15];
		character* player;
		int camera_x = -1;
		int camera_y = -1;
		bool is_moving = false;
};