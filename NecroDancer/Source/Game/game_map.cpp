#pragma once

#include "stdafx.h"
#include "../Library/gameutil.h"
#include "../Library/audio.h"
//#include "../Library/gamecore.h"
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

	player = new main_character(3,1);
	player->set_map_position(start_x, start_y);
	player->set_camera_position(7, 4);

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
	try
	{
		return &blocks[y][x];
	}
	catch (const std::exception&)
	{
		return nullptr;
	}
}
