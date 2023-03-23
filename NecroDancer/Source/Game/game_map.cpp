#pragma once

#include "stdafx.h"
#include "../Library/gameutil.h"
#include "img_path.h"
#include <string>
#include <vector>
#include "game_map.h"

#define _wall 1
#define _floor 0

void game_map::init()
{
	start_x = 2;
	start_y = 2;
	map_height = 10;
	map_width = 10;

	characters.push_back(new main_character{ 3,img_player,RGB(0,0,0) });//player
	characters[0]->set_position_map(start_x, start_y);
	characters[0]->set_position_camera(7, 4);
	
	characters.push_back(new monster{ 3,img_monsters[0],RGB(0,0,0) });
	characters[1]->set_position_map(1, 1);

	characters.push_back(new monster{ 3,img_monsters[1],RGB(0,0,0) });
	characters[2]->set_position_map(3, 1);

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

int game_map::get_start_x()
{
	return start_x;
}

int game_map::get_start_y()
{
	return start_y;
}

bool game_map::is_out_of_range(int x, int y)
{
	if (y >= map_height || y < 0 || x >= map_width || x < 0)
		return true;

	return false;
}

block* game_map::get_block_info(int x,int y)
{
	return &blocks[y][x];
}
