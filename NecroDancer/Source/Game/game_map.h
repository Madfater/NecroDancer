#pragma once
#include "../Library/gameutil.h"
#include "img_path.h"
#include "monster.h"
#include "player.h"
#include <string>
#include <vector>

typedef struct 
{
	int type;
}block;

class game_map
{
	private:
		vector<vector<block>> blocks;
		int start_x;
		int start_y;
		int map_width;
		int map_height;
		vector<Monster *> monsters;
	public:
		Player* player;
		void init();
		vector<Monster *> get_chr();
		void pop_monster(int);
		bool is_out_of_range(int x, int y);
		int get_block_info(int x, int y);
};