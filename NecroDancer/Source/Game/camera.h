#pragma once

#include "../Library/gameutil.h"
#include "character.h"
#include "game_map.h"
#include "img_path.h"
#include <string>
#include <vector>

class camera
{
	private:
		game_map* _map;
		game_framework::CMovingBitmap camera_blocks[9][15];
	public:
		void init(game_map*);
		void show();
};