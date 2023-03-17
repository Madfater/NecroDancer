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
	player = new main_character(3, 7, 4,true, img_player, RGB(0, 0, 0));
	//dragon = new main_character(3, 4, 2, img_dragon, RGB(0, 0, 0));
	//bat = new main_character(3, 9, 4, img_bat, RGB(0, 0, 0));
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 15; x++)
		{
			camera[y][x].LoadBitmapByString({ img_floor,img_wall,img_wall_half });
			camera[y][x].SetTopLeft(x * 60, y * 60);

			switch (_map[y][x])
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
	//dragon->show();
	//bat->show();
	if (is_moving)
	{
		is_moving = player->move();
	}
}

void camera::keydown(UINT key)
{
	switch (key) {
	case 37:
		is_moving = true;
		player->set_faceright(false);
		break;
	case 38:
		is_moving = true;
		break;
	case 39:
		is_moving = true;
		player->set_faceright(true);
		break;
	case 40:
		is_moving = true;
		break;
	}
}
