#pragma once
#include "../Library/gameutil.h"
#include "img_path.h"
#include "character.h"
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
		vector<character *> characters;
	public:
		Player* player;
		void init();
		int get_start_x();
		int get_start_y();
		
		vector<character *> get_chr();
		void pop_monster(int);
		bool is_out_of_range(int x, int y);
		int get_block_info(int x, int y);
};