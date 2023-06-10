#pragma once

#include "../Library/gameutil.h"
#include "monster.h"
#include "game_map.h"
#include "img_path.h"
#include <string>
#include <vector>

class camera
{
	private:
		game_map* _map;
		vector<vector<int>> camera_blocks;
		game_framework::CMovingBitmap camera_blocks_img[9][15];
		void updateVisibility();
	public:
		void init(game_map*);
		void show();
};