#include "stdafx.h"
#include "game_map.h"

void game_map::init()
{
	start_x = 2;
	start_y = 2;
	map_height = 10;
	map_width = 10;

	player = new Player(start_x,start_y);

	monsters.push_back(new bat);
	monsters[0]->set_position(1, 1, player->get_x(), player->get_y());

	monsters.push_back(new slime);
	monsters[1]->set_position(3, 1, player->get_x(), player->get_y());


	for (int y = 0; y < 10; y++)
	{
		blocks.push_back(vector<block>());
		for (int x = 0; x < 10; x++)
		{
			if(y==0 || x==0 || y==9 || x==9)
				blocks[y].push_back({ _wall });
			else
				blocks[y].push_back({ _floor });
		}
	}
}

vector<Monster*> game_map::get_chr()
{
	return monsters;
}

void game_map::pop_monster(int n)
{
	monsters.erase(monsters.begin() + n);
}

bool game_map::is_out_of_range(int x, int y)
{
	if (y >= map_height || y < 0 || x >= map_width || x < 0)
		return true;

	return false;
}

int game_map::get_block_info(int x,int y)
{
	if (player->get_x() == x && player->get_y() == y)
		return _player;

	for (int i = 0; i < monsters.size(); i++)
		if (monsters[i]->get_x() == x && monsters[i]->get_y() == y)
			return -1*(i+1);

	return blocks[x][y].type;
}
