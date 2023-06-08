#pragma once
#ifndef CLASSmap_H
#define CLASSmap_H
#include "../Library/gameutil.h"
#include "img_path.h"
#include "monster.h"
#include "player.h"
#include "item.h"
#include <string>
#include <vector>
#include <fstream>

class Monster;
class Player;
class Item;

typedef struct 
{
	int type;
}block;

class game_map
{
	private:
		vector<vector<block>> blocks;
		vector<Monster*> monsters;
		vector<Item*> Items;

		int start_x;
		int start_y;
		int map_width;
		int map_height;

	public:
		void init();
		Player* player;
		vector<Monster *> get_chr();
		void pop_monster(int);
		bool is_out_of_range(int x, int y);
		int get_block_info(int x, int y);
		void block_change(int x, int y, int type);
};
#endif
