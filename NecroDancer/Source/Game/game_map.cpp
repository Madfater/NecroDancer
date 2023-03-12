#pragma once

#include "stdafx.h"
#include "../Library/gameutil.h"
#include "img_path.h"

#include "game_map.h"

#define _wall 1
#define _floor 0
#define player_x 7
#define player_y 4

void camera::init()
{
	player = main_character(3, player_x*60, player_y*60-30, img_player,RGB(0,0,0));
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 15; x++)
		{
			view[y][x].LoadBitmapByString({ img_floor,img_wall,img_wall_half });
			view[y][x].SetTopLeft(x * 60, y * 60);

			switch (_map[y][x])
			{
			case _wall:
				if (y == 0)
					view[y][x].SetFrameIndexOfBitmap(2);
				else
				{
					view[y][x].SetFrameIndexOfBitmap(1);
					view[y][x].SetTopLeft(x * 60, (y * 60) - 38);
				}
				break;
			case _floor:
				view[y][x].SetFrameIndexOfBitmap(0);
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
			view[y][x].ShowBitmap();
			
			if(x==player_x && y==player_y)
				player.show();
		}
	}
}
