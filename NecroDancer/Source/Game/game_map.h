#pragma once

#include "../Library/gameutil.h"
#include "character.h"
#include "img_path.h"
#include <string>
#include <vector>


class game_map
{
	private:
		int _map[10][20] = {
							{1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1},
							{1,0,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1},
							{1,0,0,0,1,1,1,1,1,1,1,0,0,0,1,0,0,1,1,1},
							{1,0,0,0,0,0,0,0,0,1,1,1,0,0,1,0,0,1,1,1},
							{1,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1},
							{1,1,1,1,1,1,1,0,0,0,1,1,0,0,0,0,0,1,1,1},
							{1,1,1,1,1,1,1,0,0,0,1,1,0,0,1,1,1,1,1,1},
							{1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1},
							{1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1},
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
						  };
		int start[2] = {1,1};
	public:
		int* get_start_position();
		int get_block_info(int x, int y);


};

class camera
{
	public:
		void init();
		void show();
		void keydown(string key);
	private:
		game_map g;
		game_framework::CMovingBitmap camera[9][15];
		character* player;
		vector<character*> monster;
		int position_x=-1;
		int position_y=-1;
		bool is_moving=false;
};

/*
struct block
{
	character* monster;
	bool has_torch;//預定
	bool has_trap;//預定
	bool has_item;//預定
	bool has_chest;
	int brightness;
	int type;
};
*/
