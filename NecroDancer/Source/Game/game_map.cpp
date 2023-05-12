#include "stdafx.h"
#include "game_map.h"

void game_map::init()
{
	start_x = 2;
	start_y = 2;
	map_height = 10;
	map_width = 10;

	player = new Player(start_x,start_y);

	characters.push_back(new bat);
	characters[0]->set_map_position(1, 1);

	characters.push_back(new slime);
	characters[1]->set_map_position(3, 1);


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

vector<character*> game_map::get_chr()
{
	return characters;
}

void game_map::pop_monster(int n)
{
	characters.erase(characters.begin() + n);
}

bool game_map::is_out_of_range(int x, int y)
{
	if (y >= map_height || y < 0 || x >= map_width || x < 0)
		return true;

	return false;
}

int game_map::get_block_info(int x,int y)
{
	if (player->get_map_x() == x && player->get_map_y() == y)
		return _player;

	for (int i = 0; i < characters.size(); i++)
		if (characters[i]->get_map_x() == x && characters[i]->get_map_y() == y)
			return -1*(i+1);

	return blocks[x][y].type;
}
