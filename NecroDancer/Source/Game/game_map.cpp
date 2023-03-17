#pragma once

#include "stdafx.h"
#include "../Library/gameutil.h"
#include "img_path.h"
#include <string>

#include "game_map.h"

#define _wall 1
#define _floor 0

void camera::init()
{
	if (position_x == -1 || position_y == -1)
	{
		position_x = g.get_start_position()[0];
		position_y = g.get_start_position()[1];
	}
	player = new main_character(3, 7, 4, img_player,RGB(0,0,0));
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 15; x++)
		{
			camera[y][x].LoadBitmapByString({ img_floor,img_wall,img_wall_half });
			camera[y][x].SetTopLeft(x * 60, y * 60);
			if (position_x - 7 + x < 0 || position_y - 4 + y < 0)
				continue;

			switch (g.get_block_info(position_x - 7 + x, position_y - 4 + y))
			{
				case _wall:
					if (y == 0)
						camera[y][x].SetFrameIndexOfBitmap(2);
					else
					{
						camera[y][x].SetFrameIndexOfBitmap(1);
						camera[y][x].SetTopLeft(x * 60, (y * 60) - 38);
					}
					break;
				case _floor:
					camera[y][x].SetFrameIndexOfBitmap(0);
					break;
				default:
					break;
			}
		}
	}
}
void camera::show()
{
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 15; x++)
		{
			camera[y][x].ShowBitmap();
			
			if(x==player->get_x() && y==player->get_y())
				player->show();
		}
	}

	if (is_moving)
		is_moving = player->move();
}

void camera::keydown(string key)
{
	is_moving = true;
	if (key == "right")
	{
		if (g.get_block_info(position_x + 1, position_y) == _wall)
			is_moving = false;
		else
		{
			player->move();
			position_x++;
			init();
		}		
	}
	else if (key == "left")
	{
		if (g.get_block_info(position_x - 1, position_y) == _wall)
			is_moving = false;
		else
		{
			player->move();
			position_x--;
			init();
		}
	}
	else if (key == "up")
	{
		if (g.get_block_info(position_x, position_y - 1) == _wall)
			is_moving = false;
		else
		{
			player->move();
			position_y--;
			init();
		}
	}
	else if (key == "down")
	{
		if (g.get_block_info(position_x, position_y + 1) == _wall)
			is_moving = false;
		else
		{
			player->move();
			position_y++;
			init();
		}
	}
}

int* game_map::get_start_position()
{
	int *rst = start;
	return rst;
}

int game_map::get_block_info(int x,int y)
{
	return _map[y][x];
}
